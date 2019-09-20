#include "NodoArbol.h"
#include "ListaFiltro.h"
#include "MatrizCapa.h"
#include <fstream>
#include <sstream>
#include <iostream>

NodoArbol::NodoArbol(string nickname)
{
    //ctor

    //NODO ARBOL
    this->izq = NULL;
    this->dere = NULL;
    this->nickname = nickname;

    //NODO CAPA
    this->iniCapa = NULL;

    //NODO FILTRO
    this->iniFil = NULL;
}


void NodoArbol::crearCapa(){
    MatrizCapa insertar;

    ifstream archivos;
    string texto;
    int x=-1, y=-1;
    archivos.open("usuarios.csv",ios::in);

    while(getline(archivos, texto)){
        stringstream ss(texto);
        x++;
        y=0;
        while(getline(ss, texto, ',')){
            if(texto != "x"){
                insertar.insertarColor(y,x,texto);
                cout << y << " , " << x << " " << texto << endl;
            }
            y++;
        }
        ss.clear();
    }
    //insertar.graficar();
}

void NodoArbol::graficarMatriz(){

}



NodoArbol::~NodoArbol()
{
    //dtor
}
