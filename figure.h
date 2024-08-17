#ifndef FIGURE_H
#define FIGURE_H
#include <QColor>
#include <QDebug>
#include <QPainter>

class Figure
{
    QColor figureColor[3];
    const QColor rand_array[4] = {Qt::red, Qt::yellow, Qt::darkGreen, Qt::magenta};
    uint m_x;
    uint m_y;
    uint m_W;
public:
    Figure();
    void makeRandomColors();
    void paintFigure(QPainter&);
    void rotateColorsUp();
    void rotateColorsDown();
    void changePositionRight();
    void changePositionLeft();
    void changePositionDown();
    QPoint position();
    friend class Glass;
    friend class nextFigure;

};

#endif // FIGURE_H
