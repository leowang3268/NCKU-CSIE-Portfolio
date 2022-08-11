#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mappaint.h"
#include <QKeyEvent>
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Sokoban");
    createMenu();
    createAction();
    setCentralWidget(widget);
    connect(restartButton, SIGNAL(clicked()), this, SLOT(restartGameSlot()));
    restartButton->setEnabled(false);
    rightLayout->addWidget(levelLabel);
    rightLayout->addWidget(levelLCD);
    rightLayout->addWidget(stepLabel);
    rightLayout->addWidget(stepLCD);
    rightLayout->addWidget(restartButton);
    rightLayout->addSpacing(210);
    mainLayout->addWidget(mainmap);
    mainLayout->addLayout(rightLayout);
    widget->setLayout(mainLayout);
    mainmap->levelNow = 0;
    mainmap->stepNow = 0;
    mainmap->man_x = 0;
    mainmap->man_y = 0;
    mainmap->BeginOrEnd = 0; //start::quitGame
    mainmap->update();
    boxNum = 0;
    levelLCDShow();
    stepLCDShow();
    createMap();
    widget->setFocus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGameSlot()
{
    mainmap->BeginOrEnd = 1; //start::startForOne
    widget->setFixedSize(mainmap->map_x+150, mainmap->map_y);
    this->setFixedSize(mainmap->map_x+150, mainmap->map_y);
    startGame(0);
}

void MainWindow::startGame(int x)
{
    widget->setFocus();
    quitGameAction->setEnabled(true);
    restartGameAction->setEnabled(true);
    restartButton->setEnabled(true);
    int a = 0, b = 0;
    findManPos(x, a, b);
    mainmap->man_x = a;
    mainmap->man_y = b;
    boxNum = 0;
    mainmap->mapNow.resize(map[x].size());
    for(int i=0; i<map[x].size(); i++)
        (mainmap->mapNow)[i].resize(map[x][i].size());

    for(int i=0; i<map[x].size(); i++)
        for(int j=0; j<map[x][i].size(); j++)
            mainmap->mapNow[i][j] = map[x][i][j];
    mainmap->mapNow[mainmap->man_x][mainmap->man_y] = GROUND;
    mainmap->levelNow = x;
    mainmap->stepNow = 0;
    stepLCDShow();
    levelLCDShow();
    mainmap->update();
    levelLCDShow();
}

void MainWindow::findManPos(int x, int& man_x, int& man_y)
{
    for(int i=0; i<map[x].size(); i++)
        for(int j=0; j<map[x][i].size(); j++)
            if(map[x][i][j] == MAN)
            {
                man_x = i;
                man_y = j;
            }
}

void MainWindow::restartGameSlot()
{
    startGame(mainmap->levelNow);
}

void MainWindow::quitGameSlot()
{
    quitGameAction->setEnabled(false);
    restartButton->setEnabled(false);
    restartGameAction->setEnabled(false);
    mainmap->levelNow = 0;
    mainmap->stepNow = 0;
    boxNum = 0;
    mainmap->BeginOrEnd = 0;
    levelLCDShow();
    stepLCDShow();
    widget->setFixedSize(mainmap->map_x+150,mainmap->map_y);
    this->setFixedSize(mainmap->map_x+150,mainmap->map_y);
    mainmap->update();
}

void MainWindow::chooseLevelSlot()
{
    resize(200,100);
    bool ok;
    int value =
            QInputDialog::getInt(this, tr("Number of Levels"), tr("Please choose level"), 1, 1, 2, 1, &ok);
    if(ok)
    {
        if(mainmap->BeginOrEnd==0)
            mainmap->BeginOrEnd = 1;
        startGame(value-1);
    }
}

void MainWindow::createMenu()
{
    connect(startGameAction, SIGNAL(triggered()), this, SLOT(startGameSlot()));
    restartGameAction->setEnabled(false);
    connect(restartGameAction, SIGNAL(triggered()), this, SLOT(restartGameSlot()));
    quitGameAction->setEnabled(false);
    connect(quitGameAction, SIGNAL(triggered()), this, SLOT(quitGameSlot()));
    connect(chooseLevelAction, SIGNAL(triggered()), this, SLOT(chooseLevelSlot()));
}

void MainWindow::createAction()
{
    gameMenu = menuBar()->addMenu(QStringLiteral("Game"));
    gameMenu->addAction(startGameAction);
    gameMenu->addAction(restartGameAction);
    gameMenu->addAction(quitGameAction);
    levelMenu = menuBar()->addMenu(QStringLiteral("Level"));
    levelMenu->addAction(chooseLevelAction);
}

void MainWindow::createMap()
{
    int i, j;

    //level 1
    man[0][0] = 8;
    man[0][1] = 7;
    box[0]=3;
    for(i=0;i<12;i++)
        for(j=0;j<12;j++)
        {
            map[0][i][j] = GROUND; //initialize
            map[0][4][4] = WALL; map[0][4][8] = WALL;
            map[0][8][4] = WALL; map[0][8][8] = WALL;
            map[0][7][7] = BOX; map[0][7][8] = BOX;
            map[0][8][6] = BOX;
        }
    //level 2
    man[1][0] = 6;
    man[1][1] = 9;
    box[1]=3;
    for(i=0;i<12;i++)
        for(j=0;j<12;j++)
        {
            map[1][i][j] = GROUND; //initialize
            map[1][4][10] = WALL; map[1][4][11] = WALL;
            map[1][5][5] = WALL; map[1][5][6] = WALL;
            map[1][6][5] = WALL; map[1][6][6] = WALL;
            map[1][6][7] = WALL; map[1][6][10] = WALL;
            map[1][7][7] = WALL; map[1][7][5] = WALL;
            map[1][7][6] = WALL; map[1][8][7] = WALL;
            map[1][9][6] = WALL; map[1][9][7] = WALL;
            map[1][10][6] = WALL; map[1][10][7] = GOAL;
            map[1][10][8] = GOAL; map[1][10][9] = GOAL;
            map[1][5][9] = BOX; map[1][5][10] = BOX;
            map[1][6][8] = BOX;
        }
}



void MainWindow::levelLCDShow()
{
    levelLCD->display(mainmap->levelNow);
}

void MainWindow::stepLCDShow()
{
    stepLCD->display(mainmap->stepNow);
}

//moving stategy

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(!(mainmap->levelNow==0))
    {
        switch(event->key())
        {
            case Qt::Key_Up: keyUp();break;
            case Qt::Key_Left: keyLeft();break;
            case Qt::Key_Right: keyRight();break;
            case Qt::Key_Down: keyDown();break;
            default: break;
        }
    }
}

void MainWindow::keyUp()
{
    int manx = mainmap->man_x;
    int many = mainmap->man_y;
    if(manx-1<0 || mainmap->mapNow[manx-1][many]==WALL)
        return;

    if(mainmap->mapNow[manx-1][many]==GROUND ||
            mainmap->mapNow[manx-1][many]==GOAL)
    {
        mainmap->man_x--;
        if(map[mainmap->levelNow][manx][many]==BOX ||
                map[mainmap->levelNow][manx][many]==MAN)
            mainmap->mapNow[manx][many]=GROUND;
        else
            mainmap->mapNow[manx][many] =
                    map[mainmap->levelNow][manx][many];
    }

    if(mainmap->mapNow[manx-1][many]==BOX)
    {
        if(manx-2<0 || mainmap->mapNow[manx-2][many]==BOX ||
                mainmap->mapNow[manx-2][many]==WALL)
            return;

        if(mainmap->mapNow[manx-2][many]==GROUND)
        {
            if(map[mainmap->levelNow][manx-1][many]==GOAL)
                boxNum--;

            mainmap->mapNow[manx-2][many] = BOX;

            if(map[mainmap->levelNow][manx][many]==BOX ||
                    map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many] = GROUND;
            else
                mainmap->mapNow[manx][many] =
                        map[mainmap->levelNow][manx][many];


            mainmap->man_x--;
        }
        if(mainmap->mapNow[manx-2][many]==GOAL)
        {
            if(map[mainmap->levelNow][manx-1][many]!=GOAL)
                boxNum++;

            if(map[mainmap->levelNow][manx][many]==BOX ||
                    map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many]=GROUND;
            else
                mainmap->mapNow[manx][many] =
                        map[mainmap->levelNow][manx][many];

            mainmap->mapNow[manx-2][many] = BOX;

            if(map[mainmap->levelNow][manx][many]==BOX ||
                    map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many] = GROUND;
            else
                mainmap->mapNow[manx][many] =
                        map[mainmap->levelNow][manx-1][many];

            mainmap->man_x--;
        }
    }
    mainmap->stepNow++;
    stepLCDShow();
    mainmap->update();
    boxNumCheck();
}

void MainWindow::keyDown()
{
    int manx = mainmap->man_x;
    int many = mainmap->man_y;
    if(manx+1>mainmap->mapNow[0].size() ||
            mainmap->mapNow[manx+1][many]==WALL)
        return;

    if(mainmap->mapNow[manx+1][many]==GROUND ||
            mainmap->mapNow[manx+1][many]==GOAL)
    {

        mainmap->man_x++;

        if(map[mainmap->levelNow][manx][many]==BOX ||
                 map[mainmap->levelNow][manx][many]==MAN)
            mainmap->mapNow[manx][many] = GROUND;
        else
            mainmap->mapNow[manx][many] =
                    map[mainmap->levelNow][manx][many];
    }

    if(mainmap->mapNow[manx+1][many]==BOX)
    {
        if(manx+2>mainmap->mapNow[0].size() ||
                mainmap->mapNow[manx+2][many]==BOX ||
                mainmap->mapNow[manx+2][many]==WALL)
            return;

        if(mainmap->mapNow[manx+2][many]==GROUND)
        {
            if(map[mainmap->levelNow][manx+1][many]==GOAL)
                boxNum--;

            mainmap->mapNow[manx+2][many] = BOX;

            if(map[mainmap->levelNow][manx][many]==BOX ||
                    map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many] = GROUND;

            else
                mainmap->mapNow[manx][many] =
                        map[mainmap->levelNow][manx][many];

            mainmap->man_x++;
        }

        if(mainmap->mapNow[manx+2][many]==GOAL)
        {
            if(map[mainmap->levelNow][manx+1][many]!=GOAL)
                boxNum++;

            if(map[mainmap->levelNow][manx][many]==BOX ||
                    map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many] = GROUND;
            else
                mainmap->mapNow[manx][many] =
                    map[mainmap->levelNow][manx][many];

            mainmap->mapNow[manx+2][many] = BOX;

            if(map[mainmap->levelNow][manx][many]==BOX ||
               map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many] = GROUND;
            else
                mainmap->mapNow[manx][many] =
                    map[mainmap->levelNow][manx][many];

            mainmap->man_x++;
        }
    }
    mainmap->stepNow++;
    stepLCDShow();
    mainmap->update();
    boxNumCheck();
}

void MainWindow::keyLeft()
{
    int manx = mainmap->man_x;
    int many = mainmap->man_y;

    if(many-1<0 || mainmap->mapNow[manx][many-1]==WALL)
        return;

    if(mainmap->mapNow[manx][many-1]==GROUND ||
            mainmap->mapNow[manx][many-1]==GOAL)
    {
        mainmap->man_y--;
        if(map[mainmap->levelNow][manx][many]==BOX)
            mainmap->mapNow[manx][many] = GROUND;
        else
            mainmap->mapNow[manx][many] =
                    map[mainmap->levelNow][manx][many];
    }

    if(mainmap->mapNow[manx][many-1]==BOX)
    {
        if(many-2<0 || mainmap->mapNow[manx][many-2]==BOX ||
                mainmap->mapNow[manx][many-2]==WALL)
            return;

        if(mainmap->mapNow[manx][many-2]==GROUND)
        {
            if(map[mainmap->levelNow][manx][many-1]==GOAL)
                boxNum--;

            mainmap->mapNow[manx][many-2] = BOX;

            if(map[mainmap->levelNow][manx][many]==BOX ||
                    map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many] = GROUND;
            else
                mainmap->mapNow[manx][many] =
                        map[mainmap->levelNow][manx][many];


            mainmap->man_y--;
        }

        if(mainmap->mapNow[manx][many-2]==GOAL)
        {
            if(map[mainmap->levelNow][manx][many-1]!=GOAL)
                boxNum++;

            if(map[mainmap->levelNow][manx][many]==BOX ||
                    map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many] = GROUND;
            else
                mainmap->mapNow[manx][many] =
                        map[mainmap->levelNow][manx][many];

            mainmap->mapNow[manx][many-2] = BOX;

            if(map[mainmap->levelNow][manx][many]==BOX ||
                    map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many] = GROUND;
            else
                mainmap->mapNow[manx][many] =
                        map[mainmap->levelNow][manx][many];

            mainmap->man_y--;
        }
    }
    mainmap->stepNow++;
    stepLCDShow();
    mainmap->update();
    boxNumCheck();
}

void MainWindow::keyRight()
{
    int manx = mainmap->man_x;
    int many = mainmap->man_y;
    if(many+1>mainmap->mapNow[0].size() ||
            mainmap->mapNow[manx][many+1]==WALL)
        return;

    if(mainmap->mapNow[manx][many+1]==GROUND ||
            mainmap->mapNow[manx][many+1]==GOAL)
    {
        mainmap->man_y++;

        if(map[mainmap->levelNow][manx][many]==BOX ||
            map[mainmap->levelNow][manx][many]==MAN)
            mainmap->mapNow[manx][many]=GROUND;
        else
            mainmap->mapNow[manx][many] =
                    map[mainmap->levelNow][manx][many];
    }

    if(mainmap->mapNow[manx][many+1]==BOX)
    {
        if(many+2>mainmap->mapNow[0].size() ||
            mainmap->mapNow[manx][many+2]==BOX ||
            mainmap->mapNow[manx][many+2]==WALL)
            return;

        if(mainmap->mapNow[manx][many+2]==GROUND)
        {
            if(map[mainmap->levelNow][manx][many+1]==GOAL)
                boxNum--;

            mainmap->mapNow[manx][many+2] = BOX;

            if(map[mainmap->levelNow][manx][many]==BOX ||
                map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many] = GROUND;
            else
                mainmap->mapNow[manx][many] =
                    map[mainmap->levelNow][manx][many];

            mainmap->man_y++;
        }

        if(mainmap->mapNow[manx][many+2]==GOAL)
        {
            if(map[mainmap->levelNow][manx][many+1]!=GOAL)
                boxNum++;

            if(map[mainmap->levelNow][manx][many]==BOX ||
                    map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many] = GROUND;
            else
                mainmap->mapNow[manx][many] =
                        map[mainmap->levelNow][manx][many];

            mainmap->mapNow[manx][many+2] = BOX;

            if(map[mainmap->levelNow][manx][many]==BOX ||
                    map[mainmap->levelNow][manx][many]==MAN)
                mainmap->mapNow[manx][many] = GROUND;
            else
                mainmap->mapNow[manx][many] =
                        map[mainmap->levelNow][manx][many];

            mainmap->man_y++;
        }
    }
    mainmap->stepNow++;
    stepLCDShow();
    mainmap->update();
    boxNumCheck();
}

void MainWindow::boxNumCheck()
{
    if(boxNum==box[mainmap->levelNow])
    {
        quitGameAction->setEnabled(false);
        restartGameAction->setEnabled(false);
        restartButton->setEnabled(false);
        if(mainmap->levelNow==map.size())
        {
            QMessageBox::information(this, QStringLiteral("Congrats"), QStringLiteral("Congrats to pass all the level!")
                                     , QMessageBox::Ok);
            mainmap->levelNow = 0;
            mainmap->stepNow = 0;
            boxNum = 0;
            levelLCDShow();
            stepLCDShow();
            mainmap->BeginOrEnd = 1;
            mainmap->update();
        }
        else
        {
            QMessageBox::information(this, QStringLiteral("Congrats"), QStringLiteral("Congrats to pass the level! "
                                                         "Let's go to the next level!")
                                     , QMessageBox::Ok);
            startGame(mainmap->levelNow+1);
        }
    }
}
