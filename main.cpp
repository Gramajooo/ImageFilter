#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "MatrizCapa.h"
#include "ArbolImagen.h"
#include "NodoArbol.h"

using namespace std;


ArbolImagen inserImg;

void leerImagenes(){
    string archi;
    cout << "Ingrese el nombre de la imagen: " <<endl;
    cin >> archi;
    inserImg.insertarImagen(archi);
}

void seleccionarImagen(){
    NodoArbol creCapa;
    int opcion;
    inserImg.recorrerInorden();
    cin >> opcion;

    ifstream archivos;
    string archi;
    archi = inserImg.buscarImagen(opcion);
    cout << archi <<endl;
    string direc = ".\\CargaMasiva\\"+archi+"\\inicial.csv";
    archivos.open(direc,ios::in);
    cout << direc <<endl;

    string texto;
    int x=-1, y=-1;
    while(getline(archivos, texto)){
        stringstream ss(texto);
        x++;
        y=0;
        string priori, capa;
        while(getline(ss, texto, ',')){
            switch(y){
            case 0:
                if(texto != "Layer"){
                    priori = texto;
                }
                break;
            case 1:
                if(texto != "File"){
                    capa = texto;
                }
                break;
            }
            if((priori.size() != 0 && capa.size() != 0)){
                creCapa.crearCapa(archi, capa, priori);
            }
            y++;
        }
        ss.clear();
    }
    //system("cls");
}

void reports(){
    int opcion;
    do{
        cout << "---------------- REPORTS ------------------- " << endl;
        cout << "1. Imported Images (ABB) " << endl;
        cout << "2. Image Layer (CAPAS Y LIENZO)" << endl;
        cout << "3. Linear Matrix (MATRIZ LINEAL)" << endl;
        cout << "4. Traversal (RECORRIDOS)" << endl;
        cout << "5. Filters (FILTROS)" << endl;
        cout << "6. Exit" << endl;

        cin >> opcion;

        switch(opcion){
        case 1:{
            //string sys = "\\cd Reports\\abb.jpg";
            //const char *s = sys.c_str();
            //system(s);}
            inserImg.graficarABB();
            }
            break;
        case 6:
            opcion = 8;
            break;
        default:
            //system("cls");
            break;
        }

    }while(opcion != 8);

}

int main()
{
    int opcion;

    do{
        cout << "---------------- MENU ------------------- " << endl;
        cout << "1. Insert image " << endl;
        cout << "2. Select image " << endl;
        cout << "3. Apply filters " << endl;
        cout << "4. Manual editing " << endl;
        cout << "5. Export image " << endl;
        cout << "6. Reports " << endl;
        cout << "7. Exit " << endl;

        cin >> opcion;

        switch(opcion){
        case 1:
            leerImagenes();
            break;
        case 2:
            system("cls");
            cout << "---------------- IMAGES ------------------- " << endl;
            seleccionarImagen();
            //system("cls");
            break;
        case 6:
            system("cls");
            reports();
            break;
        case 7:
            opcion = 7;
            break;
        default:
            system("cls");
            break;
        }
        //system("cls");

    }while(opcion != 7);

    return 0;
}
