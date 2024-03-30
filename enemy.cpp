#include "enemy.h"


Enemy::Enemy(Player* p) {
    // <<<<<<< HEAD

    gameoversound = new QMediaPlayer();
    gameoversound->setMedia(":/soundssss/gameover sound.mp3");

    rect = p;
    // QGraphicsPixmapItem * pixmap1;
    // QPixmap Pixmap1(":/images/Chicken.png");

    ;
    setPixmap(QPixmap(":/new/prefix1/Chicken.png").scaled(80, 80));
    // *  Setting the size of the enemy **
    // setRect(0,0,100,100);

    // *  Setting the postion of the enemy within the view dimensions
    int random_number = rand() % 700;
    setPos(random_number,0);

    // *  Moving the enemies downwards automatically every 50 milli second **
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT (move()));
    timer->start(50);

}
// Function move: move the enemy downwards untill the end of the scene then remove it and delete it
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
            qDebug() << "HEYYYY";
            // scene()->removeItem(colliding_items[i]);
            Player* rect = dynamic_cast<Player*> (colliding_items[i]);
            scene()->removeItem(this);
            qDebug() << "HEYYYY";
            // delete colliding_items[i];
            //score

            delete this;

            rect->decrease_health();
            if(rect-> get_health()->getHealth() < 1)
            {
                game_over*  gameOver = new game_over;
                gameOver->show();
                if (chickensound-> state()==QMediaPlayer :: PlayingState){
                    chickensound->setPos(0);
                }
                else  chickensound -> play();

                return;
            }
            // scene() -> removeItem(rect);
        }
    }
}
