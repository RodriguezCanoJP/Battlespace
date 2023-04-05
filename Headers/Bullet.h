//
// Created by juanpablo on 04/04/23.
//

#ifndef UNTITLED_BULLET_H
#define UNTITLED_BULLET_H
#include <SFML/Graphics.hpp>
#include "BulletCollector.h"

class Bullet{
protected:
    //Sprite
    sf::Texture texture;
    sf::Sprite sprite;
    //Posiciones
    int x;
    int y;
    int dmg;
public:
    static BulletCollector collector;
    //Destructor
    Bullet();
    ~Bullet();
    //Funciones publicas
    void update(int y, int velocity);
    int getX();
    int getY();
    sf::Sprite getSprite(); //retorna el sprite del jugador
    //Operadores
    void* operator new(size_t size);
    void operator delete(void* p);
};


#endif //UNTITLED_BULLET_H
