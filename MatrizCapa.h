#ifndef MATRIZCAPA_H
#define MATRIZCAPA_H

#include "NodoMatriz.h"

class MatrizCapa
{
    public:

        // NODO RAIZ
        NodoMatriz *root;
        //NODO CAPA
        MatrizCapa *sig;
        string prioridad;
        string nomcapa;

        MatrizCapa(string prioridad, string nomcapa);
        MatrizCapa();
        virtual ~MatrizCapa();

        // METODOS CAPA
        NodoMatriz* buscarFila(int y);
        NodoMatriz* buscarColumna(int x);

        NodoMatriz* insertarOrdColumna(NodoMatriz *nuevo, NodoMatriz *cabeza_col);
        NodoMatriz* insertarOrdFila(NodoMatriz *nuevo, NodoMatriz *cabeza_fil);

        NodoMatriz* crearFila(int y);
        NodoMatriz* crearColumna(int x);

        void insertarColor(int x, int y, string color);

        void graficar(string prioridad);

        void crearLienzo(string lienzo);

    protected:

    private:
};

#endif // MATRIZCAPA_H
