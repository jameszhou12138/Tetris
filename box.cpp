#include "box.h"

Box::Box(QWidget *parent) : QWidget(parent){
    block.clear();
    shadowBlock.clear();
    memset(box, 0, sizeof (box));
    int w = 30*10 + 4*(10-1);
    int h = 30*20 + 4*(20-1);
    setFixedSize(w, h);
}


void Box::updateTetris(Tetris tetris){
    block = tetris.getBlock();
    shadowBlock = tetris.getShadowBlock();
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 20; j++){
            box[i][j] = tetris.getBox(i, j);
        }
    }
    repaint();
}


void Box::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.drawRect(this->rect().x(),this->rect().y(),this->rect().width()-1,this->rect().height()-1);
    painter.setPen(Qt::white);
    int w = 30*10 + 4*(10-1);
    int h = 30*20 + 4*(20-1);
    setPalette(QPalette(Qt::black));
    setAutoFillBackground(true);
    for (int i = 1; i < 10; i++){
        painter.drawLine(i*34-2, 0, i*34-2, h);
    }
    for (int i = 1; i < 20; i++){
        painter.drawLine(0, i*34-2, w, i*34-2);
    }

    QPen boxPen;
    QBrush boxBrush;
    boxPen.setStyle(Qt::SolidLine);
    boxPen.setColor(Qt::gray);
    boxBrush.setStyle(Qt::SolidPattern);
    boxBrush.setColor(Qt::white);
    painter.setPen(boxPen);
    painter.setBrush(boxBrush);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 20; j++){
            if (box[i][j]){
                painter.drawRect(i*34, j*34, 30, 30);
            }
        }
    }

    QPen blockPen;
    QBrush blockBrush;
    blockPen.setStyle(Qt::SolidLine);
    blockPen.setColor(Qt::gray);
    blockBrush.setStyle(Qt::SolidPattern);
    blockBrush.setColor(block.getColor());
    painter.setPen(blockPen);
    painter.setBrush(blockBrush);
    for (int i = 0; i < 4; i++){
        int x = block.getX(i);
        int y = block.getY(i);
        painter.drawRect(x*34, y*34, 30, 30);
    }

    QPen shadowBlockPen;
    QBrush shadowBlockBrush;
    shadowBlockPen.setStyle(Qt::SolidLine);
    shadowBlockPen.setColor(Qt::gray);
    shadowBlockBrush.setStyle(Qt::SolidPattern);
    shadowBlockBrush.setColor(QColor(shadowBlock.getColor().red(), shadowBlock.getColor().green(), shadowBlock.getColor().blue(), 150));
    painter.setPen(shadowBlockPen);
    painter.setBrush(shadowBlockBrush);
    for (int i = 0; i < 4; i++){
        int x = shadowBlock.getX(i);
        int y = shadowBlock.getY(i);
        painter.drawRect(x*34, y*34, 30, 30);
    }
}
