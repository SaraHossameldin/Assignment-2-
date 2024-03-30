
#include "player.h"
#include<QKeyEvent>

//#include <QMediaPlayer>

Player::Player(QGraphicsScene* scene)
{

    this->scene = scene;
    setPixmap(QPixmap("C:\\Users\\sarah\\Downloads\\Images\\download.jpeg").scaled(80, 80));
    score = new health_score(nullptr, 2);
    health = new health_score(nullptr, 1);


    scene -> addItem(score);
    score-> setPos(score->x(),score->y()+25);
    scene -> addItem(health);
    health-> setPos(health->x(),health->y()+50);

}


health_score* Player :: get_score (){
    return (this-> score);
}

health_score* Player :: get_health (){
    return (this-> health);
}
void Player::keyPressEvent(QKeyEvent *event)
{
  //  bulletsound = new QMediaPlayer();
  //  bullet->setMedia("C:\\Users\\sarah\\AppData\\Local\\Temp\\10e8baf5-a2cb-4206-9176-a93fffc69ec3_Assignment 2 - Game (4).zip.ec3\\red_laser.png");


    if(event->key()== Qt::Key_Left)
    {
            setPos(x()-50,y());
    }
    else if(event->key()== Qt::Key_Right)

    {
            setPos(x()+50,y());
    }
    else if(event->key()== Qt::Key_Up)
    {
            setPos(x(), y()-50);
    }
    else if(event->key()== Qt::Key_Down)

    {
            setPos(x(),y()+50);
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet(this);


        this->scene->addItem(bullet);
        bullet->setPos(x()+40, y());


        //(BONUS) sound
       // if (bulletsound-> state()==QMediaPlayer :: PlayingState)
       // {
       //    bulletsound->setPos(0);
       // }
      //  else  bulletsound -> play();
    }


//to increase &decrease the score
}
void Player::decrease_health()
{
    health->decrease();
}
void Player::increase_score()
{
    score->increase();
}

//enemy
void Player::createEnemy()
{
    if (this->get_health()->getHealth() < 1)
        return;
    Enemy* enemy = new Enemy(this);
    this->scene->addItem(enemy);

}
