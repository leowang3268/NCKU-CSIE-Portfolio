#include "ufo.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <cstdlib> // rand()

ufo::ufo(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set random position
    int random_number = rand() % 300;
    setPos(random_number, 0);

    // draw the graphic
    setPixmap(QPixmap(":/images/ufo.jpeg").scaled(100, 100));

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(fall()));
    timer->start(1);
}

void ufo::fall(){
    dv += 0.001;
    setPos(x(), y() + dv);
    if(pos().x() > 500 ){
        scene()->removeItem(this);
        delete this;
    }
}
