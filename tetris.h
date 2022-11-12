#ifndef TETRIS_H
#define TETRIS_H

#include <time.h>
#include <stdlib.h>
#include "block.h"

class Tetris{
    public:
        Tetris();
        void init();
        void createBlock();
        void createNextBlock();
        void createShadowBlock();

        bool move(int dx, int dy);
        bool moveLeft();
        bool moveRight();
        bool moveDown();
        bool rotate();

        bool gameOver();

        int getLine();
        void killLines();

        int getScore();
        int getLevel();
        Block getBlock();
        Block getNextBlock();
        Block getShadowBlock();
        bool getBox(int x, int y);


    private:
        int score;
        int level;

        Block block;
        Block nextBlock;
        Block shadowBlock;
        bool box[10][20];
};

#endif // TETRIS_H
