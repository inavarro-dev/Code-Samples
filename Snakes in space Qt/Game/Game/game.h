#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include "player.h"

class Game : public QObject
{
    Q_OBJECT
private:
   QGraphicsScene *scene;
   QGraphicsView *view;
   Player *player;
   QTimer *spawnTimer;
public:
    explicit Game(QObject *parent = 0);
    ~Game();

signals:

public slots:
   void spawnSnake();
};

#endif // GAME_H
