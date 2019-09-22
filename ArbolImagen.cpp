#include "ArbolImagen.h"
#include "NodoArbol.h"
#include <iostream>
#include <sstream>
#include <fstream>
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
void ArbolImagen::graficarABB(){
    string dot = "digraph g { style=\"radial\" bgcolor=\"white:darkgreen\";\n";
    dot = dot + "node [style = radial, shape = record,color=cornflowerblue];\n";

    string algo = graficar(this->raiz);

    dot += algo + "}";

    ofstream file;
    file.open("graf.dot");
    file << dot;
    file.close();
    cout << "\n<<<<Archivo creado>>>>\n";
    string ope = "dot graf.dot -o Reports\\abb.jpg -Tjpg -Gcharset=utf8";
    const char* cs = ope.c_str();
    system(cs);

}
string ArbolImagen::graficar(NodoArbol *raiz) {
    string dot;
    string lbl1 = "[label = \"<f0> |<f1> ";
    string lbl2 = "|<f2> \",style = radial, shape = record,color=cornflowerblue];\n";
    if (raiz != 0) {
        stringstream r;
        r << raiz;
        string rot = "ABB" + r.str();
        r.str("");
        string name = raiz->nickname;
        string lbl = lbl1 + name + lbl2;
        dot = dot + rot + lbl;
        if (raiz->izq != 0) {
            dot = dot + graficar(raiz->izq);
            r << raiz->izq;
            string rotizq = "ABB" + r.str();
            dot = dot + "\"" + rot + "\":f0->\"" + rotizq + "\":f1 [color=\"white\"];\n";
        }
        r.str("");
        if (raiz->dere != 0) {
            dot = dot + graficar(raiz->dere);
            r << raiz->dere;
            string rotder = "ABB" + r.str();
            dot = dot + "\"" + rot + "\":f2->\"" + rotder + "\":f1 [color=\"white\"];\n";
        }
    }
    return dot;
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
