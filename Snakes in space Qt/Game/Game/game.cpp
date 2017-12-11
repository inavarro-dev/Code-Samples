#include "game.h"
#include "enemy.h"
#include <QBrush>
#include <QDebug>
Game::Game(QObject *parent) : QObject(parent)
{
    scene = new QGraphicsScene();
    player = new Player();
    scene->addItem(player);
    player->setFocus();
    player->grabKeyboard();



    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(800, 600);
    view->setSceneRect(0, 0, 800, 600);
    view->setBackgroundBrush(QBrush(QImage(":/Images/space.jpg")));

    float x = view->width()/2;
    float y = view->height() - player->pixmap().height();
    player->setPos(x, y);

    spawnTimer = new QTimer();
    connect(spawnTimer,
            SIGNAL(timeout()),
            this,
            SLOT(spawnSnake()));
    spawnTimer->start(500 * 1);


}

Game::~Game()
{

}


void Game::spawnSnake()
{
    Enemy * enemy = new Enemy();
    scene->addItem(enemy);
}
