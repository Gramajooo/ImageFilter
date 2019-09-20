#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "MatrizCapa.h"
#include "ArbolImagen.h"

using namespace std;

void leerImagenes(){

    ArbolImagen inserImg;

    ifstream archivos;
    string texto;
    string archi;
    int x=-1, y=-1;
    cout << "Ingrese el nombre de la imagen: " <<endl;
    cin >> archi;
    archivos.open(".\CargaMasiva\\"+archi+"\inicial.csv",ios::in);
    inserImg.insertarImagen(archi);
    while(getline(archivos, texto)){
        stringstream ss(texto);
        x++;
        y=0;
        while(getline(ss, texto, ',')){
            if(y>0 && texto != "File")
            inserImg.insertarImagen(texto);
            cout << y << " , " << x << " " << texto << endl;
            y++;
        }
        ss.clear();
    }
    inserImg.recorrerInorden();

}

int main()
{
    int opcion;
    while(opcion != 8){

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

        if (opcion == 7){
            leerImagenes();
        }else{
            cout << "Algo salio mal " << endl;
            opcion = 8;
        }
    }
    return 0;
}
