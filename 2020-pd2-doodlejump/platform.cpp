#include "platform.h"
#include <QGraphicsScene>
#include <QList>
#include <cstdlib> // rand()

platform::platform(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set random position
    int random_numberx = rand() % 350;
    int random_numbery = rand() % 550;
    setPos(random_numberx, random_numbery);
    // draw the graphic
    setPixmap(QPixmap(":/images/normalplatform.jpeg").scaled(90, 10));
}
