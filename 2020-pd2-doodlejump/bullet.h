#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

class bullet: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT // handle singals and slots
public:
    bullet(QGraphicsItem * parent = 0);

public slots:
    void fly();
};

#endif // BULLET_H
