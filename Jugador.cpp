//
// Created by juanpablo on 04/04/23.
//

#include "Jugador.h"

Jugador::Jugador() {
    this->x = 20;
    this->y = 200;
    this->texture.loadFromFile("/home/juanpablo/CLionProjects/Battlespace/Images/Jugador.png");
    this->sprite.setTexture(texture);
    this->sprite.setPosition(this->x, this->y);
}

Jugador::~Jugador() {
}

void Jugador::update(int up, int down) {
    if(this->y <= 0){
        this->y += 1;
    }else if(this->y + 25 >= 399){
        this->y -= 1;
    }else{
        this->y += down - up;
    }
    this->sprite.setPosition(this->x, this->y);
}

int Jugador::getX() {
    return this->x;
}

int Jugador::getY() {
    return this->y;
}

sf::Sprite Jugador::getSprite() {
    return this->sprite;
}
