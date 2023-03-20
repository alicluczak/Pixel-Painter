#include "Brush.h"
#include "QDebug"

void Brush::use(Board &board, QPointF point, ColorPalette &colorPalette){
    int x,y;
    int cellSize=board.getCellSize();
    x=point.x()/cellSize;
    y=point.y()/cellSize;
    int index= (board.getCellsNumber()*x)+y;
    QColor color= colorPalette.currentColor();
    if(x<board.getCellsNumber() && y < board.getCellsNumber() && index<board.getPointList().size() && point.x() >0 && point.y()> 0){
    board.setColor(color, index);
    board.setFilled(true,index);
    }
}
