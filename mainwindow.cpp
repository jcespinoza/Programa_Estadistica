#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->miEstadistica = new Estadistica();
    validator = new QIntValidator(1, 150, this);
    ui->le_Valor->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete validator;
    delete miEstadistica;
}

void MainWindow::on_le_Valor_returnPressed()
{
    this->on_pBAgregar_clicked();
}

void MainWindow::on_pBAgregar_clicked()
{
    //if(isInteger(ui->le_Valor->text()))
        ui->listValores->addItem(ui->le_Valor->text());
    ui->le_Valor->clear();
}

void MainWindow::on_pbCalcular_clicked()
{
    int count = ui->listValores->count();
    int *nData = new int[count];
    for(int i = 0; i < count; i++){
        QListWidgetItem *temp = ui->listValores->item(i);
        QString s = temp->text();
        nData[i] = s.toInt();
    }
    this->miEstadistica->setData(nData, count);
    showStatistics();
    delete [] nData;
}

void MainWindow::showStatistics(){
    float media = this->miEstadistica->getMedia();
    int menor = this->miEstadistica->getMenor();
    int mayor = this->miEstadistica->getMayor();
    int mediana = this->miEstadistica->getMediana();
    int moda = this->miEstadistica->getModa();
    this->ui->lblMedia->setText(QString::number(media));
    this->ui->lblMenor->setText(QString::number(menor));
    this->ui->lblMayor->setText(QString::number(mayor));
    this->ui->lblMediana->setText(QString::number(mediana));
    this->ui->lblModa->setText(QString::number(moda));
}

bool MainWindow::isInteger(QString q){
    bool isInt = true;
    std::string s = q.toStdString();
      for(int i = 0; i < s.length(); i++){
        if(!isdigit(s[i])){
            isInt = false;
            break;
        }
      }
    return isInt;
}

void MainWindow::on_pbLimpiar_clicked()
{
    ui->listValores->clear();
    QString text = QString::fromStdString("No hay Datos");
    this->ui->lblMedia->setText(text);
    this->ui->lblMenor->setText(text);
    this->ui->lblMayor->setText(text);
    this->ui->lblMediana->setText(text);
    this->ui->lblModa->setText(text);
}

void MainWindow::on_pbCargar_clicked()
{
    QFileDialog f(this);
    f.setFileMode(QFileDialog::ExistingFile);
    f.setNameFilter(QString::fromStdString("Archivos de texto (*.txt)"));
    f.showFullScreen();
}
