#pragma once
#ifndef BRUSH_H
#define BRUSH_H

#endif // BRUSH_H
#include "Tool.h"
#include <QPoint>
#include <QCursor>
#include "QGraphicsScene"

class Brush : public Tool{
public:
    void use(Board &board, QPointF point, ColorPalette &colorPalette);
};
