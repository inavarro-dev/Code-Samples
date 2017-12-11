#include "tile.h"
#include "game.h"
#include <QPixmap>
#include <QDebug>
#include <QGraphicsScene>
#include <QMessageBox>


Tile::Tile(QObject *parent, int x, int y) : QObject(parent)
{
    //creates location struct used for generating grid,
    //and for tiles to find and communicate with eachother
    this->location.x =x;
    this->location.y =y;

    //sets starting image for tiles
    this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Tile.png"));

    //sets up boolean values that are used to determine status of any tile
    //
    //isClicked describes whether or not a tile has been revealed
    //
    //isFlagged describes whether or not a tile has a flag on it
    //flagged tiles cannot be revealed until the flag is toggled off
    //
    //isClickable describes whether or not a tile can be revealed
    //once isClickable is set to false,the tile cannot be interacted
    //with and only shows information
    //
    this->isClicked = false;
    this->isFlagged = false;
    this->isClickable = true;
    this->isMine=false;

    //counts how many mines are around after checkNearbyTiles() runs
    minesAround = 0;


}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //determines what happens when mouse is single clicked
    if(isClickable == false)
    {
        qDebug() << "Tile(" << location.x << "," << location.y << ") is inactive 1";
    }
    if(isClickable == true && isFlagged == false)
    {
        isFlagged = true;
        qDebug() << "Tile(" << location.x << "," << location.y << ")  was Flagged!";
        update();
        QGraphicsItem::mousePressEvent(event);
        this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Flag.png"));
    }
    else if(isFlagged == true && isClickable == true)
    {
        isFlagged = false;
        qDebug() << "Tile(" << location.x << "," << location.y << ")  was Unflagged!";
        update();
        //QGraphicsItem::mousePressEvent(event);
        this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Tile.png"));
    }

}

void Tile::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{

    //Determines what happens when mouse is double clicked
    //If double clicked while unrevealed and with flag------------------------------------------------------------


    if(isClicked == false && isFlagged == true)
    {
        isClicked = true;
        isClickable = false;

        qDebug() << "Tile(" << location.x << "," << location.y << ") was Clicked!";
        //QGraphicsItem::mouseDoubleClickEvent(event);

        //choose what to do with clicked tile
        if(isMine == true)
        {
            this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Mine.png"));

            //Create message box telling you that you died when you click on a mine.

            QMessageBox *msg = new QMessageBox();
            msg->setWindowTitle("You lose");
            msg->setText("You touched a mine and died.");
            msg->exec();

        }

        if(isMine == false)
        {

            qDebug() << "Tile(" << location.x << "," << location.y << ") is not a mine!";


            if(minesAround == 0)
            {
                this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Clicked.png"));
                revealEmptyTiles();
            }

            if(minesAround == 1)
            {
                this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/One.png"));
                revealEmptyTiles();
            }

            if(minesAround == 2)
            {
                this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Two.png"));
            }

            if(minesAround == 3)
            {
                this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Three.png"));
            }

            if(minesAround == 4)
            {
                this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Four.png"));
            }

            if(minesAround == 5)
            {
                this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Five.png"));
            }

            if(minesAround == 6)
            {
                this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Six.png"));
            }

            if(minesAround == 7)
            {
                this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Seven.png"));
            }

            if(minesAround == 8)
            {
                this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Eight.png"));
            }
        }
        //this->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Clicked.png"));
    }
    if(isClickable == false)
    {
        qDebug() << "Tile(" << location.x << "," << location.y << ") is inactive 2";
    }

}







void Tile::findNearbyTiles(QList<Tile *> allTiles)
{

    foreach(Tile *tile,allTiles)
    {
        if(tile->location.x == this->location.x +1 && tile->location.y == this->location.y +1)
        {
            nearbyTiles.append(tile);

            qDebug() << "Tile(" << location.x << "," << location.y << ")found a new friend at (" << tile->location.x << "," << tile->location.y << ")";
        }
        if(tile->location.x == this->location.x +1 && tile->location.y == this->location.y -1)
        {
            nearbyTiles.append(tile);

            qDebug() << "Tile(" << location.x << "," << location.y << ")found a new friend at (" << tile->location.x << "," << tile->location.y << ")";
        }
        if(tile->location.x == this->location.x -1 && tile->location.y == this->location.y -1)
        {
            nearbyTiles.append(tile);

            qDebug() << "Tile(" << location.x << "," << location.y << ")found a new friend at (" << tile->location.x << "," << tile->location.y << ")";
        }
        if(tile->location.x == this->location.x -1 && tile->location.y == this->location.y +1)
        {
            nearbyTiles.append(tile);

            qDebug() << "Tile(" << location.x << "," << location.y << ")found a new friend at (" << tile->location.x << "," << tile->location.y << ")";
        }
        if(tile->location.x == this->location.x +1 && tile->location.y == this->location.y)
        {
            nearbyTiles.append(tile);

            qDebug() << "Tile(" << location.x << "," << location.y << ")found a new friend at (" << tile->location.x << "," << tile->location.y << ")";
        }
        if(tile->location.x == this->location.x -1 && tile->location.y == this->location.y)
        {
            nearbyTiles.append(tile);

            qDebug() << "Tile(" << location.x << "," << location.y << ")found a new friend at (" << tile->location.x << "," << tile->location.y << ")";
        }
        if(tile->location.x == this->location.x && tile->location.y == this->location.y +1)
        {
            nearbyTiles.append(tile);

            qDebug() << "Tile(" << location.x << "," << location.y << ")found a new friend at (" << tile->location.x << "," << tile->location.y << ")";
        }
        if(tile->location.x == this->location.x && tile->location.y == this->location.y -1)
        {
            nearbyTiles.append(tile);

            qDebug() << "Tile(" << location.x << "," << location.y << ")found a new friend at (" << tile->location.x << "," << tile->location.y << ")";
        }
    }


}

void Tile::checkNearbyTiles()
{
    foreach(Tile *tile,nearbyTiles)
    {
        if(tile->isMine == true)
        {
            qDebug() << "Tile(" << location.x << "," << location.y << ") is a mine";
            minesAround++;

        }
    }

}

void Tile::revealEmptyTiles()
{
    foreach(Tile *tile,nearbyTiles)
    {
        if(tile->isMine == false)
        {

            tile->isClicked = true;
            tile->isClickable = false;
            qDebug() << "Tile(" << tile->location.x << "," << tile->location.y << ") was Revealed!";

            if(tile->minesAround == 0)
            {
                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Clicked.png"));
                foreach(Tile *tile,tile->nearbyTiles)
                {
                    {
                        if(tile->isMine == false)
                        {

                            tile->isClicked = true;
                            tile->isClickable = false;
                            qDebug() << "Tile(" << tile->location.x << "," << tile->location.y << ") was Revealed!";

                            if(tile->minesAround == 0)
                            {
                                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Clicked.png"));
                                foreach(Tile *tile,tile->nearbyTiles)
                                {
                                    if(tile->isMine == false)
                                    {

                                        tile->isClicked = true;
                                        tile->isClickable = false;
                                        qDebug() << "Tile(" << tile->location.x << "," << tile->location.y << ") was Revealed!";

                                        if(tile->minesAround == 0)
                                        {
                                            tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Clicked.png"));
                                            //foreach(Tile *tile,tile->nearbyTiles)
                                        }

                                        else if(tile->minesAround == 1)
                                        {
                                            tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/One.png"));
                                        }

                                        else if(tile->minesAround == 2)
                                        {
                                            tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Two.png"));
                                        }

                                        else if(tile->minesAround == 3)
                                        {
                                            tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Three.png"));
                                        }

                                        else if(tile->minesAround == 4)
                                        {
                                            tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Four.png"));
                                        }

                                        else if(tile->minesAround == 5)
                                        {
                                            tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Five.png"));
                                        }

                                        else if(tile->minesAround == 6)
                                        {
                                            tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Six.png"));
                                        }

                                        else if(tile->minesAround == 7)
                                        {
                                            tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Seven.png"));
                                        }

                                        else if(tile->minesAround == 8)
                                        {
                                            tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Eight.png"));
                                        }



                                    }
                                }
                            }

                            else if(tile->minesAround == 1)
                            {
                                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/One.png"));
                            }

                            else if(tile->minesAround == 2)
                            {
                                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Two.png"));
                            }

                            else if(tile->minesAround == 3)
                            {
                                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Three.png"));
                            }

                            else if(tile->minesAround == 4)
                            {
                                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Four.png"));
                            }

                            else if(tile->minesAround == 5)
                            {
                                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Five.png"));
                            }

                            else if(tile->minesAround == 6)
                            {
                                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Six.png"));
                            }

                            else if(tile->minesAround == 7)
                            {
                                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Seven.png"));
                            }

                            else if(tile->minesAround == 8)
                            {
                                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Eight.png"));
                            }



                        }
                    }
                }
            }

            else if(tile->minesAround == 1)
            {
                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/One.png"));
            }

            else if(tile->minesAround == 2)
            {
                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Two.png"));
            }

            else if(tile->minesAround == 3)
            {
                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Three.png"));
            }

            else if(tile->minesAround == 4)
            {
                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Four.png"));
            }

            else if(tile->minesAround == 5)
            {
                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Five.png"));
            }

            else if(tile->minesAround == 6)
            {
                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Six.png"));
            }

            else if(tile->minesAround == 7)
            {
                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Seven.png"));
            }

            else if(tile->minesAround == 8)
            {
                tile->setPixmap(QPixmap(":/Images/Minesweeper Tile Assets/Eight.png"));
            }



        }
    }
}
