#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "personnage.h"
#include "ballon.h"
#include "focushandler.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    // constructors
    Game(QWidget* parent=NULL);

    // public methods
    void displayMainMenu();
    //QString getWhosTurn();
    //void setWhosTurn(QString player);

    // public attributes
    QGraphicsScene* scene;
    Ballon* ballon;
    Personnage* personnage;
    FocusHandler* f;

public slots:
    void start();
    void close_game();

private:
    // private methods
    //void drawPanel(int x, int y, int width, int height, QColor color, double opacity);
    //void drawGUI();
    //void createNewCard(QString player);
    //void createInitialCards();
    //void drawCards();

    // private attributes
    //QString whosTurn_;
    //QGraphicsTextItem* whosTurnText;
    //QList<Hex* > player1Cards;
    //QList<Hex* > player2Cards;
};

#endif // GAME_H
