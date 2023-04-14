//
// Created by juanpablo on 06/04/23.
//

#ifndef UNTITLED_ENEMIGO_H
#define UNTITLED_ENEMIGO_H
#include <SFML/Graphics.hpp>

class Enemigo {
protected:
    Enemigo* next;
    Enemigo* previous;
    sf::Texture texture; ///< textura del sprite
    sf::Sprite sprite; ///< objeto sprite
    int health;
    int x; ///< posicion en el eje x
    int y; ///< posicion en el eje y
    bool init;

public:
    ///Constructor/Destructor
    Enemigo(int type);
    ~Enemigo();

    Enemigo* getNext();
    Enemigo* getPrevious();
    void setNext(Enemigo* enemigo);
    void setPrevious(Enemigo* enemigo);

    bool getDead();

    void setDamage(int dmg);

    void setPos(int x, int y){
        this->x = x;
        this->y = y;
    }
    /**
     * Actualiza la posicion de la nave del jugador
     * @param up cantidad de movimiento hacia arriba
     * @param down cantidad de movimiento hacia abajo
     */
    void update(int vel);

    /**
     * Retorna la posicion del jugador en el eje x
     * @return int x
     */
    int getX() const;

    /**
     * Retorna la posicion del jugador en el eje y
     * @return int y
     */
    int getY() const;

    /**
     * Retorna el sprite del objeto de jugador
     * @return Sprite sprite
     */
    sf::Sprite getSprite(); //retorna el sprite del jugador

    bool getInit();
    void setInit();
};


#endif //UNTITLED_ENEMIGO_H
