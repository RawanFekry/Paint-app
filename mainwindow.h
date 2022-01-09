#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "Scene.h"
#include "QUndoStack"
#include <QTableWidget>


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



    void on_linewidthSpn_valueChanged(int arg1);

    void on_actShapes_Rectangle_triggered();

    void on_actShapes_Line_triggered();

    void on_actShapes_Circle_triggered();

    void on_actShapes_Triangle_triggered();

    void on_actUndo_triggered();

    void on_actRedo_triggered();

    void on_actColor_Line_triggered();

    void on_actLinestyle_Dense_Level_1_triggered();

    void on_actLinestyle_Dense_Level_2_triggered();

    void on_actLinestyle_Dense_Level_3_triggered();



    void on_actLinestyle_Solid_triggered();



    void on_actShapecolor_triggered();

    void on_actLinestyle_No_Brush_triggered();



    void on_btnSearch_clicked();



    void on_btnDelete_clicked();



    void on_btnSortA_clicked();

    void on_btnSortD_clicked();

    void on_tblwdgShape_cellChanged(int row, int column);

private:
    Ui::MainWindow *ui;
    newscene* scene;
    QUndoStack* undoStack;
    QBrush* brush;
};
#endif // MAINWINDOW_H
