#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "enemy.h"
#include <QObject>
#include <QVector2D>
#include <QGraphicsPixmapItem>

class Enemy;

class Projectile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    Enemy * target;
    QVector2D * velocity;
    float speed;



public:
    Projectile();
    ~Projectile();
    void FindTarget();
    void NoTarget();
signals:

public slots:
    void Move();
};

#endif // PROJECTILE_H
