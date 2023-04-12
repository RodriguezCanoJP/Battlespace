//
// Created by juanpablo on 04/04/23.
//

#ifndef UNTITLED_BULLETCOLLECTOR_H
#define UNTITLED_BULLETCOLLECTOR_H
#include <iostream>
#include <vector>

class BulletCollector {
private:
    std::vector <void*> punteros; ///< vector de punteros para reutilizar
public:
    BulletCollector();
    ~BulletCollector();

    /**
     * Recibe el puntero de la memoria de Bullet que va a ser eliminado para ser reusado despues
     * @param ptr
     */
    void reciclar(void* ptr);

    /**
     * Retorna un espacio disponible en memoria para ser utilizado por un objeto bullet
     * @param size de Bullet
     * @return puntero
     */
    void* reusar(size_t size);

    /**
     * libera la memoria asignada en el Heap
     */
    void liberar();

    /**
     * Funcion paa visualizar las direcciones de memoria
     */
    void lista_punteros();



};


#endif //UNTITLED_BULLETCOLLECTOR_H
