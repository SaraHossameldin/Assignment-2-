
#include"bullet.h"
#include <QMediaPlayer>

Bullet::Bullet(Player* p):QObject(), QGraphicsPixmapItem() {


    rect = p;

    setPixmap(QPixmap("C:\\Users\\sarah\\AppData\\Local\\Temp\\45db8745-296d-42a2-8e87-0b19d41be934_Assignment 2 - Game (4).zip.934\\red_laser.png").scaled(5, 30));


    // generating bullets every 50 ms
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

void Bullet:: move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            rect->increase_score();

            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            delete colliding_items[i];
            delete this;
            if (chickensound-> state()==QMediaPlayer :: PlayingState){
                chickensound->setMedia("C:\\Users\\sarah\\Desktop\\Chicken_Invaders_Assignment_Sara_&_Menna\\chicken sound.mp3");
            }
           else  chickensound -> play();
            return;
        }

    }

    // Moving the bullets upwards
    setPos(x(),y()-10);
    if(pos().y()+rect->y()<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

