#include "Bucket.h"

void Bucket::use(Board &board, QPointF points, ColorPalette &colorPalette){
    int x,y;
    int cellSize=board.getCellSize();
    x=points.x()/cellSize;
    y=points.y()/cellSize;
    int index= (board.getCellsNumber()*x)+y;

    QColor newColor=colorPalette.currentColor();
    if(x < board.getCellsNumber() && y < board.getCellsNumber() && index < board.getPointList().size() && points.x() >0 && points.y()> 0){
        QColor oldColor=board.getColorOfPoint({x,y});
        vector<point> queue;
        queue.push_back({x,y});
        while(!queue.empty()){
            point tempPoint=queue.back();
            queue.pop_back();
            for(point direction:directions){
                if(board.getColorOfPoint({tempPoint.x+direction.x,tempPoint.y+direction.y}) != newColor
                        && board.getColorOfPoint({tempPoint.x+direction.x,tempPoint.y+direction.y}) == oldColor
                        && tempPoint.x+direction.x>=0
                        && tempPoint.y+direction.y>=0
                        && tempPoint.x+direction.x < board.getCellsNumber()
                        && tempPoint.y+direction.y < board.getCellsNumber()
                        ){
                    fill(tempPoint.x+direction.x,tempPoint.y+direction.y,newColor,board);
                    queue.push_back({tempPoint.x+direction.x,tempPoint.y+direction.y});
                }
            }
        }

    }
}

void Bucket::fill(int x,int y, QColor color, Board &board){
    int index = (board.getCellsNumber()*(x))+(y);
    board.setColor(color, index);
    board.setFilled(true,index);
}
