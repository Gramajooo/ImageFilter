#include "MatrizCapa.h"
#include "NodoMatriz.h"

#include <iostream>
#include <fstream>
#include <sstream>

MatrizCapa::MatrizCapa()
{
    //ctor
    //NODO MATRIZ ROOT
    this->root = new NodoMatriz(-1,-1, "Root");
    //NODO MATRIZ CAPA
    this->sig = NULL;
    this->ant = NULL;
    this->prioridad = 0;
    this->nomcapa = "";

}

NodoMatriz* MatrizCapa::buscarFila(int y)
{
    NodoMatriz *temp = this->root;
    while (temp != NULL){
        if (temp->y == y){
            return temp;
        }
        temp = temp->sig;
    }
    return NULL;
}


NodoMatriz* MatrizCapa::buscarColumna(int x)
{
    NodoMatriz *temp = this->root;
    while (temp != NULL){
        if (temp->x == x){
            return temp;
        }
        temp = temp->sig;
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
            bandera = false;
            break;
        }
    }
    if (bandera){
        nuevo->sig = temp;
        temp->ant->sig = nuevo;
        nuevo->ant = temp->ant;
        temp->ant = nuevo;
    }else{
        temp->sig = nuevo;
        nuevo->ant = temp;
    }
    return nuevo;


}

NodoMatriz* MatrizCapa::insertarOrdFila(NodoMatriz *nuevo, NodoMatriz *cabeza_fil){
    NodoMatriz *temp = cabeza_fil;
    bool bandera = true;
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
            bandera = false;
            break;
        }
    }
    if (bandera) {
        nuevo->abajo = temp;
        temp->arri->abajo = nuevo;
        nuevo->arri = temp->arri;
        temp->arri = nuevo;
    }else{
        temp->abajo = nuevo;
        nuevo->arri = temp;
    }
    return nuevo;

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
    NodoMatriz *nodoColumna = buscarColumna(x);
    NodoMatriz *nodoFila = buscarFila(y);


    if (nodoColumna == NULL && nodoFila == NULL)
    {
        nodoColumna = crearColumna(x);
        nodoFila = crearFila(y);


        nuevo = insertarOrdColumna(nuevo, nodoFila);
        nuevo = insertarOrdFila(nuevo, nodoColumna);
        return;

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


void MatrizCapa::graficar(){
    NodoMatriz *rrFil = this->root;
    NodoMatriz *rrCol = this->root;


    string grafica = "digraph g { \n";
    grafica += "node[shape=box, color=cornflowerblue];";
    while(rrCol != NULL){
        grafica += "\n subgraph {";
        while(rrFil != NULL){
            stringstream rr3;
            stringstream rr4;
            rr3 << rrFil->x;
            rr4 << rrFil->y;
            string s3 = rr3.str();
            string s4 = rr4.str();
            grafica += "\"" + s3 + "," + s4 + " " + rrFil->color + "\" \n";
            rrFil = rrFil->abajo;
            if(rrFil != NULL){
                stringstream rr3;
                stringstream rr4;
                rr3 << rrFil->x;
                rr4 << rrFil->y;
                string s3 = rr3.str();
                string s4 = rr4.str();
                grafica += "-> \"" + s3+ "," + s4 + " " + rrFil->color + "\" [dir=\"both\"] \n";
            }
        }
        rrCol = rrCol->sig;
        if(rrFil == NULL){
            rrFil = rrCol;
        }
         grafica += "}";
    }
    rrFil = this->root;
    rrCol = this->root;

    while(rrFil != NULL){
        grafica += "\n rank=same{";
        while(rrCol != NULL){
            stringstream rr3;
            stringstream rr4;
            rr3 << rrCol->x;
            rr4 << rrCol->y;
            string s3 = rr3.str();
            string s4 = rr4.str();
            grafica += "\"" + s3 + "," + s4 + " " + rrCol->color + "\" \n";
            rrCol = rrCol->sig;
            if(rrCol != NULL){
                stringstream rr3;
                stringstream rr4;
                rr3 << rrCol->x;
                rr4 << rrCol->y;
                string s3 = rr3.str();
                string s4 = rr4.str();
                grafica += "-> \"" + s3+ "," + s4 + " " + rrCol->color + "\" [dir=\"both\"] \n";
            }
        }
        rrFil = rrFil->abajo;
        if(rrCol == NULL){
            rrCol = rrFil;
        }
          grafica += "}";
    }


    grafica += "}";

    ofstream file;
    file.open("graf.dot");
    file << grafica;
    file.close();

    system("dot graf.dot -o imagen.jpg -Tjpg -Gcharset=utf8");
    //system("/c start imagen.jpg");


    cout << "\n Listo :)" << endl;

}


MatrizCapa::~MatrizCapa()
{
    //dtor
}
