#ifndef LISTAFILTRO_H
#define LISTAFILTRO_H

#include <string>

using namespace std;

class ListaFiltro
{
    public:

        //NODO FILTRO
        ListaFiltro *sig;
        ListaFiltro *ant;

        string nomfiltro;

        ListaFiltro(string nomfiltro);
        virtual ~ListaFiltro();

    protected:

    private:
};

#endif // LISTAFILTRO_H
