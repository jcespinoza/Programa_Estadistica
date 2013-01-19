#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "estadistica.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_le_Valor_returnPressed();

    void on_pBAgregar_clicked();

    void on_pbCalcular_clicked();

private:
    Ui::MainWindow *ui;
    Estadistica *miEstadistica;
};

#endif // MAINWINDOW_H
