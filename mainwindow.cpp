#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent){
    this->resize(750, 780);

    box = new Box;
    box->setParent(this);
    box->setGeometry(20, 40, 350, 700);

    nextBox = new NextBox;
    nextBox->setParent(this);
    nextBox->setGeometry(480, 90, 150, 150);

    nextLabel = new QLabel(tr("下一个："));
    nextLabel->setParent(this);
    nextLabel->setGeometry(500, 40, 150, 50);

    QFont font("黑体", 20, 100);

    scoreTitleLabel = new QLabel(tr("得分："));
    scoreTitleLabel->setParent(this);
    scoreTitleLabel->setGeometry(440, 260, 150, 50);
    scoreTitleLabel->setFont(font);

    scoreLabel = new QLabel(tr("0"));
    scoreLabel->setParent(this);
    scoreLabel->setGeometry(600, 260, 150, 50);
    scoreLabel->setFont(font);

    levelTitleLabel = new QLabel(tr("等级："));
    levelTitleLabel->setParent(this);
    levelTitleLabel->setGeometry(440, 330, 150, 50);
    levelTitleLabel->setFont(font);

    levelLabel = new QLabel(tr("1"));
    levelLabel->setParent(this);
    levelLabel->setGeometry(600, 330, 150, 50);
    levelLabel->setFont(font);


    controlLabel = new QLabel(tr("按键提示："));
    controlLabel->setParent(this);
    controlLabel->setGeometry(490, 420, 200, 50);

    upLabel = new QLabel(tr("Up-旋转"));
    upLabel->setParent(this);
    upLabel->setGeometry(380, 470, 200, 50);

    downLabel = new QLabel(tr("Down-向下加速"));
    downLabel->setParent(this);
    downLabel->setGeometry(570, 470, 200, 50);

    leftLabel = new QLabel(tr("Left-向左移动"));
    leftLabel->setParent(this);
    leftLabel->setGeometry(380, 520, 200, 50);

    rightLabel = new QLabel(tr("Right-向右移动"));
    rightLabel->setParent(this);
    rightLabel->setGeometry(570, 520, 200, 50);

    spaceLabel = new QLabel(tr("Space-开始/暂停"));
    spaceLabel->setParent(this);
    spaceLabel->setGeometry(460, 570, 200, 50);

    escLabel = new QLabel(tr("Esc-退出游戏"));
    escLabel->setParent(this);
    escLabel->setGeometry(380, 620, 200, 50);

    renewLabel = new QLabel(tr("F5-重新开始"));
    renewLabel->setParent(this);
    renewLabel->setGeometry(570, 620, 200, 50);

    status = STATUS_OFF;
    nextBox->updateNextTetris(tetris);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(onTimer()));
}

MainWindow::~MainWindow(){

}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if (tetris.moveLeft() && status == STATUS_ON){
                box->updateTetris(tetris);
        }
    }else if (event->key() == Qt::Key_Right){
        if (tetris.moveRight() && status == STATUS_ON){
                box->updateTetris(tetris);
        }
    }else if (event->key() == Qt::Key_Up){
        if (tetris.rotate() && status == STATUS_ON){
                box->updateTetris(tetris);
        }
    }else if (event->key() == Qt::Key_Down){
        if (status == STATUS_ON){
            if (tetris.moveDown()){
                box->updateTetris(tetris);
                nextBox->updateNextTetris(tetris);
                updateScore();
                updateLevel();
            }else{
                timer->stop();
                QString s;
                int score = tetris.getScore();
                int level = score/10 + 1;
                s += "Well Done!\n";
                s += QString("Your Score is: %1\n").arg(score);
                s += QString("Your level is: %1!").arg(level);
                QMessageBox::information(this, tr("Game Over"), s);
                status = STATUS_END;
            }
        }
    }else if (event->key() == Qt::Key_Space){
        if (status == STATUS_PAUSE){
            int level = tetris.getLevel();
            if (level < 9){
                timer->start(1100 - level*100);
            }else{
                timer->start(200);
            }
            status = STATUS_ON;
            setWindowTitle(tr("tetris"));
        }else if (status == STATUS_OFF){
            tetris.createBlock();
            box->updateTetris(tetris);
            nextBox->updateNextTetris(tetris);
            updateScore();
            updateLevel();
            int level = tetris.getLevel();
            if (level < 9){
                timer->start(1100 - level*100);
            }else{
                timer->start(200);
            }
            status = STATUS_ON;
        }else if (status == STATUS_END){
            tetris.init();
            tetris.createBlock();
            box->updateTetris(tetris);
            nextBox->updateNextTetris(tetris);
            updateScore();
            int level = tetris.getScore()/10 + 1;
            if (level < 9){
                timer->start(1100 - level*100);
            }else{
                timer->start(200);
            }
            status = STATUS_ON;
        }else if (status == STATUS_ON){
            timer->stop();
            status = STATUS_PAUSE;
            setWindowTitle(tr("PAUSE!"));
        }
    }else if (event->key() == Qt::Key_F5){
        timer->stop();
        tetris.init();
        box->updateTetris(tetris);
        nextBox->updateNextTetris(tetris);
        updateScore();
        updateLevel();
        status = STATUS_OFF;

    }else if (event->key() == Qt::Key_Escape){
        close();
    }

}

void MainWindow::onTimer(){
    if(tetris.moveDown()){
        box->updateTetris(tetris);
        nextBox->updateNextTetris(tetris);
        updateScore();
        updateLevel();
    }else{
        timer->stop();
        QString s;
        int score = tetris.getScore();
        int level = tetris.getLevel();
        s += "Well Done!\n";
        s += QString("Your Score is: %1\n").arg(score);
        s += QString("Your level is: %1!").arg(level);
        QMessageBox::information(this, tr("Game Over"), s);
        status = STATUS_END;
    }
}


void MainWindow::updateScore(){
    QString s;
    int score = tetris.getScore();
    s += QString("%1").arg(score);
    scoreLabel->setText(s);
}

void MainWindow::updateLevel(){
    QString s;
    int level = tetris.getLevel();
    s += QString("%1").arg(level);
    levelLabel->setText(s);
    if (level < 9){
        timer->start(1100 - level*100);
    }else{
        timer->start(200);
    }
}
