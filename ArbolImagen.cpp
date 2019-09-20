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


void ArbolImagen::recorrerInorden(){
    inorden(this->raiz);
}
void ArbolImagen::inorden(NodoArbol *raiz){
    int cont=1;
    if (nodo != NULL) {
		inorden(NodoArbol->izq);
		cout << cont + ". " + NodoArbol->nickname << endl;
        cont++;
		inorden(NodoArbol->dere);
	}
}

void ArbolImagen::recorrerPreorden(){
    preorden(this->raiz);
}
void ArbolImagen::preorden(NodoArbol *raiz){
    int cont=1;
    if (nodo != NULL) {
		cout << cont + ". " + NodoArbol->nickname << endl;
        cont++;
		preorden(NodoArbol->izq);
		preorden(NodoArbol->dere);
	}
}

void ArbolImagen::recorrerPosorden(){
    postorden(this->raiz);
}
void ArbolImagen::postorden(NodoArbol *raiz){
    int cont=1;
    if (nodo != NULL) {
		postorden(NodoArbol->izq);
		postorden(NodoArbol->dere);
		cout << cont + ". " + NodoArbol->nickname << endl;
        cont++;
	}
}

ArbolImagen::~ArbolImagen()
{
    //dtor
}
