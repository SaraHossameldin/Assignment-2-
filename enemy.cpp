
#include "enemy.h"
//#include <QMediaPlayer>
#include<QMessageBox>
#include<QGraphicsScene>
#include<QApplication>
#include<QString>


Enemy::Enemy(Player *pPlayer)
{
    rect = pPlayer;
    //to add the sound
   // gameoversound = new QMediaPlayer();
  //  gameoversound->setMedia("C:\\Users\\sarah\\Desktop\\Chicken_Invaders_Assignment_Sara_&_Menna\\gameover sound.mp3");


    setPixmap(QPixmap("C:\\Users\\sarah\\Downloads\\Images\\chicken.png").scaled(80, 80));
    setPos(((int)(rand()% 10)) * 80,100);

    //  Moving the enemies downwards every 50 milli second **
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(500);
}

void Enemy:: move()
{
    if(rect-> get_health()->getHealth() < 1)
        return;
    setPos(x(),y()+5);
    if(y()>1000)
    {
        //rect->decrease_health();
        scene()->removeItem(this);
        delete this;
    } else this->collide();



}

void Enemy::collide()
{
   /* if (abs(x() - rect->x()) < 80 && abs(y() - rect->y()) < 80)
    {
        scene()->removeItem(this);
        rect->decrease_health();
        if(rect->get_health()->getHealth() < 1)
        {
            //Display game over message
            QMessageBox *msg = new QMessageBox;
            msg->setText("Game Over");
            msg->show();

        }
        delete this;
    }
    */
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Player))
        {
            Player* rect = dynamic_cast<Player*> (colliding_items[i]);
            scene()->removeItem(this);
            delete this;

            rect->decrease_health();
            if(rect-> get_health()->getHealth() < 1)
            {
               //Display game over message

                QMessageBox *msg = new QMessageBox;
               msg->setText("Game Over");
                msg->exec();

               QApplication::quit();

              //  if (chickensound-> state()==QMediaPlayer :: PlayingState){
               //  chickensound->setPos(0);
             //  }
              //  else  chickensound -> play();

                return;
            }

        }
    }
}
