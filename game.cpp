#include "game.h"
#include "personnage.h"
#include "ballon.h"
#include "focushandler.h"
#include "button.h"
#include <QGraphicsTextItem>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QGraphicsLineItem>
#include <QGraphicsPixmapItem>
#include <QPainter>
#include <cstdlib>

QGraphicsView * view;

Game::Game(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1024,768);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1024,768);
    setScene(scene);
    view = new QGraphicsView(scene);
    view->show();
}

void Game::start(){
    // clear the screen
    scene->clear();
    scene->setSceneRect(0,-0,800,300);
    //setBackgroundBrush(QBrush(QImage(":/Image/Image/Environment/rouge.png")));
    //scene->setBackgroundBrush(QImage(":/Image/Environment/terrain_foot3.png"));
    QImage * bg = new QImage(":/Image/Environment/terrain_foot3.png");
    *bg = bg->scaled(1024,400);
    scene->setBackgroundBrush(*bg);
    Personnage * pers = new Personnage(Qt::Key_Left,Qt::Key_Up,Qt::Key_Right,Qt::Key_Down);
    Personnage * pers2 = new Personnage(Qt::Key_Q,Qt::Key_Z,Qt::Key_D,Qt::Key_S);
    Ballon * ballon = new Ballon();
    FocusHandler * focus = new FocusHandler();
    QGraphicsPixmapItem * cage1 = new QGraphicsPixmapItem();
    QGraphicsPixmapItem * cage2 = new QGraphicsPixmapItem();
    QPixmap * cage1_scaled = new QPixmap(":/Image/Environment/goal_2.png");
    QPixmap * cage2_scaled = new QPixmap(":/Image/Environment/goal_1.png");
    cage1_scaled->scaled(50,100);
    ballon->setPos(scene->width()/2,-scene->height());
    pers->setPixmap(QPixmap(":/Image/Player/Parts(more HD but not annimated)/P1.png"));
    pers2->setPixmap(QPixmap(":/Image/Player/Parts(more HD but not annimated)/p2.png"));
    cage1->setPixmap(*cage1_scaled);
    cage2->setPixmap(QPixmap(":/Image/Environment/goal_1.png"));
    pers->setPos(0,-scene->height());
    pers2->setPos(scene->width(),-scene->height());
    focus->setPos(-scene->width(),-scene->height());
    cage1->setPos(-135,scene->height()/2);
    cage2->setPos(scene->width()+80,scene->height()/2);
    focus->addPersonnage(pers);
    focus->addPersonnage(pers2);
    //add the item to the scene
    scene->addItem(ballon);
    scene->addItem(pers);
    scene->addItem(pers2);
    scene->addItem(cage1);
    scene->addItem(cage2);
    scene->addItem(focus);
    // make personnage focusable
    focus->setFlag(QGraphicsItem::ItemIsFocusable);
    pers2->setFlag(QGraphicsItem::ItemIsFocusable);
    focus->setFocus();
    //add a view
    //QGraphicsView * view = new QGraphicsView(scene);
    view->show();

}


void Game::close_game(){
    exit(0);
}



void Game::displayMainMenu(){
    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Head Soccer"));
    QFont titleFont("comic sans",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close_game()));
    scene->addItem(quitButton);
}


