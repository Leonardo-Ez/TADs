//
// Created by hecto on 13/11/2026.
//

#ifndef TADS_BASE_LISTA_H
#define TADS_BASE_LISTA_H

#include "Nodo.h"

template <typename T>
class Lista {
    Nodo<T> *inicio;
    Nodo<T> *fin;
    int numNodos;
public:
    Lista() : inicio(nullptr), numNodos(0),fin(nullptr) {}

    ~Lista() {
        destruirRecursivo(this->inicio);
        this->inicio = nullptr;
        this->numNodos = 0;
    }

    Lista(const Lista &lista) {
        //para copiar una lista tendremos que copiar todos los nodos de la lista original
        this->inicio=copiarRecursivo(lista.inicio);
        this->numNodos = lista.numNodos;
    }

    //metodos útiles:
    int get_num_nodos() const {
        return this->numNodos;
    }


    void insertarDatoInicio(const T dato) {
        //un nuevo nodo con el dato y apuntando al inicio de la lista
        Nodo<T> *nuevoNodo = new Nodo<T>(dato,this->inicio);
        this->inicio = nuevoNodo;//movemos el inicio al nuevo nodo
        if (!fin)
            this->fin =nuevoNodo;
        this->numNodos++;
    }

    void insertarDatoFinal(const T dato) {
        Nodo<T> *nuevoNodo = new Nodo<T>(dato,nullptr);
        //creamos un nuevo nodo que apunte a nullptr
        if (this->fin!=nullptr)
            this->fin->set_siguiente(nuevoNodo);//cambiar a dónde apunta el último nodo
        this->fin=nuevoNodo;
        if (!this->inicio)
            this->inicio=nuevoNodo;
        this->numNodos++;
    }



private:

    /*
     * los metodos para manipular los punteros si son privados para que no se puedan manipular
     */
    void set_num_nodos(int num_nodos) {
        this->numNodos = num_nodos;
    }

    Nodo<T> * get_inicio() const {
        return this->inicio;
    }
    void set_inicio(Nodo<T> *inicio) {
        this->inicio = inicio;
    }

    Nodo<T> * get_fin() const {
        return this->fin;
    }

    void set_fin(Nodo<T> *fin) {
        this->fin = fin;
    }

    void destruirRecursivo(Nodo<T> *nodo) {
        if (nodo == nullptr) {
            this->fin = nullptr;
            return;
        }
        destruirRecursivo(nodo->get_siguiente());
        delete nodo;
    }

    Nodo<T> *copiarRecursivo(const Nodo<T> *inicio) {
        if (inicio->get_siguiente() == nullptr) {
            Nodo<T>*ultimo=new Nodo<T>(inicio->get_dato(),nullptr);
            set_fin(ultimo);
            return ultimo;
        }
        return new Nodo<T>(inicio->get_dato(),
            copiarRecursivo(inicio->get_siguiente()));
    }

};




#endif //TADS_BASE_LISTA_H
