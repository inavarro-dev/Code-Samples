#ifndef TILE_H
#define TILE_H

#include <QObject>
#include <QMouseEvent>
#include <QWidget>
#include <QGraphicsPixmapItem>


struct TileLocation
{
    int x;
    int y;

};

class Tile : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:

public:
    explicit Tile(QObject *parent = 0,int x =0,int y=0);
    bool isMine;
    QList <Tile *>nearbyTiles;
    TileLocation location;
    int minesAround;

    bool isClicked;
    bool isFlagged;
    bool isClickable;


    void findNearbyTiles(QList <Tile *>allTiles);
    void checkNearbyTiles();
    void revealEmptyTiles();
protected:
    //Override Mouse events
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

signals:



public slots:
};

#endif // TILE_H
