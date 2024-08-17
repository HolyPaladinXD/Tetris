#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tetris)
{
    ui->setupUi(this);
    ui->widgetGlass->glassInit();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionGame_Over_triggered()
{
    QMessageBox::about(this,"Game", "GAME OVER");
}


void MainWindow::on_actionOptions_triggered()
{
    QMessageBox::about(this,"Options", "<- move left \n -> move right \n space - down \n key up - change color up \n key down - change color down");
}

