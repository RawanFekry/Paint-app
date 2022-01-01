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

private:
    Ui::MainWindow *ui;
    newscene* scene;
    QUndoStack* undoStack;


};
#endif // MAINWINDOW_H
