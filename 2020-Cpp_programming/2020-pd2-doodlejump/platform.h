#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsPixmapItem>
#include <QObject>

class platform: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    platform(QGraphicsItem * parent = 0);

};
#endif // PLATFORM_H
