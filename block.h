#ifndef BLOCK_H
#define BLOCK_H

#include <QColor>

class Block{
    public:
        Block();
        void create();
        void clear();

        void setCenterX(int x);
        void setCenterY(int y);
        void setX(int i, int x);
        void setY(int i, int y);
        void setId(int id);
        void setColor(QColor color);

        int getCenterX();
        int getCenterY();
        int getX(int i);
        int getY(int i);
        int getId();
        QColor getColor();


    private:
        int centerX;
        int centerY;
        int x[4];
        int y[4];
        int id;
        QColor color;
};

#endif // BLOCK_H
