//
// Created by juanpablo on 07/04/23.
//

#ifndef UNTITLED_LISTAENLAZADA_H
#define UNTITLED_LISTAENLAZADA_H
#include "Enemigo.h"

class ListaEnlazada {
private:
    Enemigo* head;
    int size;
public:
    ///Constructor/Destructor
    ListaEnlazada();
    ~ListaEnlazada();

    Enemigo* getNave();
    void insertar(Enemigo* nave);
    void eliminar(Enemigo* nave);
    int ssize();
    bool isEmpty();

};


#endif //UNTITLED_LISTAENLAZADA_H
