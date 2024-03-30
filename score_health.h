#ifndef HEALTH_SCORE_H
#define HEALTH_SCORE_H

#include <QGraphicsTextItem>
#include <QFont>
class health_score: public QGraphicsTextItem{
public:
    health_score(QGraphicsItem * parent= nullptr, int x = 0);
    void decrease();
    int getHealth();
    void increase();
    int getScore();
private:
    int health;
    int score;
};
#endif // HEALTH_SCORE_H
