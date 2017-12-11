#include "enemy.h"
#include <stdlib.h>
#include <QGraphicsScene>
Enemy::Enemy()
{
    int randSpeed = 1 + (rand()%5);
    int randPos = rand()%700;

    this->setPixmap(QPixmap(":/Images/snake.gif"));
    velocity = new QVector2D(0, randSpeed);
    setTransformOriginPoint(this->pixmap().width()/2,
                            this->pixmap().height()/2);
    setPos(randPos+100, -200);

    timer =  new QTimer(this);
    connect(timer,
            SIGNAL(timeout()),
            this,
            SLOT(Move()));
    timer->start(1000/60);
    notificationList = new QList<Projectile*>();
    hp = 2;

}

Enemy::~Enemy()
{

}


void Enemy::Move()
{
    setPos(x()+velocity->x(), y()+velocity->y());
    if(y() > 900)
    {
        NotifyTargets();
        scene()->removeItem(this);
        delete this;
        return;
    }
}

void Enemy::TakeDamage(float damage)
{
    hp = hp-damage;
    if(hp<=0)
    {
        NotifyTargets();
        scene()->removeItem(this);
        delete this;
        return;
    }
}



void Enemy::AddNotificationTarget(Projectile* t)
{
    notificationList->append(t);
}
void Enemy::RemoveNotificationTarget(Projectile* t)
{
    int n = notificationList->indexOf(t);
    notificationList->removeAt(n);
}

void Enemy::NotifyTargets()
{
    int n = notificationList->length();
    for(int i=0; i<n; i++)
    {
        notificationList->at(i)->NoTarget();
    }
}












