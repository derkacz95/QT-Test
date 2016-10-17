#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(x() > 0)
        {
            setPos(x() - 10, y());
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(x() + 100 < 800 )
            setPos(x() + 10, y());
    }
    else if(event->key() == Qt::Key_Space)
    {
        // create a bullet

        Bullet* bullet = new Bullet();
        bullet->setPos(x() + 50,y() - bullet->rect().height());
        qDebug() << "Bullet created";
        scene()->addItem(bullet);

    }
}

void MyRect::Spawn()
{
    Enemy* enemy = new Enemy();
    scene()->addItem(enemy);


}
