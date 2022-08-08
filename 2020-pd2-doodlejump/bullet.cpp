#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "monster.h"
#include "mainwindow.h"

extern game * doodlegame; // there is an extern global object called doodlegame

bullet::bullet(QGraphicsItem * parent): QObject(), QGraphicsPixmapItem(parent)
{
    // draw the graphic
    setPixmap(QPixmap(":/images/bullet.png").scaled(50, 50));

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(fly()));
    timer->start(10);
}

void bullet::fly()
{
    // if the bullets collide monster, destory both
    QList<QGraphicsItem * > colliding_items = collidingItems();

    for(int i=0; i<colliding_items.size(); ++i){
        if(typeid (*(colliding_items[i])) == typeid (monster)){
            // increase the score
            doodlegame->scores->scorecounter();

            // remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // delete them on the heap (prevent wasting memory)
            delete colliding_items[i];
            delete this;
            // let shooting NOT execute
            return;
        }
    }

    // shooting
    setPos(x(), y()-5);
    // delete the bullets for preventing wasting memory
    if(pos().y()< -200){
        scene()->removeItem(this);
        delete this;
    }

}
