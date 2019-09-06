#ifndef NODOCOLUMNA_H
#define NODOCOLUMNA_H

#include "NodoMatriz.h"

class NodoColumna
{
    public:

        NodoColumna *sig;
        NodoColumna *ant;

        NodoMatriz *valor;

        NodoColumna();
        virtual ~NodoColumna();

    protected:

    private:
};

#endif // NODOCOLUMNA_H
