#ifndef ENEMY_H
#define ENEMY_H

#include "projectile.h"
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QVector2D>
#include <QTimer>
#include <QList>

class Projectile;

class Enemy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QVector2D * velocity;
    QTimer * timer;
    QList<Projectile*> * notificationList;
    float hp;
public:
    Enemy();
    ~Enemy();
    void TakeDamage(float damage);
    void AddNotificationTarget(Projectile* t);
    void RemoveNotificationTarget(Projectile* t);
    void NotifyTargets();
public slots:
    void Move();
};

#endif // ENEMY_H
