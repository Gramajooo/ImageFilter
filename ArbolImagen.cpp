#include "ArbolImagen.h"
#include "NodoArbol.h"
#include <iostream>
ArbolImagen::ArbolImagen()
{
    //ctor
    //NODO ARBOL BINARIO
    this->raiz = NULL;

}

void ArbolImagen::insertarImagen(string nickname){
    this->raiz = insertar(this->raiz, nickname);
}

NodoArbol *ArbolImagen::insertar(NodoArbol *raiz, string nickname){
    if(raiz == NULL){
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
    if (raiz != NULL) {
		inorden(raiz->izq);
		cout << cont + ". " + raiz->nickname << endl;
        cont++;
		inorden(raiz->dere);
	}
}

void ArbolImagen::recorrerPreorden(){
    preorden(this->raiz);
}
void ArbolImagen::preorden(NodoArbol *raiz){
    int cont=1;
    if (raiz != NULL) {
		cout << cont + ". " + raiz->nickname << endl;
        cont++;
		preorden(raiz->izq);
		preorden(raiz->dere);
	}
}

void ArbolImagen::recorrerPosorden(){
    postorden(this->raiz);
}
void ArbolImagen::postorden(NodoArbol *raiz){
    int cont=1;
    if (raiz != NULL) {
		postorden(raiz->izq);
		postorden(raiz->dere);
		cout << cont + ". " + raiz->nickname << endl;
        cont++;
	}
}

ArbolImagen::~ArbolImagen()
{
    //dtor
}
