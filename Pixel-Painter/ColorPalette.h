#pragma once
#ifndef COLORPALETTE_H
#define COLORPALETTE_H
#include <QColorDialog>
#endif // COLORPALETTE_H

class ColorPalette : public QColorDialog{
public:

    ColorPalette(QWidget *parent = nullptr) : QColorDialog(parent) {}
};
