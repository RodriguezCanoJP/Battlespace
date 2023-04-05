//
// Created by juanpablo on 04/04/23.
//

#include "Headers/Bullet.h"

Bullet::Bullet() {
    texture.loadFromFile("/home/juanpablo/CLionProjects/Battlespace/Images/bullet.png");
    sprite.setTexture(texture);
    x = 60;
    y = 0;
}

Bullet::~Bullet() {

}

BulletCollector Bullet::collector;

void Bullet::setPath(int y){
    this->y = y;
}

void Bullet::setPos(float velocity) {
    this->x += velocity;
    this->sprite.setPosition(this->x, this->y);
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


