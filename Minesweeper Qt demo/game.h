#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "tile.h"


class Game : public QObject
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    //Tile *tile;

public:
    explicit Game(QObject *parent = 0);
    int difficulty;
    void buildGrid();
    QList <Tile *>allTiles;


signals:

public slots:
};

#endif // GAME_H
