#include "NodoArbol.h"
#include "ListaFiltro.h"
#include "MatrizCapa.h"

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
    MatrizCapa nuevaMatriz;
    nuevaMatriz.insertarColor(1,1,"FFF");
}

void NodoArbol::graficarMatriz(){

}



NodoArbol::~NodoArbol()
{
    //dtor
}
