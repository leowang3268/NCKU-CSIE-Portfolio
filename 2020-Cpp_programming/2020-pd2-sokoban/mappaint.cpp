#include "mappaint.h"
#include "mainwindow.h"

mappaint::mappaint(QWidget *parent) :
    QWidget(parent)
{
    map_x = 600;
    map_y = 480;
    setFixedSize(map_x, map_y);
    paint[0] = new QPixmap("/image/images/man.png");
    paint[1] = new QPixmap("/image/images/ground.png");
    paint[2] = new QPixmap("/image/images/wall.png");
    paint[3] = new QPixmap("/image/images/box.png");
    paint[4] = new QPixmap("/image/images/goal.png");
    paint[5] = new QPixmap("/image/images/start.png");
}

void mappaint::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    if(BeginOrEnd==0) //start::quitGame
    {
        setFixedSize(map_x, map_y);
        QPixmap l = *paint[5];
        p.drawPixmap(0, 0, l);
    }
    else
    {
        setFixedSize(map_x,map_y);
        for(int i=0; i<16; i++)
            for(int j=0; j<20; j++)
            {
                QPixmap l = *paint[GROUND];
                p.drawPixmap(j*30, i*30, l);
            }

        for(int i=0; i<mapNow.size(); i++)
            for(int j=0; j<mapNow[0].size(); j++)
            {

                if(mapNow[i][j]!=MAN)
                {
                    QPixmap l = *paint[mapNow[i][j]];
                    p.drawPixmap((j+9-mapNow[i].size()/2+1)*30
                                 , (i+9-mapNow.size()/2-1)*30, l);
                }
                else
                {
                    QPixmap l = *paint[GROUND];
                    p.drawPixmap((j+9-mapNow[i].size()/2+1)*30
                                 , (i+9-mapNow.size()/2-1)*30, l);
                }


            }
        QPixmap l1=*paint[WALL];
        p.drawPixmap((man_y_1+9-mapNow[0].size()/2+1)*30
                , (man_x_1+9-mapNow.size()/2-1)*30, l1);
    }
}
