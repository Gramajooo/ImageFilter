#ifndef NODOMATRIZ_H
#define NODOMATRIZ_H


class NodoMatriz
{
    public:

        NodoMatriz *sig;
        NodoMatriz *ant;
        NodoMatriz *arri;
        NodoMatriz *abajo;

        NodoMatriz();
        virtual ~NodoMatriz();


    protected:

    private:
};

#endif // NODOMATRIZ_H
