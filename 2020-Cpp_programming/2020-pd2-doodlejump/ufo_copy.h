#ifndef UFO_H
#define UFO_H

#include <QGraphicsRectItem>
#include <QObject>

class ufo: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    ufo();

public slots:
    void spawnufo();

public slots:
    void hover();
};

#endif // UFO_H
