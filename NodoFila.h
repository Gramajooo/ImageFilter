#ifndef NODOFILA_H
#define NODOFILA_H


class NodoFila
{
    public:

        NodoFila *sig;
        NodoFila *ant;

        NodoMatriz *valor;

        NodoFila();
        virtual ~NodoFila();

    protected:

    private:
};

#endif // NODOFILA_H
