#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QLabel>
#include <QMessageBox>
#include "box.h"
#include "nextbox.h"

const int STATUS_ON = 0;//游戏进行
const int STATUS_PAUSE = 1;//游戏暂停
const int STATUS_OFF = 2;//游戏未开始
const int STATUS_END = 3;//游戏结束

class MainWindow: public QMainWindow{
        Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();
        void keyPressEvent(QKeyEvent *event);
        void updateScore();
        void updateLevel();


    public slots:
        void onTimer();


    private:
        int status;
        QTimer *timer;

        Tetris tetris;
        Box *box;
        NextBox *nextBox;
        QLabel *nextLabel;

        QLabel *scoreTitleLabel;
        QLabel *scoreLabel;
        QLabel *levelTitleLabel;
        QLabel *levelLabel;

        QLabel *controlLabel;
        QLabel *upLabel;
        QLabel *downLabel;
        QLabel *leftLabel;
        QLabel *rightLabel;
        QLabel *spaceLabel;
        QLabel *escLabel;
        QLabel *renewLabel;
};

#endif // MAINWINDOW_H
