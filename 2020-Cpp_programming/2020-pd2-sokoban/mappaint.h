#ifndef MAPPAINT_H
#define MAPPAINT_H

#define MAN 0
#define GROUND 1
#define WALL 2
#define BOX 3
#define GOAL 4

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QPaintEvent>
#include <vector>

class mappaint : public QWidget
{
    Q_OBJECT
    
public :
    mappaint(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    int map_x, map_y;
    int man_x, man_y;
    int man_x_1, man_y_1;
    int levelNow;
    int stepNow;
    std::vector<std::vector<int>> mapNow;
    QPixmap *paint[6];
    int BeginOrEnd;

};


#endif // MAPPAINT_H
