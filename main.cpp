#include "player.h"
#include <QApplication>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include<QGraphicsView>
//#include <QMediaPlayer>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include<score_health.h>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // scene
    QGraphicsScene* scene=new QGraphicsScene();
    scene->setSceneRect(0,0,800,800);



    //view
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(800,800);
    view->show();
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);




  //Pointer of type Player
    Player* play =new Player (scene);
    play->setPixmap(QPixmap("C:\\Users\\sarah\\Downloads\\Images\\download.jpeg").scaled(50, 50));
    scene->addItem(play);
    play->setPos(10, 450);



    //making the player focusable
    play->setFlag(QGraphicsItem::ItemIsFocusable);
    play->setFocus();



    //  Enemy
    QTimer * time = new QTimer();
    QObject::connect(time, SIGNAL(timeout()),play,SLOT(createEnemy()));
    time->start(2000);


    //score
    //health_score* score =play->get_score();
    //scene->addItem(score);


     //health
    //health_score* health= play->get_health();
  //   health->setPos(100,100);
    ///scene->addItem(health);

     // (Bonus) laser sound
   // QMediaPlayer* bullet = new QMediaPlayer();
   // bullet->setMedia("C:\\Users\\sarah\\Desktop\\Chicken_Invaders_Assignment_Sara_&_Menna\\laser sound.mp3");
  // bullet -> play();

    return a.exec();
}
