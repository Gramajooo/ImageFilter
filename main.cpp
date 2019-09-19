#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "MatrizCapa.h"

using namespace std;

void leerImagenes(){

    MatrizCapa insertar;

    ifstream archivos;
    string texto;
    int x=0, y=0;
    archivos.open("usuarios.csv",ios::in);

    while(getline(archivos, texto)){
        stringstream ss(texto);
        x++;
        y=1;
        while(getline(ss, texto, ';')){
            //if(texto != "x"){
                insertar.insertarColor(y,x,texto);
                cout << y << " , " << x << " " << texto << endl;
            //}
            y++;
        }
        ss.clear();
    }
    insertar.graficar();
}

int main()
{
    int opcion;

    cout << "---------------- MENU ------------------- " << endl;
    cout << "1. Insert image " << endl;
    cout << "2. Select image " << endl;
    cout << "3. Apply filters " << endl;
    cout << "4. Manual editing " << endl;
    cout << "5. Export image " << endl;
    cout << "6. Reports " << endl;
    cout << "7. Pruebas " << endl;

    cin >> opcion;

    if (opcion == 7){
        leerImagenes();
    }else{
        cout << "Algo salio mal " << endl;
    }
    return 0;
}
