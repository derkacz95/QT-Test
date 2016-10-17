#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <stdlib.h>

Enemy::Enemy()
{
    // set random position
    int random_number = rand() % 700;
    setPos(random_number, 0);

    // draw the rect
    setRect(0, 0, 100, 100);
    setBrush(QBrush(QColor(255,0,255)));

    // connect to slot
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    // move the bullet up
    setPos(x(), y() + 5);

    if(pos().y() + this->rect().height() > 600)
    {
        scene()->removeItem(this);
        delete this;

        qDebug() << "Bullet deleted";
    }
}
