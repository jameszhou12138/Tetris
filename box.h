#ifndef BOX_H
#define BOX_H

#include <QWidget>
#include <QPainter>
#include "tetris.h"

class Box: public QWidget{
        Q_OBJECT

    public:
        explicit Box(QWidget *parent = nullptr);
        void updateTetris(Tetris tetris);
        void paintEvent(QPaintEvent *event);


    private:
        Block block;
        Block shadowBlock;
        bool box[10][20];
};

#endif // BOX_H
