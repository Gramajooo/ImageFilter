#ifndef ARBOLIMAGEN_H
#define ARBOLIMAGEN_H

#include "NodoArbol.h"

class ArbolImagen
{
    public:

        //NODO RAIZ
        NodoArbol *raiz;

        //METODOS ARBOL BINARIO

        void insertarImagen(string nickname);
        NodoArbol *insertar(NodoArbol *raiz, string nickname);

        string buscarImagen(int ids);
        string buscar(NodoArbol *raiz);


        void recorrerInorden();
        void inorden(NodoArbol *raiz);

        void recorrerPreorden();
        void preorden(NodoArbol *raiz);

        void recorrerPosorden();
        void postorden(NodoArbol *raiz);


        ArbolImagen();
        virtual ~ArbolImagen();

    protected:

    private:
};

#endif // ARBOLIMAGEN_H
