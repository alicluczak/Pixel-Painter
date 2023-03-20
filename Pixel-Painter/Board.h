#pragma once
#ifndef BOARD_H
#define BOARD_H
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QVector"
#include "QWidget"
#include "QtWidgets"
#include"QDebug"
using namespace std;
#include <iostream>
#include <fstream>

struct point{
    int x;
    int y;
    QColor color;
    bool isFilled;
};

class Board : public QGraphicsView{
private:
    int cellsNumber=10;
    int cellSize=0;
    std::vector<point> pointsList;
    double previousScaleFactor = 1.0;
    QGraphicsScene *scene=nullptr;
public:
    Board(QWidget *parent = nullptr) : QGraphicsView(parent) {}
    void createBoard(QGraphicsView *GraphicBoard);
    void open();
    void save();
    void exportToFile();
    void clear();
    void fillTable();
    void setCellsNumber(int cellsNumber);
    void setCellSize(int cellSize);
    std::vector<point> getPointList();
    int getCellSize();
    QColor getColorOfPoint(point point);
    int getIndexOfPoint(point point);
    int getCellsNumber();
    void setColor(QColor color, int index);
    void resizeTable(int newSize);
    void setFilled(bool isFilled,int index);
protected:
    void wheelEvent(QWheelEvent *event) override;
};
#endif // BOARD_H
