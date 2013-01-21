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
    if(isInteger(ui->le_Valor->text()))
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

/**
 * @brief MainWindow::showStatistics
 * Se encarga de cambiar el texto de los Labels con los datos de Estadistica
 */
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

/**
 * @brief MainWindow::isInteger
 * Verifica si una QString representa un entero.
 * @param q La QString a evaluar.
 * @return Si la QString es entero o no.
 */
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
