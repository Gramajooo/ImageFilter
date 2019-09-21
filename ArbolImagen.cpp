#include "ArbolImagen.h"
#include "NodoArbol.h"
#include <iostream>
#include <sstream>
ArbolImagen::ArbolImagen()
{
    //ctor
    //NODO ARBOL BINARIO
    this->raiz = NULL;

}

int x=1, id;
string ArbolImagen::buscarImagen(int ids){
    id=ids;
    return buscar(this->raiz);
}

string ArbolImagen::buscar(NodoArbol *raiz){
    stringstream rc;
    rc << x;
    string ss = rc.str();
    if (raiz != NULL) {
		buscar(raiz->izq);
		if(x == id){
            return raiz->nickname;
		}
        x++;
		buscar(raiz->dere);
	}
}


void ArbolImagen::insertarImagen(string nickname){
    this->raiz = insertar(this->raiz, nickname);
}

NodoArbol *ArbolImagen::insertar(NodoArbol *raiz, string nickname){
    if(raiz == 0){
        raiz = new NodoArbol(nickname);
    }else if ( 1 <= raiz->nickname.compare (nickname)){
        raiz->izq = insertar(raiz->izq, nickname);
    }else if( -1 >= raiz->nickname.compare (nickname)){
        raiz->dere = insertar(raiz->dere, nickname);
    }
    return raiz;
}


void ArbolImagen::recorrerInorden(){
    inorden(this->raiz);
}
int cont=1;
void ArbolImagen::inorden(NodoArbol *raiz){

    stringstream rc;
    rc << cont;
    string ss = rc.str();
    if (raiz != NULL) {
		inorden(raiz->izq);
		cout << ss + ". " + raiz->nickname << endl;
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
