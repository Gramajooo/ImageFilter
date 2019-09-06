#include <iostream>

#include "MatrizCapa.h"
#include "NodoMatriz.h"

using namespace std;

MatrizCapa::MatrizCapa()
{
    //ctor

    this->root = new NodoMatriz(-1,-1, "Root");

}

NodoMatriz* MatrizCapa::buscarFila(int y)
{
    NodoMatriz *nuevo = root;
    while (nuevo != NULL){
        if (nuevo->y == y){
            return nuevo;
        }
        nuevo = nuevo->sig;
    }
    return NULL;
}


NodoMatriz* MatrizCapa::buscarColumna(int x)
{
    NodoMatriz *nuevo = root;
    while (nuevo != NULL){
        if (nuevo->x == x){
            return nuevo;
        }
        nuevo = nuevo->sig;
    }
    return NULL;
}


NodoMatriz* MatrizCapa::insertarOrdColumna(NodoMatriz *nuevo, NodoMatriz *cabeza_col){

    NodoMatriz *temp = cabeza_col;
    bool bandera = false;
    while (true){
        if (temp->x == nuevo->x){
            temp->y = nuevo->y;
            temp->color = nuevo->color;
            return temp;
        }else if(temp->x > nuevo->x){
            bandera = true;
            break;
        }
        if (temp->sig != NULL){
            temp = temp->sig;

        }else{
            break;
        }
        if (bandera)
        {
            nuevo->sig = temp;
            temp->ant->sig = nuevo;
            nuevo->ant = temp->ant;
            temp->abajo = nuevo;
        }else{
            temp->sig = nuevo;
            nuevo->ant = temp;
        }
        return nuevo;
    }


}

NodoMatriz* MatrizCapa::insertarOrdFila(NodoMatriz *nuevo, NodoMatriz *cabeza_fil){
    NodoMatriz *temp = cabeza_fil;
    bool bandera = false;

            cout << "caray" << endl;
    while (true){
        if (temp->y == nuevo->y){
            temp->x = nuevo->x;
            temp->color = nuevo->color;
            return temp;
        }else if(temp->y > nuevo->y){
            bandera = true;
            break;
        }
        if (temp->abajo != NULL){
            temp = temp->abajo;

        }else{
            break;
        }
        if (bandera)
        {
            nuevo->abajo = temp;
            temp->arri->abajo = nuevo;
            nuevo->arri = temp->arri;
            temp->abajo = nuevo;
        }else{
            temp->abajo = nuevo;
            nuevo->arri = temp;
        }
        return nuevo;
    }

}

NodoMatriz * MatrizCapa::crearColumna(int x){
    NodoMatriz *cabeza_columna = this->root;
    NodoMatriz *columna = insertarOrdColumna(new NodoMatriz(x, -1, "COL"), cabeza_columna);
    return columna;
}

NodoMatriz * MatrizCapa::crearFila(int y){
    NodoMatriz *cabeza_fila = this->root;
    NodoMatriz *fila = insertarOrdFila(new NodoMatriz(-1, y, "FIL"), cabeza_fila);
    return fila;
}

void MatrizCapa::insertarColor(int x, int y, string color){
    NodoMatriz *nuevo = new NodoMatriz(x, y, color);
    NodoMatriz *nodoFila = buscarFila(y);
    NodoMatriz *nodoColumna = buscarColumna(x);

    if (nodoColumna == NULL && nodoFila == NULL)
    {
        nodoColumna = crearColumna(x);
        nodoFila = crearFila(y);


        nuevo = insertarOrdColumna(nuevo, nodoFila);
        cout << "holis original" << endl;
        nuevo = insertarOrdFila(nuevo, nodoColumna);



    }else if (nodoColumna == NULL && nodoFila != NULL){

        nodoColumna = crearColumna(x);

        nuevo = insertarOrdColumna(nuevo, nodoFila);
        nuevo = insertarOrdFila(nuevo, nodoColumna);
        return;

    }else if (nodoColumna != NULL && nodoFila == NULL){

        nodoFila = crearFila(y);

        nuevo = insertarOrdColumna(nuevo, nodoFila);
        nuevo = insertarOrdFila(nuevo, nodoColumna);
        return;

    }else if (nodoColumna != NULL && nodoFila != NULL){

        nuevo = insertarOrdColumna(nuevo, nodoFila);
        nuevo = insertarOrdFila(nuevo, nodoColumna);

    }



}


MatrizCapa::~MatrizCapa()
{
    //dtor
}
