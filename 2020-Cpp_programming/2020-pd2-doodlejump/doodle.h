#ifndef DOODLE_H
#define DOODLE_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QString>

class doodle: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT // macro which can handle singals and slots
public:
    doodle(QGraphicsItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);

public slots:
    void spawnmonster();
    void spawnufo();
    void spawnplatform();

public slots:
    void gravity();

private:
    double dv = 0.1;

private:
    QMediaPlayer * bulletsound;
};

#endif // DOODLE_H
