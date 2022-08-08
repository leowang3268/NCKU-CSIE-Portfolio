#ifndef UFO_H
#define UFO_H

#include <QGraphicsPixmapItem>
#include <QObject>

class ufo: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    ufo(QGraphicsItem * parent = 0);

public slots:
    void fall();

private:
    double dv = 0.1;

};
#endif // UFO_H
