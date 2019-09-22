#include "MatrizCapa.h"
#include "NodoMatriz.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

MatrizCapa::MatrizCapa(string prioridad, string nomcapa)
{

    this->prioridad = prioridad;
    this->nomcapa = nomcapa;

}

MatrizCapa::MatrizCapa(){
    //NODO MATRIZ ROOT
    this->root = new NodoMatriz(-1,-1, "Root");
    //NODO MATRIZ CAPA
    this->sig = NULL;
}

NodoMatriz* MatrizCapa::buscarFila(int y)
{
    NodoMatriz *temp = this->root;
    while (temp != NULL){
        if (temp->y == y){
            return temp;
        }
        temp = temp->sig;
    }
    return NULL;
}


NodoMatriz* MatrizCapa::buscarColumna(int x)
{
    NodoMatriz *temp = this->root;
    while (temp != NULL){
        if (temp->x == x){
            return temp;
        }
        temp = temp->sig;
    }
    return NULL;
}


NodoMatriz* MatrizCapa::insertarOrdColumna(NodoMatriz *nuevo, NodoMatriz *cabeza_col){

    NodoMatriz *temp = cabeza_col;
    bool bandera = false;
    while (true){
        if (temp->x == nuevo->x){
            temp->y = nuevo->y;
            temp->color = nuevo->color;
            return temp;
        }else if(temp->x > nuevo->x){
            bandera = true;
            break;
        }
        if (temp->sig != NULL){
            temp = temp->sig;
        }else{
            bandera = false;
            break;
        }
    }
    if (bandera){
        nuevo->sig = temp;
        temp->ant->sig = nuevo;
        nuevo->ant = temp->ant;
        temp->ant = nuevo;
    }else{
        temp->sig = nuevo;
        nuevo->ant = temp;
    }
    return nuevo;


}

NodoMatriz* MatrizCapa::insertarOrdFila(NodoMatriz *nuevo, NodoMatriz *cabeza_fil){
    NodoMatriz *temp = cabeza_fil;
    bool bandera = true;
    while (true){
        if (temp->y == nuevo->y){
            temp->x = nuevo->x;
            temp->color = nuevo->color;
            return temp;
        }else if(temp->y > nuevo->y){
            bandera = true;
            break;
        }
        if (temp->abajo != NULL){
            temp = temp->abajo;

        }else{
            bandera = false;
            break;
        }
    }
    if (bandera) {
        nuevo->abajo = temp;
        temp->arri->abajo = nuevo;
        nuevo->arri = temp->arri;
        temp->arri = nuevo;
    }else{
        temp->abajo = nuevo;
        nuevo->arri = temp;
    }
    return nuevo;

}

NodoMatriz * MatrizCapa::crearColumna(int x){
    NodoMatriz *cabeza_columna = this->root;
    NodoMatriz *columna = insertarOrdColumna(new NodoMatriz(x, -1, "COL"), cabeza_columna);
    return columna;
}

NodoMatriz * MatrizCapa::crearFila(int y){
    NodoMatriz *cabeza_fila = this->root;
    NodoMatriz *fila = insertarOrdFila(new NodoMatriz(-1, y, "FIL"), cabeza_fila);
    return fila;
}

void MatrizCapa::insertarColor(int x, int y, string color){
    NodoMatriz *nuevo = new NodoMatriz(x, y, color);
    NodoMatriz *nodoColumna = buscarColumna(x);
    NodoMatriz *nodoFila = buscarFila(y);


    if (nodoColumna == NULL && nodoFila == NULL)
    {
        nodoColumna = crearColumna(x);
        nodoFila = crearFila(y);


        nuevo = insertarOrdColumna(nuevo, nodoFila);
        nuevo = insertarOrdFila(nuevo, nodoColumna);
        return;

    }else if (nodoColumna == NULL && nodoFila != NULL){

        nodoColumna = crearColumna(x);

        nuevo = insertarOrdColumna(nuevo, nodoFila);
        nuevo = insertarOrdFila(nuevo, nodoColumna);
        return;

    }else if (nodoColumna != NULL && nodoFila == NULL){

        nodoFila = crearFila(y);

        nuevo = insertarOrdColumna(nuevo, nodoFila);
        nuevo = insertarOrdFila(nuevo, nodoColumna);
        return;

    }else if (nodoColumna != NULL && nodoFila != NULL){

        nuevo = insertarOrdColumna(nuevo, nodoFila);
        nuevo = insertarOrdFila(nuevo, nodoColumna);

    }
}


void MatrizCapa::graficar(string priori){
    NodoMatriz *rrFil = this->root;
    NodoMatriz *rrCol = this->root;

    string grafica = "digraph g { \n";
    grafica += "node[shape=box, color=cornflowerblue];";
    while(rrCol != NULL){
        grafica += "\n subgraph {";
        while(rrFil != NULL){
            stringstream rr3;
            stringstream rr4;
            rr3 << rrFil->x;
            rr4 << rrFil->y;
            string s3 = rr3.str();
            string s4 = rr4.str();
            grafica += "\"" + s3 + "," + s4 + " " + rrFil->color + "\" \n";
            rrFil = rrFil->abajo;
            if(rrFil != NULL){
                stringstream rr3;
                stringstream rr4;
                rr3 << rrFil->x;
                rr4 << rrFil->y;
                string s3 = rr3.str();
                string s4 = rr4.str();
                grafica += "-> \"" + s3+ "," + s4 + " " + rrFil->color + "\" [dir=\"both\"] \n";
            }
        }
        rrCol = rrCol->sig;
        if(rrFil == NULL){
            rrFil = rrCol;
        }
         grafica += "}";
    }
    rrFil = this->root;
    rrCol = this->root;

    while(rrFil != NULL){
        grafica += "\n rank=same{";
        while(rrCol != NULL){
            stringstream rr3;
            stringstream rr4;
            rr3 << rrCol->x;
            rr4 << rrCol->y;
            string s3 = rr3.str();
            string s4 = rr4.str();
            grafica += "\"" + s3 + "," + s4 + " " + rrCol->color + "\" \n";
            rrCol = rrCol->sig;
            if(rrCol != NULL){
                stringstream rr3;
                stringstream rr4;
                rr3 << rrCol->x;
                rr4 << rrCol->y;
                string s3 = rr3.str();
                string s4 = rr4.str();
                grafica += "-> \"" + s3+ "," + s4 + " " + rrCol->color + "\" [dir=\"both\"] \n";
            }
        }
        rrFil = rrFil->abajo;
        if(rrCol == NULL){
            rrCol = rrFil;
        }
          grafica += "}";
    }


    grafica += "}";

    ofstream file;
    file.open("graf.dot");
    file << grafica;
    file.close();
    string sys = "dot graf.dot -o Capas\\capa"+priori+".jpg -Tjpg -Gcharset=utf8";
    cout << priori << endl;
    const char *s = sys.c_str();
    system(s);
    //system("\\c start imagen.jpg");

    //cout << "\n Listo :)" << endl;

}

void MatrizCapa::graficarDouble(){
    NodoMatriz *rrFil = this->root;
    NodoMatriz *rrCol = this->root;

    string grafica = "digraph g { \n";
    grafica += "node[shape=box, color=cornflowerblue];";
    while(rrFil != NULL){
        grafica += "\n subgraph {";
        while(rrCol != NULL){
            stringstream rr3;
            stringstream rr4;
            rr3 << rrCol->x;
            rr4 << rrFil->y;
            string s3 = rr3.str();
            string s4 = rr4.str();
            grafica += "\"" + s3 + "," + s4 + " " + rrCol->color + "\" \n";
            rrCol = rrCol->sig;
            if(rrCol != NULL){
                stringstream rr3;
                stringstream rr4;
                rr3 << rrCol->x;
                rr4 << rrCol->y;
                string s3 = rr3.str();
                string s4 = rr4.str();
                grafica += "-> \"" + s3+ "," + s4 + " " + rrCol->color + "\" [dir=\"both\"] \n";
            }
        }
        rrFil = rrFil->abajo;
        if(rrCol == NULL){
            rrCol = rrFil;
        }
         grafica += "}";
    }
    rrFil = this->root;
    rrCol = this->root;

    while(rrCol != NULL){
        grafica += "\n rank=same{";
        while(rrFil != NULL){
            stringstream rr3;
            stringstream rr4;
            rr3 << rrFil->x;
            rr4 << rrFil->y;
            string s3 = rr3.str();
            string s4 = rr4.str();
            grafica += "\"" + s3 + "," + s4 + " " + rrFil->color + "\" \n";
            rrFil = rrFil->abajo;
            if(rrFil != NULL){
                stringstream rr3;
                stringstream rr4;
                rr3 << rrFil->x;
                rr4 << rrFil->y;
                string s3 = rr3.str();
                string s4 = rr4.str();
                grafica += "-> \"" + s3+ "," + s4 + " " + rrFil->color + "\" [dir=\"both\"] \n";
            }
        }
        rrCol = rrCol->sig;
        if(rrFil == NULL){
            rrFil = rrCol;
        }
          grafica += "}";
    }


    grafica += "}";

    ofstream file;
    file.open("graf.dot");
    file << grafica;
    file.close();
    string sys = "dot graf.dot -o Filtros\\Double.jpg -Tjpg -Gcharset=utf8";
    const char *s = sys.c_str();
    system(s);
    //system("\\c start imagen.jpg");

    //cout << "\n Listo :)" << endl;

}


void MatrizCapa::crearLienzo(string lienzo){
    ifstream archivos;
    string texto;
    int x=-1, y=-1;
    archivos.open(lienzo,ios::in);
    while(getline(archivos, texto)){
        stringstream ss(texto);
        x++;
        y=0;
        while(getline(ss, texto, ',')){
            if(texto != "X" && texto != "x" ){
                insertarColor(y,x,texto);
                //cout << y << " , " << x << " " << texto << endl;
            }
            y++;
        }
        ss.clear();
    }
    graficar("Lienzo");
}

void MatrizCapa::pintarHTML(string confi, string archi){

    ifstream archivos;
    string texto;
    string imgw, imgh, pixw, pixh;
    int x=-1, y=-1;
    archivos.open(confi,ios::in);
    while(getline(archivos, texto)){
        stringstream ss(texto);
        x++;
        y=0;
        while(getline(ss, texto, ',')){
            switch(y){
            case 1:
                if(texto != "Value" && texto != "value"){
                    switch(x){
                    case 1:
                        imgw = texto;
                        break;
                    case 2:
                        imgh = texto;
                        break;
                    case 3:
                        pixw = texto;
                        break;
                    case 4:
                        pixh = texto;
                        break;
                    }
                }
                break;
            }
            y++;
        }
        ss.clear();
    }

    int tot = atoi(imgw.c_str())*atoi(imgh.c_str());
    int sumpix = 0;

    string grafica = "<!DOCTYPE html><html>\n<head><!-- Link to our stylesheet Painting our Pixel Art --> \n";
    grafica += "<link rel=\"stylesheet\" href=\""+archi+".css\">\n</head>\n<body>\n<!-- div container representing the canvas -->\n";
    grafica += "<div class=\"canvas\">\n";
    //cout << tot << endl;
    while(sumpix != tot){
        grafica += "<div class=\"pixel\"></div>\n";
        sumpix++;
    }
/*
    string estilo="body {\n background: #333333;\n height: 100vh;\n display: flex;\n justify-content: center;\n ";
    estilo +="align-items: center;\n} \n .canvas {\n width: 480px;\n height: 480px;\n}\n";
    estilo +=".pixel {\n width: "+pixw+"px;\n height: "+pixh+"px;\n float: left;\n }\n";

    NodoMatriz *rrFil = this->root;
    NodoMatriz *rrCol = this->root;

    while(rrCol != NULL){
        while(rrFil != NULL){
            stringstream rr3;
            stringstream rr4;
            rr3 << rrFil->x;
            rr4 << rrFil->y;
            string s3 = rr3.str();
            string s4 = rr4.str();
            grafica += " .pixel:nth-child(5), \n " + s3 + "," + s4 + " " + rrFil->color + "\" \n";
            rrFil = rrFil->abajo;
        }
    }
*/
    grafica += "</div>\n</body>\n</html>";

    ofstream file;
    file.open("Export\\"+archi+".html");
    file << grafica;
    file.close();

    //system("\\c start imagen.jpg");

    //cout << "\n Listo :)" << endl;

}

MatrizCapa::~MatrizCapa()
{
    //dtor
}
