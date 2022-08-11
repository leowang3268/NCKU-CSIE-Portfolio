#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class score: public QGraphicsTextItem{
public:
    score(QGraphicsItem * parent = 0);
    void scorecounter();
    int get_score();

private:
    int scores;
};

#endif // SCORE_H
