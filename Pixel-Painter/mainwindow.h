#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Brush.h"
#include "Eraser.h"
#include "Bucket.h"
#include "ColorPalette.h"
#include <QMouseEvent>
#include <QVBoxLayout>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnBrush_clicked();
    void on_sldCellsNumber_valueChanged(int value);
    void on_btnEraser_clicked();
    void on_btnBucked_clicked();
    void on_btnClear_clicked();
    void on_btnSave_clicked();
    void on_btnExport_clicked();
    void on_btnOpen_clicked();

private:
    Ui::MainWindow *ui;
    Board *board = new Board();
    Tool *tool= new Brush();
    ColorPalette *colorPalette = new ColorPalette(this);
protected:
    void mousePressEvent(QMouseEvent *event);
};
#endif // MAINWINDOW_H
