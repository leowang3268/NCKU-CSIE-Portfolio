#ifndef MONSTER_H
#define MONSTER_H

#include <QGraphicsPixmapItem>
#include <QObject>

class monster: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    monster(QGraphicsItem * parent = 0);

public slots:
    void move();
};

#endif // MONSTER_H
