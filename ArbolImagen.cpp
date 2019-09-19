#include "ArbolImagen.h"
#include "NodoArbol.h"

ArbolImagen::ArbolImagen()
{
    //ctor
    //NODO ARBOL BINARIO
    this->raiz = NULL;

}

void ArbolImagen::insertarImagen(string nickname){
    insertar(this->raiz, nickname);
}

NodoArbol *ArbolImagen::insertar(NodoArbol *raiz, string nickname){
    if(raiz != NULL){
        raiz = new NodoArbol(nickname);
    }else if ( 1 < raiz->nickname.compare (nickname)){
        raiz->izq = insertar(raiz->izq, nickname);
    }else if( -1 >= raiz->nickname.compare (nickname)){
        raiz->dere = insertar(raiz->dere, nickname);
    }
    return raiz;
}


ArbolImagen::~ArbolImagen()
{
    //dtor
}
