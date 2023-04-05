//
// Created by juanpablo on 04/04/23.
//

#ifndef UNTITLED_JUGADOR_H
#define UNTITLED_JUGADOR_H
#include <SFML/Graphics.hpp>

class Jugador{
protected:
    sf::Texture texture; ///< textura del sprite
    sf::Sprite sprite; ///< objeto sprite
    int x; ///< posicion en el eje x
    int y; ///< posicion en el eje y
public:
    ///Constructor/Destructor
    Jugador();
    ~Jugador();

    /**
     * Actualiza la posicion de la nave del jugador
     * @param up cantidad de movimiento hacia arriba
     * @param down cantidad de movimiento hacia abajo
     */
    void update(int up, int down);

    /**
     * Retorna la posicion del jugador en el eje x
     * @return int x
     */
    int getX();

    /**
     * Retorna la posicion del jugador en el eje y
     * @return int y
     */
    int getY();

    /**
     * Retorna el sprite del objeto de jugador
     * @return Sprite sprite
     */
    sf::Sprite getSprite(); //retorna el sprite del jugador
};


#endif //UNTITLED_JUGADOR_H
