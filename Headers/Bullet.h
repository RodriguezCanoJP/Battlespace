//
// Created by juanpablo on 04/04/23.
//

#ifndef UNTITLED_BULLET_H
#define UNTITLED_BULLET_H
#include <SFML/Graphics.hpp>
#include "BulletCollector.h"

class Bullet{
protected:
    sf::Texture texture; ///< textura del sprite
    sf::Sprite sprite; ///< objeto sprite
    int x; ///< posicion en el eje x
    int y; ///< posicion en el eje y
    int dmg; ///< dano de la bala
public:
    static BulletCollector collector;
    ///Constructor/Destructor
    Bullet(int damage);
    ~Bullet();

    /**
     * Actualiza la posicion de la bala
     * @param y posicion actual de la nave
     * @param velocity velocidad en el eje x
     */
    void setPath(int y);

    void update(float vel);

    /**
     * Retorna la posicion en el eje x
     * @return int x
     */
    int getX();

    /**
     * Retorna la posicion en el eje y
     * @return int y
     */
    int getY();

    /**
     * Retorna el sprite del jugador
     * @return Sprte sprite
     */
    sf::Sprite getSprite();

    /**
     * Consulta si la bala esta fuera de la pantalla
     * @return bool
     */
    bool outOfBounds();

    ///Operadores
    void* operator new(size_t size);
    void operator delete(void* p);
};


#endif //UNTITLED_BULLET_H
