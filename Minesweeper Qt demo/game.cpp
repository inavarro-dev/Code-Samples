#include "game.h"
#include <QDebug>
#include <stdlib.h>
#include <time.h>

Game::Game(QObject *parent) : QObject(parent)
{
    //Create Scene on heap
    scene = new QGraphicsScene(this);
    //Create View on heap and point to scene
    view = new QGraphicsView(scene);
    //shut off scroll bars
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //show scene and set size
    view->setWindowTitle("Minesweeper");
    view->show();
    view->setFixedSize(800, 600);
    view->setSceneRect(0, 0, 800, 600);
    //view->setBackgroundBrush(QBrush(QImage(":/Images/Minesweeper Tile Assets/background.jpg")));
    view->setBackgroundBrush(Qt::black);

    difficulty = 1;



    buildGrid();

    foreach(Tile *tile,allTiles)
    {

        tile->findNearbyTiles(allTiles);

        tile->checkNearbyTiles();
    }


}

void Game::buildGrid()
{
    srand(time(NULL));
    if(difficulty = 1)
    {
        int cols = 16;
        int rows =12;

        for(int i=0; i < cols; i++)
        {
            for(int j=0; j < rows; j++)
            {
                /*tile = new Tile(this,i,j);
                qDebug() << "Tile(" << i << "," << j << ") was Created";
                scene->addItem(tile);
                tile->setPos(i*100,j*100);*/
                Tile * tile = new Tile(this,i,j);
                qDebug() << "Tile(" << i << "," << j << ") was Created";
                scene->addItem(tile);
                tile->setPos(i*50,j*50);
                tile->setScale(.2);
                allTiles.append(tile);


                int randMine = (rand()%6);
                if(randMine == 1)
                {
                    tile->isMine = true;
                }


            }
        }
    }


}
