#include"bullet.h"


Bullet::Bullet(Player* p):QObject(), QGraphicsPixmapItem() {

    // chickensound = new QMediaPlayer();
    // chickensound->setMedia(":/sounds/chicken sound.mp3");
    rect = p;
    // QGraphicsPixmapItem * pixmap3 = new QGraphicsPixmapItem();
    /*QPixmap Pixmap3(":/new/prefix1/red laser.png")*/;
    // Pixmap3./*scaled(5, 30)*/;
    // pixmap3->setPixmap(Pixmap3);

    setPixmap(QPixmap(":/new/prefix1/red laser.png").scaled(5, 30));
    // QPixmap(QPixmap(":/new/prefix1/red laser.png").scaled(5, 30));
    // *  Setting the bullets' size
    //setRect(0,0,10,50);

    // *  Generating the Bullets automatically
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);
}

// Move function is used to 1-  move the bullet upwards
// 2- Handle the collision of the bullets with enemies
void Bullet:: move(){
    // qDebug() << "you";
    // *  Getting the colliding items with the Bullet
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
                chickensound->setMedia(":/soundssss/chicken sound.mp3");
            }
            else  chickensound -> play();
            return;
        }

    }

    // *  Moving the bullets upward
    setPos(x(),y()-10);
    if(pos().y()+rect->y()<0)
    {
        scene()->removeItem(this);
        delete this;
    }
}

