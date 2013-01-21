#include "estadistica.h"
#include <QDebug>

Estadistica::Estadistica()
{
    this->_arreglo = 0;
    this->_cuantos = 0;
    this->_media = 0.0;
}

Estadistica::Estadistica(int arr[], int cuantos){
    this->_arreglo = 0;
    setData(arr, cuantos);
}

void Estadistica::setData(int arr[], int cuantos){
    if( this->_arreglo != 0)
        delete [] _arreglo;

    this->_arreglo = new int[cuantos];
    this->_cuantos = cuantos;
    int acumulador = 0;

    for(int i = 0; i < cuantos; i++){
        this->_arreglo[i] = arr[i];
        acumulador = acumulador + arr[i];
    }

    this->_media = (float)acumulador / cuantos;

    this->ordenar(_arreglo, cuantos);
}

void Estadistica::ordenar(int A[], int cuantos){
    for(int i = 0; i < cuantos-1; i++){
        int x = this->menor(A, i, cuantos-1);
        this->intercambiar(A, i, x);
    }
}

int Estadistica::menor(int A[], int inf, int sup){
    int valor_menor = A[inf];
    int indice_menor = inf;
    for(int i = inf; i <= sup; i++){
        if(A[i] < valor_menor){
            valor_menor = A[i];
            indice_menor = i;
        }
    }
    return indice_menor;
}

void Estadistica::intercambiar(int A[], int pos1, int pos2){
    int temporal = A[pos1];
    A[pos1] = A[pos2];
    A[pos2] = temporal;
}

float Estadistica::getMedia(){
    return this->_media;
}

int Estadistica::getMenor(){
    if(this->_cuantos == 0)
        return -1;
    return this->_arreglo[0];
}

int Estadistica::getMayor(){
    if(this->_cuantos == 0)
        return -1;
    return this->_arreglo[this->_cuantos-1];
}

int Estadistica::getMediana(){
    if(this->_cuantos == 0)
        return -1  ;
    return(this->_arreglo[this->_cuantos/2]);
}

int Estadistica::getModa(){
    if(this->_cuantos == 0)
        return -1;

    int index = 0;
    int maxCount = 1;
    int count = 1;
    int current = _arreglo[0];
    for(int i = 1; i < _cuantos; i++){
        qDebug() << "Using " << _arreglo[i];
        if(_arreglo[i] == current){
            count++;
            if(count > maxCount){
                index = i;
                maxCount = count;
            }
        }else
            count = 1;
        current = _arreglo[i];
    }
    return _arreglo[index];
}

Estadistica::~Estadistica(){
    delete [] this->_arreglo;
}
