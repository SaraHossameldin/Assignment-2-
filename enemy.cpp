
#include "enemy.h"
//#include <QMediaPlayer>


Enemy::Enemy(Player *)
{
    //to add the sound
   // gameoversound = new QMediaPlayer();
  //  gameoversound->setMedia("C:\\Users\\sarah\\Desktop\\Chicken_Invaders_Assignment_Sara_&_Menna\\gameover sound.mp3");


    setPixmap(QPixmap("C:\\Users\\sarah\\AppData\\Local\\Temp\\34d58435-aee2-489c-8a80-3a08bb91933b_Assignment 2 - Game (4).zip.33b\\chicken.png").scaled(80, 80));
    setPos(500,0);

    //  Moving the enemies downwards every 50 milli second **
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

void Enemy:: move()
{
    setPos(x(),y()+5);
    if(y()+rect->y()>1000)
    {
        rect->decrease_health();
        scene()->removeItem(this);
        delete this;
    } else this->collide();



}

void Enemy::collide()
{

    //score
    QGraphicsTextItem * score = new QGraphicsTextItem;
    score->setFont(QFont("times", 16));
    score->setDefaultTextColor(Qt::blue);
    score->setPlainText("Score: " + QString::number(0));
    score->setPos(600,10);

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
                game_over*  gameOver = new game_over;
                gameOver->show();
              //  if (chickensound-> state()==QMediaPlayer :: PlayingState){
               //  chickensound->setPos(0);
             //  }
              //  else  chickensound -> play();

                return;
            }

        }
    }
}
