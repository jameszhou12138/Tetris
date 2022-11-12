#include "nextbox.h"

NextBox::NextBox(QWidget *parent) : QWidget(parent){
    nextBlock.clear();

    int w = 30*4 + 4*(4-1);
    int h = 30*4 + 4*(4-1);
    setFixedSize(w, h);
}


void NextBox::updateNextTetris(Tetris tetris){
    nextBlock = tetris.getNextBlock();
    for (int i = 0; i < 4; i++){
        nextBlock.setX(i, nextBlock.getX(i)-3);
        nextBlock.setY(i, nextBlock.getY(i)+3);
    }

    repaint();
}


void NextBox::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.drawRect(this->rect().x(),this->rect().y(),this->rect().width()-1,this->rect().height()-1);
    painter.setPen(Qt::white);
    int w = 30*4 + 4*(4-1);
    int h = 30*4 + 4*(4-1);
    setPalette(QPalette(Qt::black));
    setAutoFillBackground(true);
    for (int i = 1; i < 4; i++){
        painter.drawLine(i*34-2, 0, i*34-2, h);
    }
    for (int i = 1; i < 4; i++){
        painter.drawLine(0, i*34-2, w, i*34-2);
    }

    QPen nextBlockPen;
    QBrush nextBlockBrush;
    nextBlockPen.setStyle(Qt::SolidLine);
    nextBlockPen.setColor(Qt::gray);
    nextBlockBrush.setStyle(Qt::SolidPattern);
    nextBlockBrush.setColor(nextBlock.getColor());
    painter.setPen(nextBlockPen);
    painter.setBrush(nextBlockBrush);
    for (int i = 0; i < 4; i++){
        int x = nextBlock.getX(i);
        int y = nextBlock.getY(i);
        painter.drawRect(x*34, y*34, 30, 30);
    }
}
