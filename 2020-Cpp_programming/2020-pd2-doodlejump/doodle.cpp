#include "doodle.h"
#include "bullet.h"
#include "monster.h"
#include "ufo.h"
#include "platform.h"
#include "score.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <mainwindow.h>
#include <QMediaPlayer>
#include <QMessageBox>

extern game * doodlegame; // there is an extern global object called doodlegame

doodle::doodle(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    // set bullet sound
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bgm.mp3"));
}

void doodle::keyPressEvent(QKeyEvent *event)
{
    // left and right move
    if(event->key() == Qt::Key_Left){
        setPos(x()-10, y());
        if(pos().x() < -50 )
            setPos(x()+450, y());
    }
    else if(event->key() == Qt::Key_Right){
        setPos(x()+10, y());
        if(pos().x() > 400 )
            setPos(x()-450, y());
    }

    // shoot a bullet with key_up
    else if(event->key() == Qt::Key_Up){
        bullet * bullets = new bullet();
        bullets->setPos(x(), y());
        scene()->addItem(bullets);

        // play the bulletsound
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState) {
            bulletsound->play();
        }
    }

    // pause the game
    else if(event->key() == Qt::Key_Escape){

    }

}

void doodle::gravity() // auto go down for doodleplayer (without accleration)
{
    // automatically fall down
    setPos(x(), y() + dv);
    dv += 0.0002;
    if(pos().y() > 550 ){
        setPos(x(), y() - 125);
        dv = 0.1;
    }

    // if the doodleplayer collide platform, rebound
    QList<QGraphicsItem * > colliding_platform = collidingItems();

    for(int i=0; i<colliding_platform.size(); ++i){
        if(typeid (*(colliding_platform[i])) == typeid (platform)){
            setPos(x(), y() - 125);
            dv = 0.1;
        }
    }

    // if the doodleplayer collide monster, game over
    QList<QGraphicsItem * > colliding_monster = collidingItems();

    for(int i=0; i<colliding_monster.size(); ++i){
        if(typeid (*(colliding_monster[i])) == typeid (monster)){
            QMessageBox msgBoxmonsterkill;
            msgBoxmonsterkill.setText("GAME OVER");
            msgBoxmonsterkill.setInformativeText("press key OK to close the game.");
            msgBoxmonsterkill.exec();
            exit(1);
        }
    }

    // if the doodleplayer collide ufo, game over
    QList<QGraphicsItem * > colliding_ufo = collidingItems();

    for(int i=0; i<colliding_ufo.size(); ++i){
        if(typeid (*(colliding_ufo[i])) == typeid (ufo)){
            QMessageBox msgBoxufokill;
            msgBoxufokill.setText("GAME OVER");
            msgBoxufokill.setInformativeText("press key OK to close the game.");
            msgBoxufokill.exec();
            exit(1);
        }
    }
}

void doodle::spawnmonster() // create a monster
{
    monster * monsters = new monster();
    scene()->addItem(monsters);
}

void doodle::spawnufo() // create a ufo
{
    ufo * ufos = new ufo();
    scene()->addItem(ufos);
}

void doodle::spawnplatform() // create platforms
{
    platform * platforms = new platform();
    scene()->addItem(platforms);
}
