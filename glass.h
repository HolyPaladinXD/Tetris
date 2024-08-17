#ifndef GLASS_H
#define GLASS_H
#include <QColor>
#define emptyCell QColor(150,150,150)

#include <QWidget>
#include <QPainter>
#include <QRect>
#include "figure.h"
#include <QKeyEvent>


class Glass : public QWidget
{   Q_OBJECT
    Q_PROPERTY(uint rows READ rows WRITE setRows )
    Q_PROPERTY(uint columns READ columns WRITE setColumns )
    uint m_rows;
    uint m_columns;
    QVector < QVector < QColor > > glassArray;
    const uint W = 20;
    uint timerInterval;
    bool gameOn;
    uint score;


    Figure* cur;
    Figure* next;

    int idTimer = 0;

public:
   explicit Glass(QWidget *parent = nullptr);
    void clearGlass();
    void glassInit();

    uint rows() const;
    void setRows(uint newRows);

    uint columns() const;
    void setColumns(uint newColumns);

    void acceptColors(uint, uint);

    void checkFinish();

    void delRecurrencesVertical(uint, bool&);
    void delRecurrencesHorizontal(uint, bool&);

    void afterDel(uint, uint);


    ~Glass();
signals:
    void signalNewGame();
    void signalChangePattern(Figure*);
    void setScore(int);
    void signalSetDisabled(bool);
    void trigger();
public slots:
    void slotNewGame();

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void timerEvent(QTimerEvent *event);
};

#endif // GLASS_H
