//
// Created by juanpablo on 06/04/23.
//

#include "Headers/Enemigo.h"

Enemigo::Enemigo() {
    this->init = false;
    this->next = nullptr;
    this->previous = nullptr;
    this->texture.loadFromFile("/home/juanpablo/CLionProjects/Battlespace/Images/Enemigo2.png");
    this->sprite.setTexture(texture);
}

Enemigo::~Enemigo() = default;

Enemigo* Enemigo::getNext() {
    return this->next;
}

Enemigo *Enemigo::getPrevious() {
    return this->previous;
}

void Enemigo::setNext(Enemigo* enemigo) {
    this->next = enemigo;
}

void Enemigo::setPrevious(Enemigo *enemigo) {
    this->previous = enemigo;
}



void Enemigo::update(int vel) {
    this->x -= vel;
    this->sprite.setPosition(this->x, this->y);
}

int Enemigo::getX() const {
    return this->x;
}

int Enemigo::getY() const {
    return this->y;
}

sf::Sprite Enemigo::getSprite() {
    return this->sprite;
}

bool Enemigo::getInit() {
    return this->init;
}

void Enemigo::setInit() {
    this->init = true;
}








