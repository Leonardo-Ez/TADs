//
// Created by hecto on 13/11/2026.
//

#ifndef TADS_BASE_NODO_H
#define TADS_BASE_NODO_H

template <typename T>
class Nodo {
    T dato;
    Nodo<T> *siguiente;
public:
    //constructores
    Nodo() : dato(), siguiente(nullptr) {}
    Nodo(const Nodo &nodo) : dato(nodo.dato), siguiente(nodo.siguiente) {}
    Nodo(const T dato,Nodo<T> *siguiente):dato(dato), siguiente(siguiente) {}
    ~Nodo()=default;//destructor por defecto

    //getters y setters
    T get_dato() const { return dato; }
    void set_dato(const T &dato) { this->dato = dato; }

    Nodo<T> *get_siguiente() const { return siguiente; }
    void set_siguiente(Nodo<T> *siguiente) { this->siguiente = siguiente; }
};


#endif //TADS_BASE_NODO_H
