#include "figure.h"

Figure::Figure():m_x(0), m_y(0), m_W(20) {
    this->makeRandomColors();
}


void  Figure::makeRandomColors(){
    for(uint i =0; i < 3; i++){
        figureColor[i] = rand_array[rand()%(sizeof(rand_array)/sizeof(rand_array[0]))];
    }
}

void Figure::paintFigure(QPainter& painter){
    for(uint i =0; i < sizeof(figureColor)/sizeof(figureColor[0]); i++){
        painter.fillRect(m_x,m_y+(m_W * i), m_W-1, m_W-1, figureColor[i]);
    }
}

void Figure::rotateColorsUp(){
    QColor tmp = figureColor[0];
    figureColor[0] = figureColor[1];
    figureColor[1] = figureColor[2];
    figureColor[2] = tmp;
}

void Figure::rotateColorsDown(){
    QColor tmp = figureColor[2];
    figureColor[2] = figureColor[1];
    figureColor[1] = figureColor[0];
    figureColor[0] = tmp;
}

void Figure::changePositionRight(){
    m_x += m_W;
}
void Figure::changePositionLeft(){
    m_x -= m_W;
}
QPoint Figure::position(){
    return QPoint(m_x, m_y);
}

void Figure::changePositionDown(){
    m_y += m_W;
}




