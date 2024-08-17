#include "glass.h"
#include <QDebug>

Glass::Glass(QWidget *parent)
    : QWidget{parent}
{
    //setProperty("rows", 20);
    //setProperty("columns", 12);
    //this->setFixedSize(columns() * W, rows() * W);
    //this->glassInit();
    cur = new Figure();
    gameOn = false;
    next = new Figure();
    score = 0;
}

uint Glass::rows() const
{
    return m_rows;
}

void Glass::setRows(uint newRows)
{
    m_rows = newRows;
}

uint Glass::columns() const
{
    return m_columns;
}

void Glass::setColumns(uint newColumns)
{
    m_columns = newColumns;
}

void Glass::clearGlass(){
    for(uint i = 0; i < m_rows; i++ ){
        for(uint j =0; j < m_columns; j++){
            glassArray[i][j] = emptyCell;
        }
    }
}

void Glass::glassInit(){
    glassArray.resize(m_rows);
    for (uint i=0; i < m_rows; i++)
    {
        glassArray[i].resize(m_columns);
    }
    this->clearGlass();
    setFixedSize(columns() * W, rows() * W);
}

void Glass::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(uint i =0; i < m_rows; i++){
         for(uint j= 0; j < m_columns; j++){
            painter.fillRect(W*j, W*i, W-1,W-1, glassArray[i][j] );
         }
    }
    if(gameOn){
        cur->paintFigure(painter);
    }
}

void Glass::keyPressEvent(QKeyEvent *event)
{
    if(gameOn){
        switch(event->key()){

            case Qt::Key_Left:
            if(cur->position().rx()){
                bool flag = true;
                for(uint i =0; i < 3; i++){
                    if( glassArray[(cur->position().ry() + W*i)/W][cur->position().rx()/W-1] != emptyCell){
                        flag = false;
                    }
                }
                if(flag){
                    cur->changePositionLeft();
                }
            }
            break;

            case Qt::Key_Right:
                if(cur->position().rx() < this->size().width()-W){
                    bool flag = true;
                    for(uint i =0; i < 3; i++){
                        if(glassArray[(cur->position().ry() + W*i)/W][cur->position().rx()/W+1] != emptyCell){
                            flag = false;
                        }
                    }
                    if(flag){
                        cur->changePositionRight();
                    }
                }
                break;

            case Qt::Key_Down:
                cur->rotateColorsDown();
                break;

            case Qt::Key_Up:
                cur->rotateColorsUp();
                break;

            case Qt::Key_Space:{
                while(cur->position().ry()+W*3 != this->size().height() && glassArray[(cur->position().ry() + W*3)/W][cur->position().rx()/W] == emptyCell){
                cur->changePositionDown();
            }
                acceptColors(cur->position().rx()/W, cur->position().ry()/W);


            break;
            }
            default:
                QWidget::keyPressEvent(event);
        }
    }
    else{
        QWidget::keyPressEvent(event);
    }

        this->repaint();

}

void Glass::slotNewGame(){
    score = 0;
    emit setScore(score);
    gameOn = true;
    this->clearGlass();
    this->repaint();
    this->setFocus();
    Figure* tmp = cur;
    cur = next;
    next = tmp;
    emit signalChangePattern(next);
    emit signalSetDisabled(false);
    this->repaint();
    idTimer = this->startTimer(1000);
}

void Glass::acceptColors(uint x , uint y){
    for(uint i =0; i < sizeof(cur->figureColor)/sizeof(cur->figureColor[0]); i++){
        glassArray[y + i][x] = cur->figureColor[i];
    }
    bool checkHor = false;
    bool checkVer = false;
    while(!checkHor || !checkVer){
    this->delRecurrencesVertical(0, checkVer);
    this->delRecurrencesHorizontal(0, checkHor);
    this->checkFinish();
    }

    Figure* tmp = cur;
    cur = next;
    next = tmp;

    cur->m_x= (rand()%(this->m_columns/2)+3) * W;
    cur->m_y = 0;
    next->m_x = 0;
    next->m_y = 0;
    next->makeRandomColors();

    emit setScore(score);
    emit signalChangePattern(next);
    repaint();
}

Glass::~Glass(){
    delete cur;
    delete next;
}


void Glass::timerEvent(QTimerEvent *event)
{   uint newPositionX = cur->position().rx();
    uint newPositionY = cur->position().ry() + W*3;

    if(newPositionY != this->size().height() && glassArray[newPositionY/W][newPositionX/W] == emptyCell){

        cur->changePositionDown();
    }
    else{
        acceptColors(newPositionX/W, (newPositionY-W*3)/W);
    }
    this-> repaint();

}
void Glass::checkFinish(){
    for(uint i =0; i < this->m_columns; i++){
        if(glassArray[0][i] != emptyCell){
            this->gameOn = false;
            this->killTimer(this->idTimer);
            idTimer = 0;
            emit trigger();
            emit signalSetDisabled(true);
            break;
        }
    }
}

void Glass::delRecurrencesHorizontal(uint recursion, bool &check){
    check = true;
    if(recursion  < this->m_rows){
        delRecurrencesHorizontal(recursion+1, check);
    bool tmpAr[this->m_columns];
    for(int i =0; i < this->m_columns;){
        if(glassArray[recursion][i] == emptyCell){
            tmpAr[i] = false;
            i++;
        }
        else{
            QColor tmp = glassArray[recursion][i];
            int count = 1;
            for(int j = i+1; j < this->m_columns; j++){
                if(glassArray[recursion][j] == tmp){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count >= 3){
                int res = i+count;
                while(i < res){
                    tmpAr[i] = true;
                    i++;
                }

            }
            else{
                int res = i+count;
                while(i < res){
                    tmpAr[i] = false;
                    i++;
                }
            }
        }
    }
    for(size_t i =0; i < this->m_columns; i++){
        if(tmpAr[i] == true){
            check = false;
            glassArray[recursion][i] = emptyCell;
            score+=1;
            afterDel(recursion, i);
        }
    }
    }

}

//

void Glass::delRecurrencesVertical(uint recursion, bool &check){
    check = true;
    if(recursion  < this->m_columns){
        delRecurrencesVertical(recursion+1, check);
        bool tmpAr[this->m_rows];
        for(int i =0; i < this->m_rows;){
            if(glassArray[i][recursion] == emptyCell){
                tmpAr[i] = false;
                i++;
            }
            else{
                QColor tmp = glassArray[i][recursion];
                int count = 1;
                for(int j = i+1; j < this->m_rows; j++){
                    if(glassArray[j][recursion] == tmp){
                        count++;
                    }
                    else{
                        break;
                    }
                }
                if(count >= 3){
                    int res = i+count;
                    while(i < res){
                        tmpAr[i] = true;
                        i++;
                    }

                }
                else{
                    int res = i+count;
                    while(i < res){
                        tmpAr[i] = false;
                        i++;
                    }
                }
            }
        }
        for(size_t m =0; m < this->m_rows; m++){
            if(tmpAr[m] == true){
                check = false;
                glassArray[m][recursion] = emptyCell;
                score+=1;
                afterDel(m, recursion);
            }
        }
    }
}

void Glass::afterDel(uint row_number, uint column_number){
    uint finish = row_number;
    uint start = 0;
    uint fall = 0;

    while(glassArray[finish][column_number] == emptyCell && finish  > 0){ //ищем конец "фигуры"
        finish--;
    }

    if(finish){
        fall = m_rows-1;;
        while(glassArray[fall][column_number] != emptyCell && fall  > finish){ //ищем куда опустить "фигуру"
        fall--;
    }
    }

    if(finish){
    start = finish ;
     while(glassArray[start-1][column_number] != emptyCell){ //ищем начало "фигуры"
         start--;
     }
    }

    while(finish < fall){
     for(int j = finish; j >= start; j--){
        glassArray[j+1][column_number] = glassArray[j][column_number];
    }
     glassArray[start][column_number] = emptyCell;

    finish++;
     start++;
    }
}










