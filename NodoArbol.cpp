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
    //
    cout << direc << endl;
    while(getline(archivos, texto)){
        stringstream ss(texto);
        x++;
        y=0;
        while(getline(ss, texto, ',')){
            if(texto != "X" && texto != "x" ){
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
        //cout << "holis" << endl;
        string ruta= ".\\CargaMasiva\\"+archi+"\\config.csv";
        lienzo.pintarHTML(ruta, archi);
    }
    //system("cls");
    //menuFiltros();

}

void NodoArbol::menuFiltros(){
    int opcion;
    do{
        cout << "---------------- APPLY FILTER ------------------- " << endl;
        cout << "1. Select Filter " << endl;
        cout << "2. Export Image " << endl;
        cin >> opcion;

        switch(opcion){
        case 1:
            int op;
            cout << "---------------- FILTERS ------------------- " << endl;
            cout << "1. Negative " << endl;
            cout << "2. Grayscale " << endl;
            cout << "3. X-Mirror " << endl;
            cout << "4. Y-Mirror " << endl;
            cout << "5. Double-Mirror " << endl;
            cout << "6. Collage " << endl;
            cout << "7. Mosaic " << endl;
            cin >> op;

            switch(op){
                case 5:
                    lienzo.graficarDouble();
                    break;
                default:
                    cout << "No puedo" << endl;
                    break;
            }
            break;
        default:

            break;
        }
    }while(opcion != 8);
}


NodoArbol::~NodoArbol()
{
    //dtor
}
