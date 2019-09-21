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
NodoArbol::NodoArbol(){}

void NodoArbol::crearCapa(string archi, string capa, string prioridad){
    MatrizCapa *nueva = new MatrizCapa(prioridad, capa);
    if(iniCapa == NULL){
        iniCapa = nueva;
        llenarCapa(archi, nueva, prioridad);
    }else{
        iniCapa->sig = nueva;
        iniCapa = nueva;
        llenarCapa(archi, nueva, prioridad);
    }
}
MatrizCapa lienzo;
void NodoArbol::llenarCapa(string archi, MatrizCapa *capa, string prioridad){
    MatrizCapa inse;
    ifstream archivos;
    string texto;
    int x=-1, y=-1;

    string direc = ".\\CargaMasiva\\"+archi+"\\"+capa->nomcapa;
    archivos.open(direc,ios::in);
    cout << direc << endl;
    while(getline(archivos, texto)){
        stringstream ss(texto);
        x++;
        y=0;
        while(getline(ss, texto, ',')){
            if(texto != "x"){
                inse.insertarColor(y,x,texto);
                //cout << y << " , " << x << " " << texto << endl;
            }
            y++;
        }
        ss.clear();
    }
    inse.graficar(prioridad);
    if(prioridad != "0"){
        lienzo.crearLienzo(direc);
    }
}

void NodoArbol::graficarMatriz(){

}



NodoArbol::~NodoArbol()
{
    //dtor
}
