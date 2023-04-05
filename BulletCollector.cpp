//
// Created by juanpablo on 04/04/23.
//

#include "Headers/BulletCollector.h"

BulletCollector::BulletCollector() {

}

BulletCollector::~BulletCollector() {

}

void BulletCollector::reciclar(void *ptr) {
    punteros.push_back(ptr);
}

void *BulletCollector::reusar(size_t size) {
    if(punteros.empty()){
        void* puntero = (void*) malloc(size);
        return puntero;
    }else{
        void* puntero = punteros[0];
        punteros.erase(punteros.begin());
        return puntero;
    }
}

void BulletCollector::liberar() {
 for(int i = 0; i<punteros.size(); i++){
     free(punteros[i]);
 }
}

void* BulletCollector::lista_punteros() {
    return punteros[0];
}
