#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <ctype.h>
#include <string.h>
#include "estadistica.h"

namespace Ui{
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

    /**
     * @brief on_pBAgregar_clicked
     * Agrega el elemento si es un entero.
     */
    void on_pBAgregar_clicked();

    void on_pbCalcular_clicked();

private:
    Ui::MainWindow *ui;
    Estadistica *miEstadistica;
    void showStatistics();
    bool isInteger(QString q);
};

#endif // MAINWINDOW_H
