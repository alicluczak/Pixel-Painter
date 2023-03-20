#pragma once
#ifndef MAGNIFIER_H
#define MAGNIFIER_H

#endif
#include "Tool.h"

class Magnifier : public Tool{
public:
    void use(Board &board, QPointF point, ColorPalette &colorPalette) ;
};
