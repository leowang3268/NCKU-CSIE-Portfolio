#include "score.h"
#include <QFont>
#include <QGraphicsScene>
#include "monster.h"

score::score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{
    // initialize the scores
    scores = 0;

    // draw the text of scores
    setPlainText(QString("score: ") + QString::number(scores));
    setDefaultTextColor(Qt::black);
    setFont(QFont("times", 20));
}

void score::scorecounter()
{
    scores += 100;
    // update the score
    setPlainText(QString("score: ") + QString::number(scores));
}

int score::get_score()
{
    return scores;
}
