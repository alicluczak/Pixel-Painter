#pragma once
#ifndef ERASER_H
#define ERASER_H

#endif // ERASER_H
#include "Tool.h"

class Eraser : public Tool{
public:
    void use(Board &board, QPointF point,ColorPalette &colorPalette);
};
