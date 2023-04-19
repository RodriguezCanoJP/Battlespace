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

    /**
     * retorna el primer enemigo en la lista
     * @return Enemigo*
     */
    Enemigo* getNave();

    /**
     * inserta un enemigo al principio de la lista
     * @param nave *Enemigo
     */
    void insertar(Enemigo* nave);

    /**
     * elimina una nave en la lista
     * @param nave puntero del enemigo
     */
    void eliminar(Enemigo* nave);

    /**
     * retorna el tamano actual de la lista
     * @return
     */
    int ssize();

    /**
     * retorna un valor booleano que indica si la lista esta vacia
     * @return
     */
    bool isEmpty();

};


#endif //UNTITLED_LISTAENLAZADA_H
