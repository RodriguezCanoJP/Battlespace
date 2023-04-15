//
// Created by juanpablo on 06/04/23.
//

#include "Headers/Enemigo.h"

Enemigo::Enemigo(int type) {
    this->x = 800;
    this->init = false;
    this->next = nullptr;
    this->previous = nullptr;
    this->type = type;
    if(type == 1){
        this->texture.loadFromFile("/home/juanpablo/CLionProjects/Battlespace/Images/Enemigo2.png");
        this->health = 100;
    }else if(type == 2){
        this->texture.loadFromFile("/home/juanpablo/CLionProjects/Battlespace/Images/Enemigo1.png");
        this->health = 120;
    }else if(type == 3){
        this->up = 1;
        this->texture.loadFromFile("/home/juanpablo/CLionProjects/Battlespace/Images/Enemigo3.png");
        this->health = 120;
    }
    this->sprite.setTexture(texture);
    this->sprite.setPosition(this->x, 400);
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
    if(this->type == 3){
        if(this->y >= 390){
            this->up = -1;
        }else if(this->y <= 10){
            this->up = 1;
        }
        this->x -= vel;
        this->y += (vel*up);
        this->sprite.setPosition(this->x, this->y);
    }else{
        this->x -= vel;
        this->sprite.setPosition(this->x, this->y);
    }

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

bool Enemigo::getDead() {
    return this->health <= 0;
}

void Enemigo::setDamage(int dmg) {
    this->health -= dmg;
}








