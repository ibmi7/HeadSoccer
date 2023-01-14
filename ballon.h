#ifndef BALLON_H
#define BALLON_H
#include <QObject>
#include "cercle.h"

class Ballon: public Cercle
{
    Q_OBJECT
public:
    Ballon() : Cercle(){
        vit.push_back(qMakePair(0,10));
        acc.push_back(qMakePair(0,10));
        setPixmap(QPixmap(":/Image/Ball/ball1.png"));
    };
public slots:
    void move();
private:
    long id;
};

#endif // BALLON_H
