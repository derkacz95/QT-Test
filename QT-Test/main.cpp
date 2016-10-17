#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
#include <QTimer>
#include <QGraphicsView>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();

    // create an item to put into the scene
    MyRect* player = new MyRect();
    player->setRect(0,0,100,100);
    player->setBrush(QBrush(QColor(255,0,0)));

    //add the item to the scene
    scene->addItem(player);

    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    // add a view
    QGraphicsView* view = new QGraphicsView();
    view->setScene(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    player->setPos(view->width()/2 - (player->rect().width() / 2), view->height() - player->rect().height());
    view->show();


    // spawn enemies
    QTimer* timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(Spawn()));
    timer->start(2000);

    return a.exec();
}
