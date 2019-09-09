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

NodoArbol::~NodoArbol()
{
    //dtor
}
