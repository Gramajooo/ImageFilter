#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H

#include <string>

using namespace std;

class NodoMatriz
{
    public:

        NodoMatriz *sig;
        NodoMatriz *ant;
        NodoMatriz *arri;
        NodoMatriz *abajo;

        string color;
        int x;
        int y;

        NodoMatriz(int x, int y, string color);
        virtual ~NodoMatriz();

    protected:

    private:
};

#endif // NODOMATRIZ_H
