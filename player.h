#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "score_health.h"
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QMediaPlayer>


class Player: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    health_score* score;
    health_score* health;
    QGraphicsScene* scene;
    //sound
    // QMediaPlayer* bulletsound;

public:
    Player(QGraphicsScene* scene);
public:
    void keyPressEvent(QKeyEvent * event);
    health_score* get_score();
    health_score* get_health();
    void decrease_health();
    void increase_score();

public slots:
    void createEnemy();

};

#endif // PLAYER_H
