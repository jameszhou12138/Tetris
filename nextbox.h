#ifndef NEXTBOX_H
#define NEXTBOX_H

#include <QWidget>
#include <QPainter>
#include "tetris.h"

class NextBox: public QWidget{
        Q_OBJECT

    public:
        explicit NextBox(QWidget *parent = nullptr);
        void updateNextTetris(Tetris tetris);
        void paintEvent(QPaintEvent *event);


    private:
        Block nextBlock;
};

#endif // NEXTBOX_H
