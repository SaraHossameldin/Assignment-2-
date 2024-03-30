
#include "player.h"
#include<QKeyEvent>

player::player(QGraphicsScene* scene)
{

    this->scene = scene;
    setPixmap(QPixmap(":/new/prefix1/ship.png").scaled(80, 80));
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
    bulletsound = new QMediaPlayer();
    bullet->setMedia(":/soundssss/laser sound.mp3");

    // *  Event Handling for the Player **

    if(event->key()== Qt::Key_Left)
    {
        if(pos().x()>0) // to prevent the player from getting out of the screen
        {
            setPos(x()-50,y());
        }
    }
    else if(event->key()== Qt::Key_Right)

    { if(pos().x()+100<800) // to prevent the player from getting out of the screen
            setPos(x()+50,y());
    }
    else if(event->key()== Qt::Key_Space)
    {
        Bullet * bullet = new Bullet(this);

        // qDebug() << "aaaaaaaaaaaaaaaa";
        this->scene->addItem(bullet);
        bullet->setPos(x()+40, y());
        //sound
        if (bulletsound-> state()==QMediaPlayer :: PlayingState){
            bulletsound->setPos(0);
        }
        else  bulletsound -> play();
    }



}
void Player::decrease_health()
{
    health->decrease();
}
void Player::increase_score()
{
    score->increase();
}
// CreateEnemy function used to create the eneimes
void Player::createEnemy()
{ Enemy* enemy = new Enemy(this);
    scene->addItem(enemy);

}
