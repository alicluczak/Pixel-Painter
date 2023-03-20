#pragma once
#ifndef BUCKET_H
#define BUCKET_H

#endif // BUCKET_H
#include "Tool.h"

class Bucket : public Tool{
    vector<point> directions={{0,0},{1,0},{-1,0},{0,1},{0,-1}};
    void fill(int x,int y, QColor color, Board &board);
public:
    void use(Board &board, QPointF points, ColorPalette &colorPalette);
};
