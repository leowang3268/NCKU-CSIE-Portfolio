#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mappaint.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QLayout>
#include <vector>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QWidget *widget = new QWidget;
    QLabel *levelLabel = new QLabel(QStringLiteral("Current Level"));
    QLabel *stepLabel = new QLabel(QStringLiteral("Current Steps"));
    QLCDNumber *levelLCD = new QLCDNumber;
    QLCDNumber *stepLCD = new QLCDNumber;
    QPushButton *restartButton = new QPushButton;
    QVBoxLayout *rightLayout = new QVBoxLayout;
    mappaint *mainmap = new mappaint;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QAction *startGameAction = new QAction(QStringLiteral("Start Game"), this);
    QAction *restartGameAction = new QAction(QStringLiteral("Restart Game"), this);
    QAction *quitGameAction = new QAction(QStringLiteral("Quit Game"), this);
    QAction *chooseLevelAction = new QAction(QStringLiteral("Choose Level"), this);
    QMenu *gameMenu;
    QMenu *levelMenu;

    int boxNum;
    int chooseNum;
    std::vector<std::vector<int>> man;
    std::vector<int> box;
    std::vector<std::vector<std::vector<int>>> map;
    void startGame(int x);
    void findManPos(int x, int& man_x, int& man_y);
    void createMenu();
    void createAction();
    void createMap();
    void keyPressEvent(QKeyEvent *event);
    void keyUp();
    void keyDown();
    void keyLeft();
    void keyRight();
    void boxNumCheck();


public slots:
    void startGameSlot();
    void restartGameSlot();
    void quitGameSlot();
    void chooseLevelSlot();
    void levelLCDShow();
    void stepLCDShow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
