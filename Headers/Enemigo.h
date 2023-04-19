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
    int type;
    int up;
    int health;
    int x; ///< posicion en el eje x
    int y; ///< posicion en el eje y
    bool init;

public:
    ///Constructor/Destructor
    Enemigo(int type);
    ~Enemigo();

    /**
     * retorna el puntero al siguiente enemigo en la lista
     * @return puntero de Enemigo
     */
    Enemigo* getNext();

    /**
     * retorna el puntero al enemigo anterior en la lista
     * @return puntero Enemigo
     */
    Enemigo* getPrevious();

    /**
     * cambia el puntero del siguiente enemigo en la lista
     * @param enemigo puntero enemigo
     */
    void setNext(Enemigo* enemigo);

    /**
     * cambia el puntero del enemigo anterior en la lista
     * @param enemigo puntero
     */
    void setPrevious(Enemigo* enemigo);

    /**
     * retorna un valor booleano que indica si el enemigo tiene la vida menor a cero
     * @return bool
     */
    bool getDead();

    /**
     * diminuye la vida del enemigo
     * @param dmg
     */
    void setDamage(int dmg);

    /**
     * inicializa la posicion del enemigo en la pantalla
     * @param x
     * @param y
     */
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

    /**
     * retorna un valor booleano que indica si el enemigo ya se inicializo en la pantalla de juego
     * @return bool
     */
    bool getInit();

    /**
     * inicializa el enemigo en la pantalla de juego
     */
    void setInit();
};


#endif //UNTITLED_ENEMIGO_H
