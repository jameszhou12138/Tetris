#include "block.h"

Block::Block(){
    memset(x, -1, sizeof (x));
    memset(y, -1, sizeof (y));
    centerX = -1;
    centerY = -1;
    id = 0;
    color.setRgb(255, 255, 255);
}


void Block::create(){
    centerX = 4;
    int ID = rand() % 7;
    if (ID == 0){
        //··
        //··
        x[0] = centerX;
        y[0] = -2;
        x[1] = centerX;
        y[1] = -1;
        x[2] = centerX + 1;
        y[2] = -2;
        x[3] = centerX + 1;
        y[3] = -1;
        centerX = 0;
        centerY = 0;
        id = 0;
        color.setRgb(255, 255, 0);
    }else if (ID == 1){
        //····
        x[0] = centerX - 1;
        y[0] = -1;
        x[1] = centerX;
        y[1] = -1;
        x[2] = centerX + 1;
        y[2] = -1;
        x[3] = centerX + 2;
        y[3] = -1;

        centerY = -1;
        id = 1;
        color.setRgb(0, 255, 255);
    }else if (ID == 2){
        //··
        // ··
        x[0] = centerX - 1;
        y[0] = -2;
        x[1] = centerX;
        y[1] = -2;
        x[2] = centerX;
        y[2] = -1;
        x[3] = centerX + 1;
        y[3] = -1;

        centerY = -2;
        id = 2;
        color.setRgb(255, 0, 0);
    }else if (ID == 3){
        // ··
        //··
        x[0] = centerX;
        y[0] = -2;
        x[1] = centerX + 1;
        y[1] = -2;
        x[2] = centerX - 1;
        y[2] = -1;
        x[3] = centerX;
        y[3] = -1;

        centerY = -2;
        id = 3;
        color.setRgb(144, 238, 144);
    }else if (ID == 4){
        //·
        //···
        x[0] = centerX - 1;
        y[0] = -2;
        x[1] = centerX - 1;
        y[1] = -1;
        x[2] = centerX;
        y[2] = -1;
        x[3] = centerX + 1;
        y[3] = -1;
        centerY = -1;
        id = 4;color.setRgb(0, 0, 255);
    }else if (ID == 5){
        //  ·
        //···
        x[0] = centerX + 1;
        y[0] = -2;
        x[1] = centerX - 1;
        y[1] = -1;
        x[2] = centerX;
        y[2] = -1;
        x[3] = centerX + 1;
        y[3] = -1;

        centerY = -1;
        id = 5;
        color.setRgb(255, 165, 0);
    }else if (ID == 6){
        // ·
        //···
        x[0] = centerX;
        y[0] = -2;
        x[1] = centerX - 1;
        y[1] = -1;
        x[2] = centerX;
        y[2] = -1;
        x[3] = centerX + 1;
        y[3] = -1;

        centerY = -1;
        id = 6;
        color.setRgb(255, 0, 255);
    }
}


void Block::clear(){
    memset(x, -1, sizeof (x));
    memset(y, -1, sizeof (y));
    centerX = -1;
    centerY = -1;
    id = 0;
    color.setRgb(255, 255, 255);
}


void Block::setCenterX(int x){
    centerX = x;
}

void Block::setCenterY(int y){
    centerY = y;
}

void Block::setX(int i, int x){
    this->x[i] = x;
}

void Block::setY(int i, int y){
    this->y[i] = y;
}

void Block::setId(int id){
    this->id = id;
}

void Block::setColor(QColor color){
    this->color = color;
}


int Block::getCenterX(){
    return centerX;
}

int Block::getCenterY(){
    return centerY;
}

int Block::getX(int i){
    return x[i];
}

int Block::getY(int i){
    return y[i];
}

int Block::getId(){
    return id;
}

QColor Block::getColor(){
    return color;
}
