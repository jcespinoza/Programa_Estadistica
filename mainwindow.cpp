#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    int miarreglo[6] = {30, 23, 19, 19, 20, 38};

    this->miEstadistica = new Estadistica(miarreglo, 6);

    qDebug() << "Media es: " << this->miEstadistica->getMedia();
    qDebug() << "Mediana es: " << this->miEstadistica->getMediana();
    qDebug() << "Menor es: " << this->miEstadistica->getMenor();
    qDebug() << "Mayor es: " << this->miEstadistica->getMayor();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_le_Valor_returnPressed()
{
    this->on_pBAgregar_clicked();
}

void MainWindow::on_pBAgregar_clicked()
{
    ui->listValores->addItem(ui->le_Valor->text());
    ui->le_Valor->clear();
}

void MainWindow::on_pbCalcular_clicked()
{
    int count = ui->listValores->count();
    for(int i = 0; i < count;i++){
        QListWidgetItem *temp = ui->listValores->item(i);
        //qDebug() << temp->text();
    }
}
