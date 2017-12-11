#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Player();
    ~Player();
    void keyPressEvent( QKeyEvent *event );

signals:

public slots:
};

#endif // PLAYER_H
