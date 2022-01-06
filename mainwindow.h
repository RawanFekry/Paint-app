#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include "Scene.h"
#include "QUndoStack"


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


    void on_lineBtn_clicked();

    void on_rectBtn_clicked();

    void on_circleBtn_clicked();

    void on_triangBtn_clicked();

    void on_undoBtn_clicked();

    void on_redoBtn_clicked();

    void on_shapecolorBtn_clicked();

    void on_linewidthSpn_valueChanged(int arg1);

    void on_fillshapeBtn_clicked();

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

    void on_actDelete_triggered();

private:
    Ui::MainWindow *ui;
    newscene* scene;
    QUndoStack* undoStack;
};
#endif // MAINWINDOW_H
