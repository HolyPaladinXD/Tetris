#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H
#include "figure.h"

#include <QWidget>

class nextFigure : public QWidget
{
    Q_OBJECT
    Figure* next;
public:
    explicit nextFigure(QWidget *parent = nullptr);
public slots:
    void slotNewGame();
    void slotChangePattern(Figure*);
signals:

protected:
    virtual void paintEvent(QPaintEvent *event);
};

#endif // NEXTFIGURE_H
