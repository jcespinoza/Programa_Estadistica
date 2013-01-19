#ifndef ESTADISTICA_H
#define ESTADISTICA_H

class Estadistica{
private:
    int *_arreglo;
    int _cuantos;
    float _media;
    void ordenar(int A[],int cuantos);
    int menor(int A[],int inf,int sup);
    void intercambiar(int A[],int pos1,int pos2);
public:
    Estadistica();
    Estadistica(int arr[],int cuantos);
    void setData(int arr[],int cuantos);
    int getMayor();
    int getMenor();
    float getMedia();
    int getModa();
    int getMediana();

    ~Estadistica();
};

#endif // ESTADISTICA_H
