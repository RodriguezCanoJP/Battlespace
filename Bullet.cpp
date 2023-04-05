//
// Created by juanpablo on 04/04/23.
//

#include "Headers/Bullet.h"

Bullet::Bullet() {
    texture.loadFromFile("/home/juanpablo/CLionProjects/Battlespace/Images/Bullet.png");
    sprite.setTexture(texture);
}

Bullet::~Bullet() {

}

BulletCollector Bullet::collector;

void Bullet::update(int y, int velocity) {
    this->y = y;
    while(!outOfBounds()){
        this->x += velocity;
        sprite.setPosition(this->x, this->y);
    }
}

int Bullet::getX() {
    return this->x;
}

int Bullet::getY() {
    return this->y;
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


