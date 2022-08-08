#include "mainwindow.h"
#include "doodle.h"
#include "score.h"
#include "monster.h"
#include "ufo.h"
#include <QGraphicsTextItem>
#include <QFont>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

game::game(QWidget * parent)
{
    // create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 400, 600);
    // draw the background
    setBackgroundBrush(QBrush(QImage(":/images/background.jpeg")));

    // add a view
    QGraphicsView * view = new QGraphicsView(scene);

    // create an doodleplayer to put into the scene
    doodleplayer = new doodle();
    // draw graphic of doodle
    doodleplayer->setPixmap(QPixmap(":/images/doodle.png").scaled(60, 60));

    doodleplayer->setPos(view->width()/2 - doodleplayer->pixmap().width()/2, view->height() - doodleplayer->pixmap().height());

    // add the item to the scene
    scene->addItem(doodleplayer);

    //make the rect focusable
    doodleplayer->setFlag(QGraphicsItem::ItemIsFocusable);
    doodleplayer->setFocus();

    // turn off the scrollbar
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // generate the gravity
    QTimer * gravitytimer = new QTimer();
    connect(gravitytimer, SIGNAL(timeout()), doodleplayer, SLOT(gravity()));
    gravitytimer->start(1);


    // spawn the monsters
    QTimer * spawnmonstertimer = new QTimer();
    QObject::connect(spawnmonstertimer, SIGNAL(timeout()), doodleplayer, SLOT(spawnmonster()));
    spawnmonstertimer->start(5000); // 5 seconds monster will appear

    // spawn the ufos
    QTimer * spawnufostimer = new QTimer();
    QObject::connect(spawnufostimer, SIGNAL(timeout()), doodleplayer, SLOT(spawnufo()));
    spawnufostimer->start(10000); // 10 seconds ufo will appear

    // spawn the platforms
    QTimer * spawnplatformstimer = new QTimer();
    QObject::connect(spawnplatformstimer, SIGNAL(timeout()), doodleplayer, SLOT(spawnplatform()));
    spawnplatformstimer->start(5000); // 5 seconds platform will appear

    // display the score
    scores = new score();
    scene->addItem(scores);

    //show the view
    view->show();
    view->setFixedSize(400, 600);

    // set backgorund music
    QMediaPlayer * bgm = new QMediaPlayer();
    bgm->setMedia(QUrl("qrc:/bgm/Coffin Dance Offical Music Video.mp3"));
    bgm->play();
}
