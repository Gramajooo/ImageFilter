#include "NodoMatriz.h"

#include <string>


using namespace std;

NodoMatriz::NodoMatriz(int x, int y, string color)
{
    //ctor
    this->sig = NULL;
    this->ant = NULL;
    this->arri = NULL;
    this->abajo = NULL;

    this->x = x;
    this->y = y;
    this->color = color;
}


NodoMatriz::~NodoMatriz()
{
    //dtor
}
