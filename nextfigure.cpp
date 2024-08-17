#include "nextfigure.h"
#include <QRect>

nextFigure::nextFigure(QWidget *parent)
    : QWidget{parent}
{
    // next.m_W = 20;
    // next.m_y = 0;
    // next.m_x = 0;
    // for(size_t i =0; i < 3; i++){
    //     next.figureColor[i] = Qt::gray;
    // }
    next = nullptr;
    repaint();
}

void nextFigure::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if(next){
        next->paintFigure(painter);

        //qDebug() << next->m_x << " " << next->m_y;
    }

}

void nextFigure::slotChangePattern(Figure* figure){
    next = figure;
    repaint();
}

void nextFigure::slotNewGame(){
    //next.m_W = 20;
    //next.m_y = 0;
    //next.m_x = 0;
    //for(size_t i =0; i < 3; i++){
       // next.figureColor[i] = Qt::gray;
    //}
    repaint();
}


