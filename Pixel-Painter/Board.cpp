#include <Board.h>

void Board::fillTable(){
    pointsList.clear();
    point newPoint;
    for(int x=0;x<cellsNumber;x++){
        for( int y=0;y<cellsNumber;y++){
            newPoint={x,y,Qt::white};
            this->pointsList.push_back(newPoint);
            }
    }
}

void Board::resizeTable(int newSize){
    std::vector<point> tempPointList;
    for(int i=0;i<pointsList.size();i++){
        tempPointList.push_back(pointsList[i]);
    }
    pointsList.clear();
    fillTable();
    if((newSize*newSize)>tempPointList.size()){
    for(int i=0;i<tempPointList.size();i++){
        if(tempPointList[i].isFilled){
            point point;
            point.x=tempPointList[i].x;
            point.y=tempPointList[i].y;
            int index=getIndexOfPoint(point);
            pointsList[index].color=tempPointList[i].color;
            pointsList[index].isFilled=tempPointList[i].isFilled;
        }
    }
    }
    else{
        for(int i=0;i<pointsList.size();i++){
            point point;
            point.x=tempPointList[i].x;
            point.y=tempPointList[i].y;
            if(point.x<cellsNumber && point.y<cellsNumber){
            int index=getIndexOfPoint(point);
            pointsList[index].color=tempPointList[i].color;
            pointsList[index].isFilled=tempPointList[i].isFilled;
            }
        }
    }
}

void Board::createBoard(QGraphicsView *graphicBoard){
    double scale = graphicBoard->transform().m11();
    QPointF previousCenter = graphicBoard->mapToScene(graphicBoard->viewport()->rect().center());
    scene = new QGraphicsScene();
    graphicBoard->setScene(scene);
    QPen blackpen(Qt::darkGray);
    int windowSize=600;
    cellSize=windowSize/cellsNumber;
    setCellSize(cellSize);
    for(int sizeX=0; sizeX<cellsNumber; sizeX++){
        for(int sizeY=0; sizeY<cellsNumber; sizeY++){
         QColor color(getColorOfPoint({sizeX, sizeY}));
         scene->addRect(sizeX*cellSize, sizeY*cellSize, cellSize, cellSize, blackpen, color);
        }
    }
    graphicBoard->resetTransform();
    graphicBoard->scale(scale, scale);
    graphicBoard->centerOn(previousCenter);
}

int Board::getCellSize(){
    return cellSize;
}

int Board::getCellsNumber(){
    return cellsNumber;
}

std::vector<point> Board::getPointList(){
    return pointsList;
}

QColor Board::getColorOfPoint(point point){
        QColor color=Qt::white;
        for(int index=0; index<pointsList.size(); index++){
            if(point.x==pointsList[index].x && point.y==pointsList[index].y){
                color=pointsList[index].color;
                }
            }
        return color;
}

int Board::getIndexOfPoint(point point){
    int pointIndex=0;
    for(int index=0; index<pointsList.size(); index++){
        if(point.x==pointsList[index].x && point.y==pointsList[index].y){
            pointIndex=index;
            }
        }
    return pointIndex;
}

void Board::setColor(QColor color, int index){
    pointsList[index].color = color;
}

void Board::setFilled(bool isFilled,int index){
    pointsList[index].isFilled=isFilled;
}

void Board::wheelEvent(QWheelEvent *event)
{
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    double scaleFactor=1.15;
    if(event->angleDelta().y()>0){
        scale(scaleFactor,scaleFactor);
    }
    else{
        scale(1/scaleFactor, 1/scaleFactor);
    }
}

void Board::setCellsNumber(int cellsNumber){
    this->cellsNumber=cellsNumber;
    resizeTable(cellsNumber);
}

void Board::setCellSize(int cellSize){
    this->cellSize = cellSize;
}

void Board::exportToFile(){
    if(scene!=nullptr){
        for(int sizeX=0; sizeX<cellsNumber; sizeX++){
            for(int sizeY=0; sizeY<cellsNumber; sizeY++){
                QColor color(getColorOfPoint({sizeX, sizeY}));
                scene->addRect(sizeX*cellSize, sizeY*cellSize, cellSize, cellSize, QPen(Qt::transparent), color);
            }
        }
        QImage image(scene->sceneRect().size().toSize(), QImage::Format_ARGB32);
        image.fill(Qt::transparent);
        QPainter painter(&image);
        scene->render(&painter);
        QPen blackpen1(Qt::darkGray);
        for(int sizeX=0; sizeX<cellsNumber; sizeX++){
            for(int sizeY=0; sizeY<cellsNumber; sizeY++){
                QColor color(getColorOfPoint({sizeX, sizeY}));
                scene->addRect(sizeX*cellSize, sizeY*cellSize, cellSize, cellSize, blackpen1, color);
            }
        }
        QString fileName = QFileDialog::getSaveFileName(0, "Save Image", "", "*.jpg;;*.png");
        if(!fileName.isEmpty()) {
            image.save(fileName);
        }
    }
}

void Board::save(){
    QString fileName = QFileDialog::getSaveFileName(0, "Save File", "", "*.txt");
    if(!fileName.isEmpty()){
        ofstream file(fileName.toStdString());
        file << getCellsNumber() << endl;
        for(int i=0; i<pointsList.size(); i++){
            file <<pointsList[i].x <<" ";
            file <<pointsList[i].y <<" ";
            file <<pointsList[i].color.red() << " ";
            file <<pointsList[i].color.green() << " ";
            file <<pointsList[i].color.blue() << " ";
            file <<pointsList[i].isFilled << endl;
            }
        file.close();
        }
}
void Board::open(){
    QString fileName = QFileDialog::getOpenFileName(0, "Open File", "", "*.txt");
    if(!fileName.isEmpty()){
        pointsList.clear();
        int x,y,r,g,b,cellsNumbers;
        bool isFill;
        std::ifstream file(fileName.toStdString());
        file>>cellsNumbers;
        setCellsNumber(cellsNumbers);
        pointsList.clear();
        for(int i=0;!file.eof();i++){
            file>>x, file>>y, file>>r, file>>g, file>>b, file>>isFill;
            pointsList.push_back({x,y,{r,g,b},isFill});
        }
        file.close();
    }
}


