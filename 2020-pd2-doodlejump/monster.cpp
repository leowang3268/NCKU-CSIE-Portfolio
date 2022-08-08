#include "monster.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <cstdlib> // rand()

monster::monster(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set random position
    int random_number = rand() % 300;
    setPos(random_number, 0);

    // draw the graphic
    setPixmap(QPixmap(":/images/monster.jpeg").scaled(120, 120));

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(10);
}

void monster::move(){
    setPos(x()+3, y());
    if(pos().x() > 400 ){
        setPos(x()-500, y());
    }
}
