#include "player.h"

#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QMediaPlayer>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include<score_health.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // scene
    QGraphicsScene scene;
    scene->setSceneRect(0,0,800,800);



    //view
    QGraphicsView view;
    view->setFixedSize(800,600);
    view.setScene(&scene);
    view.show();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);




  //Object of type Player
    Player * play = new Player(scene);
    play-> rect->setPixmap(QPixmap("C:\\Users\\sarah\\AppData\\Local\\Temp\\ecb2720d-aa14-48d1-bc98-2c9172813b3a_Assignment 2 - Game (4).zip.b3a\\ship.png").scaled(80, 80));
    scene->addItem(play);
    play -> setPos(10, 450);



    //making the player focusable
    play->setFlag(QGraphicsItem::ItemIsFocusable);
    play->setFocus();



    //  Enemy
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),rect,SLOT(createEnemy()));
    time->start(2000);


    //score
     Score_Health* score =play->get_score();
     scene -> addItem(score);


     //health
     Score_Health* health= play->get_health();
     health-> setPos(100,100);
     scene -> addItem(health);

     // (Bonus) laser sound
    QMediaPlayer* bullet = new QMediaPlayer();
    bullet->setMedia("C:\\Users\\sarah\\Desktop\\Chicken_Invaders_Assignment_Sara_&_Menna\\laser sound.mp3");
    bullet -> play();

    return a.exec();
}
