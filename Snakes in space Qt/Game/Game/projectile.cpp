#include "projectile.h"
#include "enemy.h"
#include "qmath.h"
#include <QPixmap>
#include <QTimer>
#include <QList>
#include <QGraphicsItem>
#include <QGraphicsScene>

Projectile::Projectile()
{
    this->setPixmap(QPixmap(":/Images/missile.png"));
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(Move()));
    timer->start(50);
    speed = 20;
    velocity = new QVector2D(0,-10);
    target = NULL;
    setTransformOriginPoint(this->pixmap().width()/2,
                            this->pixmap().height()/2);

}

Projectile::~Projectile()
{

}

void Projectile::FindTarget()
{
    target = NULL;
    int n = scene()->items().length();
    for(int i=0; i<n; i++)
    {
        if(typeid(* (scene()->items().at(i))) ==  typeid(Enemy))
        {
            target = (Enemy*) scene()->items().at(i);
            target->AddNotificationTarget(this);
            return;
        }
    }
}

void Projectile::Move()
{
    //--------- Movement -------------------------------------
    // Vector to target
    // d - s

    if(target != NULL)
    {
        QVector2D d(target->x(), target->y());
        QVector2D s(this->x(), this->y());
        QVector2D vectorToTarget = d-s;

        float r = qAtan2(vectorToTarget.y(), vectorToTarget.x());
        float euler = qRadiansToDegrees(r);

        setRotation(euler);

        QVector2D directionToTarget = vectorToTarget.normalized();
        velocity->setX(directionToTarget.x() * speed);
        velocity->setY(directionToTarget.y() * speed);
    }

    this->setPos(x() + velocity->x(), y() + velocity->y());

    if(y() < -200)
    {
        if(target!= NULL)
            target->RemoveNotificationTarget(this);
        scene()->removeItem(this);
        delete this;
        return;
    }

    //---------------- Collision ----------------------------
    QList<QGraphicsItem*> colliding_Items = collidingItems();
    int n = colliding_Items.length();
    for(int i=0; i<n; i++)
    {
        if(typeid(* (colliding_Items[i]) ) ==  typeid(Enemy))
        {
            if(target!= NULL)
                target->RemoveNotificationTarget(this);
            Enemy *e = (Enemy*)colliding_Items[i];
            e->TakeDamage(1);
            scene()->removeItem(this);
            delete this;
            return;
        }
    }

}

void Projectile::NoTarget()
{
    target = NULL;
}





