#include <iostream>

#include "MatrizCapa.h"

#include <string>

using namespace std;

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
        MatrizCapa insertar;
        insertar.insertarColor(1,3,"FFF");
        cout << "Insertado correctamente " << endl;
    }else{
        cout << "Algo salio mal " << endl;
    }




    return 0;
}
