#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnBrush->setIcon(QIcon(":/icons/brush.png"));
    ui->btnBrush->setIconSize(QSize(60, 60));

    ui->btnEraser->setIcon(QIcon(":/icons/eraser.png"));
    ui->btnEraser->setIconSize(QSize(60, 60));

    ui->btnBucked->setIcon(QIcon(":/icons/bucket.png"));
    ui->btnBucked->setIconSize(QSize(60, 60));

    ui->btnClear->setIcon(QIcon(":/icons/clear.png"));
    ui->btnClear->setIconSize(QSize(60, 60));

    ui->btnSave->setIcon(QIcon(":/icons/save.png"));
    ui->btnSave->setIconSize(QSize(60, 60));

    ui->btnOpen->setIcon(QIcon(":/icons/open.png"));
    ui->btnOpen->setIconSize(QSize(60, 60));

    ui->btnExport->setIcon(QIcon(":/icons/export.png"));
    ui->btnExport->setIconSize(QSize(60, 60));

    QPixmap pixmap(":/icons/logo.jpg");
        ui->logo->setPixmap(pixmap);
    QPixmap scaledPixmap = pixmap.scaled(200, 200, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->logo->setPixmap(scaledPixmap);

    ui->centralwidget->setLayout(new QVBoxLayout);
    ui->centralwidget->layout()->addWidget(colorPalette);
    colorPalette->setOptions(
                    ColorPalette::DontUseNativeDialog
                    |ColorPalette::NoButtons);
    colorPalette->setStyleSheet(
                "QPushButton{ color: white; background-color: rgb(34, 39, 122)}"
                "QSpinBox{ color: white; background-color: rgb(8, 13, 67)}"
                "QLabel{ color: white}"
                );
    board->createBoard(ui->GraphicBoard);
    board->fillTable();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnBrush_clicked()
{
    ui->btnEraser->setStyleSheet("QPushButton{ background-color: rgb(34, 39, 122)}");
    ui->btnBrush->setStyleSheet("QPushButton{ background-color: rgb(139, 116, 189)}");
    ui->btnBucked->setStyleSheet("QPushButton{ background-color: rgb(34, 39, 122)}");
    delete tool;
    tool = new Brush();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
   QPoint globalPos = QCursor::pos();
   QPoint viewPos = ui->GraphicBoard->mapFromGlobal(globalPos);
   QPointF scenePos = ui->GraphicBoard->mapToScene(viewPos);
   tool->use(*board,scenePos,*colorPalette);
   board->createBoard(ui->GraphicBoard);
}

void MainWindow::on_sldCellsNumber_valueChanged(int value)
{
    board->setCellsNumber(value);
    board->createBoard(ui->GraphicBoard);

}

void MainWindow::on_btnEraser_clicked()
{
    ui->btnEraser->setStyleSheet("QPushButton{ background-color: rgb(139, 116, 189)}");
    ui->btnBrush->setStyleSheet("QPushButton{ background-color: rgb(34, 39, 122)}");
    ui->btnBucked->setStyleSheet("QPushButton{ background-color: rgb(34, 39, 122)}");
    delete tool;
    tool = new Eraser();
}


void MainWindow::on_btnBucked_clicked()
{
    ui->btnEraser->setStyleSheet("QPushButton{ background-color: rgb(34, 39, 122)}");
    ui->btnBrush->setStyleSheet("QPushButton{ background-color: rgb(34, 39, 122)}");
    ui->btnBucked->setStyleSheet("QPushButton{ background-color: rgb(139, 116, 189)}");
    delete tool;
    tool = new Bucket();
}

void MainWindow::on_btnClear_clicked()
{
   board->fillTable();
   board->createBoard(ui->GraphicBoard);
}


void MainWindow::on_btnSave_clicked()
{
    board->save();
}


void MainWindow::on_btnExport_clicked()
{
    board->exportToFile();
}


void MainWindow::on_btnOpen_clicked()
{
    board->open();
    ui->sldCellsNumber->setValue(board->getCellsNumber());
    ui->spinBox->setValue(board->getCellsNumber());
    board->createBoard(ui->GraphicBoard);
}

