//
// Created by juanpablo on 04/04/23.
//

#ifndef UNTITLED_BULLETCOLLECTOR_H
#define UNTITLED_BULLETCOLLECTOR_H
#include <iostream>
#include <vector>

class BulletCollector {
private:
    std::vector <void*> punteros;
public:
    BulletCollector();
    ~BulletCollector();
    void reciclar(void* ptr);
    void* reusar(size_t size);
    void liberar();
    void lista_punteros();

};


#endif //UNTITLED_BULLETCOLLECTOR_H
