//
// Created by juanpablo on 07/04/23.
//

#include "Headers/ListaEnlazada.h"
#include "Headers/Enemigo.h"
#include <iostream>

ListaEnlazada::ListaEnlazada(){
    this->head = nullptr;
    this->size = 0;
};

ListaEnlazada::~ListaEnlazada() {
    for(int i = 0; i < size; i++){
        eliminar(this->head);
    }
};

Enemigo *ListaEnlazada::getNave() {
    return head;
}

void ListaEnlazada::insertar(Enemigo* nave) {
    if(this->head == nullptr){
        this->head = nave;
    }else {
        Enemigo *temp = this->head;
        nave->setNext(temp);
        this->head = nave;
        temp->setPrevious(nave);
        this->size++;
    }
}

void ListaEnlazada::eliminar(Enemigo* nave) {
    if(this->isEmpty()){
        std::cout << "Lista vacia" << "\n";
    }else{
        Enemigo* target = this->head;
        for(int i = 0; i < size; i++){
            if(target = nave){
                break;
            }else{
                target = target->getNext();
            }
        }
        Enemigo* prev = target->getPrevious();
        Enemigo* nex = target->getNext();
        if(nex != nullptr){
            nex->setPrevious(prev);
            if(prev == nullptr){
                this->head = nex;
                delete target;
                this->size --;
            }else{
                prev->setNext(nex);
                delete target;
                this->size --;
            }
        }
    }

}

bool ListaEnlazada::isEmpty(){
    return this->size == 0;
}

int ListaEnlazada::ssize() {
    return this->size;
}




