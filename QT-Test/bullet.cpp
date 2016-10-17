#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
#include <typeinfo>

Bullet::Bullet()
{
    // draw the rect
    setRect(0, 0, 10, 50);
    setBrush(QBrush(QColor(0,255,255)));

    // connect to slot
    QTimer* timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    // if bullet collides with enemy destroy both
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for(int i = 0, n = colliding_items.size(); i < n; ++i)
    {
        if(typeid(*(colliding_items[i])) == typeid(Enemy))
        {
            scene()->removeItem((colliding_items[i]));
            scene()->removeItem(this);

            delete colliding_items[i];
            delete this;

            return;
        }
    }

    // move the bullet up
    setPos(x(), y() - 10);

    if(pos().y() + this->rect().height() < 0)
    {
        scene()->removeItem(this);
        delete this;

        qDebug() << "Bullet deleted";
    }
}
