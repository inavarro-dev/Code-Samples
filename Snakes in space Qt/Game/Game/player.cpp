#include "player.h"
#include <QPixmap>
#include <QDebug>
#include <QGraphicsScene>
#include "projectile.h"

Player::Player()
{
    this->setPixmap(QPixmap(":/Images/ship.png"));
    setTransformOriginPoint(this->pixmap().width()/2,
                            this->pixmap().height()/2);
}

Player::~Player()
{

}

void Player::keyPressEvent( QKeyEvent * event )
{
    qDebug() << "event";
    if(event->key() == Qt::Key_Up)
    {
        setPos( x() , y() - 10);
    }
    if(event->key() == Qt::Key_Down)
    {
        setPos( x() , y() + 10);
    }
    if(event->key() == Qt::Key_Left)
    {
        setPos( x() - 10 , y());
    }
    if(event->key() == Qt::Key_Right)
    {
        setPos( x() + 10, y());
    }
    if(event->key() == Qt::Key_Space)
    {
        Projectile *p1 = new Projectile();
        p1->setPos(x() + 30, y());
        scene()->addItem(p1);
        p1->FindTarget();

        Projectile *p2 = new Projectile();
        p2->setPos(x() + 83, y());
        scene()->addItem(p2);
        p2->FindTarget();
    }
}
