# Tetris

## 题目：   俄罗斯方块                  

## 实验环境：  Qt 5.9.8                  

## 内容：

点击“源文件”文件夹下的“运行程序”文件夹下的tetris.exe文件运行程序。

如左图所示，这是我设计的俄罗斯方块游戏的开始界面。开始时页面静止，需要按键盘的Space键才能开始游戏。界面左侧为20*10的游戏空间，并且画出网格，方便玩家识别出该图形所在行数和列数。界面右侧有下一个出现的图形，方便玩家思考下一个图形存放的位置。游戏默认从得分为0分、等级为1和下落速度为1000ms开始。此外，下方还有按键提示，方便玩家阅读——按Left（Right）方块左（右）移，按Down加速下移，Esc退出游戏，F5重新开始游戏；按键盘Space使游戏开始，如中间图所示。每种图形有不同的颜色，直至不能下落图形颜色变为白色，而且图形下落可以看到即将落到的最下方位置，有助于提高玩家的游戏体验。此外，按Space键还可以暂停游戏并且标题改为PAUSE!，使游戏更具人性。消除n行得到n＊n分，随着得分每增加10分，等级增加1级，图形下落速度加快100毫秒，当速度变为200毫秒时不再加快（再快就玩不下去了）；当图形堆叠到游戏区域最顶端时，游戏结束，如右图所示，并出现提示框显示玩家分数和等级。关闭提示框，再按Space键时游戏重新开始。

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps1.jpg)![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps2.jpg)![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps3.jpg) 

## 过程：

设计思路：

我设计了Block类、Tetris类、Box类、NextBox类和MainWindow类这五个类。其中：Block类用来存储每种图形的信息，用id来区分图形的种类——x[4],y[4]分别用来存储每个图形四个方格的初始横纵坐标，id用来存储图形的种类，centerX和centerY分别用来存储图形的初始中心横纵坐标，color用来存储这种图形的颜色；然后Tetris类用来存储一次游戏中的信息——block用来存储正在移动中的图形的信息，nextBlock用来存储下一出现的图形的信息，shadowBlock用来存储图形即将落到的最下方位置，box[10][20]用来存储游戏区间已有方格的位置，score用来存储分数，level用来存储等级；然后Box类继承QWidget类（空窗口类）用来显示游戏的方块；NextBox类继承QWidge类用来显示下一个方块；最后MainWindow类继承于QMainWindow类（主窗口类）用来整合box、nextbox和控制提示和分数的显示用的QLabel控件。

程序模块结构图：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps4.jpg) 

## 实现过程：

1、Block类

Block类中含有Block()构造函数，创造图形类型的create()函数，数据清空的clear()函数，以及设置（set）和获取（get）私有成员信息的各种set和get函数。

·其中create()函数实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps5.jpg) 

2、Tetris类

Tetris类中有Tetris()构造函数，初始化init()函数，创造当前图形的createBlock()函数，创造下一个图形的createNextBlock()函数，创造当前位置图形即将落到最下方位置的图形的createShadowBlock()函数，判断图形是否能向右移动dx格、向下移动dy格（若能则图形移动）的move(int dx, int dy)函数，判断是否能向左移动1格（若能，则图形移动）的moveLeft()函数，判断是否能向右移动1格（若能，则图形移动）的moveRight()函数，判断是否能向下移动1格（若能，则图形移动）的moveDown()函数，判断图形能否旋转（若能，则图形显示旋转）的rotate()函数，判断游戏是否结束的gameOver()函数，得到第一行方格都被填满的行的getLine()函数，消除满行的killLines()函数，以及获取（get）私有成员信息的各种get函数。

·init()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps6.jpg) 

·createBlock()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps7.jpg) 

·createNextBlock()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps8.jpg) 

·createShadowBlock()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps9.jpg) 

·move(int dx, int dy)函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps10.jpg) 

·moveDown()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps11.jpg) 

·rotate()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps12.jpg) 

·gameOver()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps13.jpg) 

·getLine()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps14.jpg) 

·killLines()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps15.jpg) 

3、Box类

Box类继承于Qt自带的QWidget类，含有Box(QWidget *parent = nullptr)构造函数，更新游戏框内数据和视图的updateTetris(Tetris tetris)函数，绘制游戏运行框内视图的paintEvent(QPaintEvent *event)函数。

·updateTetris(Tetris tetris)函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps16.jpg) 

·paintEvent(QPaintEvent *event)函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps17.jpg) 

4、NextBox类

NextBox类继承于Qt自带的QWidget类，含有NextBox(QWidget *parent = nullptr)构造函数，更新“下一个图形”框内的数据和视图的updateNextTetris(Tetris tetris)函数，绘制“下一个图形”框内视图的paintEvent(QPaintEvent *event)函数。

·updateNextTetris(Tetris tetris)函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps18.jpg) 

·paintEvent(QPaintEvent *event)函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps19.jpg) 

5、MainWindow类

MainWindow类继承于Qt自带的QMainWindow类，含有用来构造初始游戏界的面MainWindow(QWidget *parent = 0)构造函数，~MainWindow()析构函数，响应键盘事件的keyPressEvent(QKeyEvent *event)函数，更新分数的updateScore()函数、更新等级的updataeLevel()函数，用来设置时间的onTimer()槽函数。

·keyPressEvent(QKeyEvent *event)函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps20.jpg) 

·onTimer()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps21.jpg) 

·updateScore()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps22.jpg) 

·updateLevel()函数的实现如下图所示：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps23.jpg) 

6、main函数

创建一个变量名为w的MainWindow类，让它显示，即执行w.show()代码，便可运行。

 

## 结果：

点击“源文件”文件夹下的“运行程序”文件夹下的tetris.exe文件便能直接运行。

1、刚打开时的俄罗斯方块游戏的开始界面：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps24.jpg) 

2、按Space键，游戏开始，下图为正在运行的游戏界面：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps25.jpg) 

3、按Space键，暂停时的游戏界面：（标题会变为PAUSE!）

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps26.png)

4、再次按Space键，游戏继续：（标题又变为tetris）

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps27.png)![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps28.png)

5、旋转：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps29.jpg)![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps30.jpg) 

6、左右移动：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps31.jpg)![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps32.jpg)![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps33.jpg) 

7、结束时的游戏界面：

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps34.jpg) 

## 分析：

1、问题：

·问题1：不了解如何使用Qt进行C++的编程。

解决方法：上网查找相关书籍以及文献，例如《C++ GUI Qt4 编程》、《Qt5开发及实例》等。通过阅读书籍之后，先写一些简单的程序，等熟练掌握之后，再进行俄罗斯方块的编程。

·问题2：不知道如何去构建哪些类，以及类与类之间应该通过哪些方式来建立联系。

解决方法：先去画思维程序模块结构图以及核心算法的流程图，再通过结构图和流程图明确任务该如何实现，需要哪些函数以及这些函数应该做什么。

·问题3：程序运行时出现程序异常结束。

解决方法：当程序编译通过并且没有报错，然而程序却没有运行起来，这个时候的错误大多属于链接库文件错误。我一般采取以下措施：（1）debug模式下使用了release版本的库或者release模式下使用了debug版本的库；（2）在pro文件中对lib库的路径指明错误，即使用到了一些除了Qt以外的其他库，但是编译程序的时候程序找不到那个库。

 

心得体会：

通过本次大作业俄罗斯方块游戏的开发，我从一个对C++编程懵懂的学生到现在可以熟练使用C++来进行简单程序的设计与编写。

首先，这次大作业，使我对C++面向对象的编程有了深一步的了解，实验过程中，我遇到了许多的困难，特别是因为大多数的同学还不太适应面向对象的编程风格和思想，看待问题时总是想到用什么结构来实现该功能，而没有将问题看成一个封装的整体来考虑，所以在这次课程设计中我接触、体验了面向对象设计，使得思维在向面过程向面向对象过渡。

其次，它培养了我的耐心。在屡次编译错误的debug过程中，焦躁的我甚至会产生“明朝散发弄扁舟”的想法，然而，当务发现程序出现的问题并加以改正后，我感觉到自己精神得到了升华，有种“挟飞仙以遨游”的舒畅感。而当最终程序运行成功，终稿敲定之时，我感觉自己的耐心与付出获得了回报。

最后，它让我对将来的工作有了一定的了解。通过本次大作业俄罗斯方块游戏的开发，我对以后工作有了一定的了解，大概清楚了C++工程开发师的大概工作。同时，也让我熟练掌握了Qt这个重要的平台，对以后工作也有一定的帮助。

这次的课程设计，使我在今后的工作和学习中，都有了很到的启发。我想，这对于我都是个很好的经验。在这次课程设计实验中，我学到的所有东西都将让我们获益良多，不管是对于以后的学习还是工作、生活。

 

2、英文文献：

(1) C++ Primer, fifth edition, written by Stanley B.Lippman, Josée LaJoie, Barbara E. Moo.

(2) Qt Assistant 5.9.8（MinGW 5.3.0 32-bit）(a Qt software)

Qt自带的一款软件，主要介绍Qt中自带的封装好的类以及其共有成员、保护成员、私有成员、基类等信息，类似于www.cplusplus.com之于C++编程。（例如：下图为QColor类（Qt自带封装的颜色类）的部分函数截图）。

![img](file:///C:\Users\ZHOUZI~1\AppData\Local\Temp\ksohtml2040\wps35.jpg) 

(3) [www.cplusplus.com](http://www.cplusplus.com)

(4) C++ Primer Plus, sixth edition, written by Stephen Prata

(5) [https://getbootstrap.com/docs/5.0/](https://getbootstrap.com/docs/5.0/customize/color)

 

3、通过本门课程的实验和大作业，谈谈自己对软件维护的认识

软件维护是指在软件产品发布后，因修正错误、提升性能或其他属性而进行的软件修改。软件维护类型总起来可分为四种——改正性维护、适应性维护、完善性维护和预防性维护。

C++将数据封装成类，包含公有成员、私有成员和保护成员，其中私有成员和保护成员不能随意被外界所修改，防止不必要的错误；C++还有继承依据另一个类来定义一个类，这使得创建和维护一个应用程序变得更容易，这样做，也达到了重用代码功能和提高执行效率的效果；以及多态，字面意思就是多种形态。当类之间存在层次结构，并且类之间是通过继承关联时，就会用到多态。C++多态意味着调用成员函数时，会根据调用函数的对象的类型来执行不同的函数。正是继承、封装和多态，让C++在软件维护上更有其独特的魅力。