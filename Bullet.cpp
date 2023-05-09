//
// Created by juanpablo on 04/04/23.
//

#include "Headers/Bullet.h"

Bullet::Bullet(int damage) {
    texture.loadFromFile("/home/juanpablo/CLionProjects/Battlespace/Images/bullet.png");
    sprite.setTexture(texture);
    dmg = damage ;
    x = 60; ///< posicion en x de la nave jugador
    y = 0;
}

Bullet::~Bullet() {

}

BulletCollector Bullet::collector;

void Bullet::setPath(int y){
    this->y = y;
}

void Bullet::update(float vel) {
    this->x += vel;
    this->sprite.setPosition(this->x, this->y);
}


int Bullet::getDamage() {
    return this->dmg;
}

sf::Sprite Bullet::getSprite() {
    return this->sprite;
}

void *Bullet::operator new(size_t size) {
    collector.reusar(size);
}

void Bullet::operator delete(void *p) {
    collector.reciclar(p);
}

bool Bullet::outOfBounds() {
    return this->x >= 800;
}




