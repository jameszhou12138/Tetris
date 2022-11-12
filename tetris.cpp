#include "tetris.h"

Tetris::Tetris(){
    srand(unsigned(time(0)));
    score = 0;
    level = 1;
    memset(box, 0, sizeof (box));
    block.clear();
    createNextBlock();
}


void Tetris::init(){
    srand(unsigned(time(0)));
    score = 0;
    level = 1;
    memset(box, 0, sizeof (box));
    block.clear();
    createNextBlock();
}


void Tetris::createBlock(){
    block = nextBlock;
    createNextBlock();
}


void Tetris::createNextBlock(){
    nextBlock.create();
}


void Tetris::createShadowBlock(){
    shadowBlock = block;
    bool flag = true;
    while (flag){
        for (int i = 0; i < 4; i++){
            if (box[shadowBlock.getX(i)][shadowBlock.getY(i)+1]){
                flag = false;
                break;
            }
        }
        if (flag){
            for (int i = 0; i < 4; i++){
                shadowBlock.setY(i, shadowBlock.getY(i)+1);
            }
            shadowBlock.setCenterY(shadowBlock.getCenterY()+1);
        }
        for (int i = 0; i < 4; i++){
            if (shadowBlock.getY(i) == 19){
                flag = false;
                break;
            }
        }
    }
}


bool Tetris::move(int dx, int dy){
    int tempX[4], tempY[4];
    int tempCenterX, tempCenterY;
    for (int i = 0; i < 4; i++){
        tempX[i] = block.getX(i) + dx;
        tempY[i] = block.getY(i) + dy;
        if (tempX[i] < 0 || tempX[i] >= 10){
            return false;
        }
        if (tempY[i] >=0 && tempY[i] < 20){
            if (box[tempX[i]][tempY[i]]){
                return false;
            }
        }else if (tempY[i] >= 20){
            return false;
        }
    }
    tempCenterX = block.getCenterX() + dx;
    tempCenterY = block.getCenterY() + dy;
    for (int i = 0; i < 4; i++){
        block.setX(i, tempX[i]);
        block.setY(i, tempY[i]);
    }
    block.setCenterX(tempCenterX);
    block.setCenterY(tempCenterY);

    createShadowBlock();
    return true;
}


bool Tetris::moveLeft(){
    if (move(-1, 0)){
        return true;
    }else{
        return false;
    }
}


bool Tetris::moveRight(){
    if (move(1, 0)){
        return true;
    }else{
        return false;
    }
}


bool Tetris::moveDown(){
    if (! move(0, 1)){
        for (int i = 0; i < 4; i++){
            int x = block.getX(i);
            int y = block.getY(i);
            if (y >= 0){
                box[x][y] = 1;
            }
        }
        killLines();
        if (gameOver()){
            return false;
        }else{
            createBlock();
        }
    }
    return true;
}


bool Tetris::rotate(){
    int tempX[4], tempY[4];
    int tempCenterX, tempCenterY;
    if (block.getId() == 0){
        return false;
    }
    for (int i = 0; i < 4; i++){
        tempX[i] = block.getCenterX() + block.getCenterY() - block.getY(i);
        tempY[i] = block.getCenterY() - block.getCenterX() + block.getX(i);
        if (tempX[i] < 0 || tempX[i] >= 10){
            return false;
        }
        if (tempY[i] >=0 && tempY[i] < 20){
            if (box[tempX[i]][tempY[i]]){
                return false;
            }
        }else if (tempY[i] >= 20){
            return false;
        }
    }
    tempCenterX = block.getCenterX();
    tempCenterY = block.getCenterY();
    for (int i = 0; i < 4; i++){
        block.setX(i, tempX[i]);
        block.setY(i, tempY[i]);
    }
    block.setCenterX(tempCenterX);
    block.setCenterY(tempCenterY);
    createShadowBlock();
    return true;
}


bool Tetris::gameOver(){
    for (int i = 0; i < 10; i++){
        if (box[i][0]){
            return true;
        }
    }
    return false;
}


int Tetris::getLine(){
    for (int j = 0; j < 20; j++){
        bool flag = true;
        for (int i = 0; i < 10; i++){
            if (! box[i][j]){
                flag = false;
                break;
            }
        }
        if (flag){
            return j;
        }
    }
    return -1;
}


void Tetris::killLines(){
    int cnt = 0;
    int line = getLine();
    while (line != -1){
        for (int j = line; j >0; j--){
            for (int i = 0; i < 10; i++){
                box[i][j] = box[i][j-1];
            }
        }
        cnt++;
        line = getLine();
    }
    score += cnt * cnt;
    level = score/10 + 1;
}


int Tetris::getScore(){
    return score;
}

int Tetris::getLevel(){
    return level;
}

Block Tetris::getBlock(){
    return block;
}


Block Tetris::getNextBlock(){
    return nextBlock;
}


Block Tetris::getShadowBlock(){
    return shadowBlock;
}


bool Tetris::getBox(int x, int y){
    return box[x][y];
}
