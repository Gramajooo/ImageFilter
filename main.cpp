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
                    //cout << texto << endl;
                    //cout << y << " , " << x << "---" << texto << endl;
                    priori = texto;
                }
                break;
            case 1:
                if(texto != "File"){
                    //cout << y << " , " << x << "---" << texto << endl;
                    capa = texto;
                }
                break;
            }
            if((priori.size() != 0 && capa.size() != 0)){
                //cout << capa << " " << priori << endl;
                creCapa.crearCapa(archi, capa, priori);
            }
            y++;
        }
        ss.clear();
    }
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
        cout << "7. Pruebas " << endl;
        cout << "8. Exit " << endl;

        cin >> opcion;

        switch(opcion){
        case 1:
            leerImagenes();
            break;
        case 2:
            system("cls");
            cout << "---------------- IMAGES ------------------- " << endl;
            seleccionarImagen();
            break;
        case 7:
            leerImagenes();
            break;
        case 8:
            system("exit");
            break;
        default:
            system("cls");
            break;
        }
        //system("cls");

    }while(opcion != 8);
    return 0;
}
