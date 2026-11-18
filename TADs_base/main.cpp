#include "Biblioteca/Lista.h"


bool compararInt(const int &a,const int &b) {
    return a<b;
}

int main() {
    /*
     * prueba de listas
     */
    Lista<int> listaEnteros;

    /*
     * insertarNodo delante y detrás
     */
    listaEnteros.insertarDatoInicio(1);
    listaEnteros.insertarDatoFinal(10);
    /*
     * insertar nodo de forma ordenada con un puntero a función
     */
    listaEnteros.insertarOrdenado(0,compararInt);
    listaEnteros.insertarOrdenado(15,compararInt);
    listaEnteros.insertarOrdenado(20,compararInt);
    listaEnteros.insertarOrdenado(12,compararInt);

    return 0;
}