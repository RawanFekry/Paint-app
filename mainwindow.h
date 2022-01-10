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

    void on_tblwdgShape_cellChanged(int row, int column);

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionLine_triggered();

    void on_actionRectangle_triggered();

    void on_actionCircle_triggered();

    void on_actionTriangle_triggered();

    void on_actionLine_color_triggered();

    void on_actionLine_Style_1_triggered();

    void on_actionLine_Style_2_triggered();

    void on_actionLine_Style_3_triggered();

    void on_actionSolid_triggered();

    void on_actionNO_Brush_triggered();

    void on_actionDelete_triggered();

    void on_actionSearch_triggered();

    void on_actionShape_color_triggered();

    void on_actionSorting_Ascending_triggered();

    void on_actionSorting_Descending_triggered();


private:
    Ui::MainWindow *ui;
    newscene* scene;
    QUndoStack* undoStack;
    QBrush* brush;
};
#endif // MAINWINDOW_H
