#ifndef NODOARBOL_H
#define NODOARBOL_H

#include "MatrizCapa.h"
#include "ListaFiltro.h"

class NodoArbol
{
    public:

        //NODO ARBOL
        NodoArbol *izq;
        NodoArbol *dere;
        string nickname;

        //NODO CAPAS
        MatrizCapa *iniCapa;

        //Lista de capas
        void crearCapa(string archi, string capa, string prioridad);
        void llenarCapa(string archi, MatrizCapa *capa, string prioridad);
        void graficarMatriz();

        //NODO FILTROS
        ListaFiltro *iniFil;

        //Lista de filtros
        void crearFiltro();

        //METODOS NODO ARBOL
        void crearLienzo();

        NodoArbol(string nickname);
        NodoArbol();
        virtual ~NodoArbol();

    protected:

    private:
};

#endif // NODOARBOL_H
