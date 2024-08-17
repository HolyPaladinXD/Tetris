/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glass.h"
#include "nextfigure.h"

QT_BEGIN_NAMESPACE

class Ui_Tetris
{
public:
    QAction *action_New;
    QAction *action_Close_game;
    QAction *actionControl;
    QAction *actionactionGameOver;
    QAction *actionGame_Over;
    QAction *actionOptions;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *Next;
    nextFigure *widgetNext;
    QSpacerItem *verticalSpacer_3;
    Glass *widgetGlass;
    QVBoxLayout *verticalLayout_2;
    QPushButton *NewGame;
    QPushButton *Exit;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLCDNumber *lcdNumber;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menuGame;
    QMenu *menuOptions;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Tetris)
    {
        if (Tetris->objectName().isEmpty())
            Tetris->setObjectName("Tetris");
        Tetris->resize(460, 450);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Tetris->sizePolicy().hasHeightForWidth());
        Tetris->setSizePolicy(sizePolicy);
        Tetris->setMinimumSize(QSize(0, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/Images/Tetris.png"), QSize(), QIcon::Normal, QIcon::Off);
        Tetris->setWindowIcon(icon);
        action_New = new QAction(Tetris);
        action_New->setObjectName("action_New");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/Images/iconNewGame.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_New->setIcon(icon1);
        action_Close_game = new QAction(Tetris);
        action_Close_game->setObjectName("action_Close_game");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/Images/iconExit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        action_Close_game->setIcon(icon2);
        actionControl = new QAction(Tetris);
        actionControl->setObjectName("actionControl");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/Images/iconInfo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionControl->setIcon(icon3);
        actionactionGameOver = new QAction(Tetris);
        actionactionGameOver->setObjectName("actionactionGameOver");
        actionactionGameOver->setMenuRole(QAction::NoRole);
        actionGame_Over = new QAction(Tetris);
        actionGame_Over->setObjectName("actionGame_Over");
        actionGame_Over->setIcon(icon3);
        actionGame_Over->setMenuRole(QAction::NoRole);
        actionOptions = new QAction(Tetris);
        actionOptions->setObjectName("actionOptions");
        actionOptions->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(Tetris);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        Next = new QLabel(centralwidget);
        Next->setObjectName("Next");
        Next->setMinimumSize(QSize(70, 20));
        Next->setMaximumSize(QSize(70, 20));

        verticalLayout->addWidget(Next);

        widgetNext = new nextFigure(centralwidget);
        widgetNext->setObjectName("widgetNext");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widgetNext->sizePolicy().hasHeightForWidth());
        widgetNext->setSizePolicy(sizePolicy1);
        widgetNext->setMinimumSize(QSize(60, 80));
        widgetNext->setMaximumSize(QSize(60, 80));

        verticalLayout->addWidget(widgetNext);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout);

        widgetGlass = new Glass(centralwidget);
        widgetGlass->setObjectName("widgetGlass");
        sizePolicy.setHeightForWidth(widgetGlass->sizePolicy().hasHeightForWidth());
        widgetGlass->setSizePolicy(sizePolicy);
        widgetGlass->setFocusPolicy(Qt::StrongFocus);
        widgetGlass->setProperty("rows", QVariant(20u));
        widgetGlass->setProperty("columns", QVariant(20u));

        horizontalLayout->addWidget(widgetGlass);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        NewGame = new QPushButton(centralwidget);
        NewGame->setObjectName("NewGame");
        sizePolicy1.setHeightForWidth(NewGame->sizePolicy().hasHeightForWidth());
        NewGame->setSizePolicy(sizePolicy1);
        NewGame->setMinimumSize(QSize(120, 40));
        NewGame->setMaximumSize(QSize(120, 40));
        NewGame->setIcon(icon1);
        NewGame->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(NewGame);

        Exit = new QPushButton(centralwidget);
        Exit->setObjectName("Exit");
        sizePolicy1.setHeightForWidth(Exit->sizePolicy().hasHeightForWidth());
        Exit->setSizePolicy(sizePolicy1);
        Exit->setMinimumSize(QSize(120, 40));
        Exit->setMaximumSize(QSize(80, 40));
        Exit->setIcon(icon2);
        Exit->setIconSize(QSize(32, 32));

        verticalLayout_2->addWidget(Exit);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(120, 10));
        label->setMaximumSize(QSize(120, 10));

        verticalLayout_2->addWidget(label);

        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName("lcdNumber");
        sizePolicy1.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy1);
        lcdNumber->setMinimumSize(QSize(120, 40));
        lcdNumber->setMaximumSize(QSize(120, 40));
        lcdNumber->setSizeIncrement(QSize(0, 0));

        verticalLayout_2->addWidget(lcdNumber);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        Tetris->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Tetris);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 460, 22));
        sizePolicy1.setHeightForWidth(menubar->sizePolicy().hasHeightForWidth());
        menubar->setSizePolicy(sizePolicy1);
        menubar->setMinimumSize(QSize(100, 1));
        menuGame = new QMenu(menubar);
        menuGame->setObjectName("menuGame");
        menuGame->setTearOffEnabled(false);
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName("menuOptions");
        Tetris->setMenuBar(menubar);
        statusbar = new QStatusBar(Tetris);
        statusbar->setObjectName("statusbar");
        Tetris->setStatusBar(statusbar);
        toolBar = new QToolBar(Tetris);
        toolBar->setObjectName("toolBar");
        Tetris->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        menubar->addAction(menuGame->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menuGame->addAction(action_New);
        menuGame->addAction(action_Close_game);
        menuOptions->addAction(actionControl);
        toolBar->addAction(action_Close_game);
        toolBar->addAction(actionControl);
        toolBar->addAction(action_New);

        retranslateUi(Tetris);
        QObject::connect(NewGame, &QPushButton::clicked, widgetGlass, qOverload<>(&Glass::slotNewGame));
        QObject::connect(Exit, &QPushButton::clicked, Tetris, qOverload<>(&QMainWindow::close));
        QObject::connect(widgetGlass, SIGNAL(signalChangePattern(Figure*)), widgetNext, SLOT(slotChangePattern(Figure*)));
        QObject::connect(widgetGlass, SIGNAL(setScore(int)), lcdNumber, SLOT(display(int)));
        QObject::connect(widgetGlass, &Glass::signalNewGame, widgetNext, qOverload<>(&nextFigure::slotNewGame));
        QObject::connect(action_Close_game, &QAction::triggered, Exit, qOverload<>(&QPushButton::click));
        QObject::connect(action_New, &QAction::triggered, NewGame, qOverload<>(&QPushButton::click));
        QObject::connect(widgetGlass, SIGNAL(signalSetDisabled(bool)), NewGame, SLOT(setEnabled(bool)));
        QObject::connect(NewGame, &QPushButton::clicked, action_New, &QAction::setEnabled);
        QObject::connect(widgetGlass, &Glass::trigger, actionGame_Over, qOverload<>(&QAction::trigger));
        QObject::connect(actionControl, &QAction::triggered, actionOptions, qOverload<>(&QAction::trigger));

        QMetaObject::connectSlotsByName(Tetris);
    } // setupUi

    void retranslateUi(QMainWindow *Tetris)
    {
        Tetris->setWindowTitle(QCoreApplication::translate("Tetris", "Tetris", nullptr));
        action_New->setText(QCoreApplication::translate("Tetris", "&New Game", nullptr));
        action_Close_game->setText(QCoreApplication::translate("Tetris", "&Close game", nullptr));
        actionControl->setText(QCoreApplication::translate("Tetris", "Control", nullptr));
        actionactionGameOver->setText(QCoreApplication::translate("Tetris", "actionGameOver", nullptr));
        actionGame_Over->setText(QCoreApplication::translate("Tetris", "Game Over", nullptr));
        actionOptions->setText(QCoreApplication::translate("Tetris", "Options", nullptr));
        Next->setText(QCoreApplication::translate("Tetris", "      Next :", nullptr));
        NewGame->setText(QCoreApplication::translate("Tetris", "New Game", nullptr));
        Exit->setText(QCoreApplication::translate("Tetris", "Exit", nullptr));
        label->setText(QCoreApplication::translate("Tetris", "          Score :", nullptr));
        menuGame->setTitle(QCoreApplication::translate("Tetris", "Game", nullptr));
        menuOptions->setTitle(QCoreApplication::translate("Tetris", "Help", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Tetris", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tetris: public Ui_Tetris {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
