#include "Eraser.h"
#include "QDebug"

void Eraser::use(Board &board, QPointF point,ColorPalette &colorPalette){
    int x,y;
    int cellSize=board.getCellSize();
    x=point.x()/cellSize;
    y=point.y()/cellSize;
    int index= (board.getCellsNumber()*x)+y;
    QColor color(Qt::white);
    if(x<board.getCellsNumber() && y < board.getCellsNumber() && index<board.getPointList().size() && point.x() >0 && point.y()> 0){
        board.setColor(color, index);
    }
}
