#include "score_health.h"



health_score::health_score(QGraphicsItem *parent, int x): QGraphicsTextItem(parent){

    health = 3;
    score = 0;


    if(x==1)
    {
        setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
        setDefaultTextColor(Qt::blue);
        setFont(QFont("times",16));
    }
    else if(x==2)
    {
        // draw the text
        setPlainText(QString("Score: ") + QString::number(score)); // Score: 0
        setDefaultTextColor(Qt::blue);
        setFont(QFont("times",16));
    }
}

void health_score::decrease(){
    health=health-1;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
}

int health_score::getHealth(){
    return health;
}

void health_score::increase(){
    score++;
    setPlainText(QString("Score: ") + QString::number(score)); // Score: 1
}

int health_score::getScore(){
    return score;
}
