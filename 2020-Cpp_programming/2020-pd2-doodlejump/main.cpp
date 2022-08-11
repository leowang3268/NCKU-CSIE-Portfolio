/*
#include "mainwindow.h"
#include "doodle.h"
#include "score.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>

/*int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene * scene = new QGraphicsScene();

    // create an item to put into the scene
    static doodle * doodleplayer = new doodle();
    doodleplayer->setRect(0, 0, 50, 50); // change the rect from 0x0(default) to 50x50 pixels

    // add the item to the scene
    scene->addItem(doodleplayer);

    //make the rect focusable
    doodleplayer->setFlag(QGraphicsItem::ItemIsFocusable);
    doodleplayer->setFocus();

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //show the view
    view->show();
    view->setFixedSize(400, 600);
    scene->setSceneRect(0, 0, 400, 600);
    doodleplayer->setPos(view->width()/2 - doodleplayer->rect().width()/2, view->height() - doodleplayer->rect().height());

    // spawn the monsters
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), doodleplayer, SLOT(spawn()));
    timer->start(5000); // 5 seconds monster will appear

    // display the score
    score * scores = new score();
    scene->addItem(scores);


    // set backgorund music
    QMediaPlayer * bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/music/Coffin Dance Offical Music Video.mp3"));
    bgm->play();

    return a.exec();
} */


#include <QApplication>
#include "mainwindow.h"

game * doodlegame;

int main(int argc, char * argv[]){
    QApplication a(argc, argv);

    doodlegame = new game();
    doodlegame->show();

    return a.exec();
}
