#ifndef BULLET_H
#define BULLET_H
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include "enemy.h"
#include "player.h"
#include "score_health.h"

// #include"main.cpp"
//#include <QMediaPlayer>


class Player;
class Bullet: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT
    // QMediaPlayer* chickensound;
    Player* rect;
public:
    Bullet(Player* p);

public slots:
    void move();
};

#endif // BULLET_H
