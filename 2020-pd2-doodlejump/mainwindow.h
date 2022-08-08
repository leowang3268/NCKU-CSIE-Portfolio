#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include "doodle.h"
#include "score.h"
#include "monster.h"

class game: public QGraphicsView{
public:
    game(QWidget * parent = 0);

    QGraphicsScene * scene;
    doodle * doodleplayer;
    score * scores;
    monster * monsters;
};

#endif // MAINWINDOW_H
