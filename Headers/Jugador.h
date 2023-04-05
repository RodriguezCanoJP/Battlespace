//
// Created by juanpablo on 04/04/23.
//

#ifndef UNTITLED_JUGADOR_H
#define UNTITLED_JUGADOR_H
#include <SFML/Graphics.hpp>

class Jugador{
protected:
    //Sprite
    sf::Texture texture;
    sf::Sprite sprite;
    //Posiciones
    int x;
    int y;
public:
    //Destructor
    Jugador();
    ~Jugador();
    //Funciones publicas
    void update(int up, int down);
    int getX();
    int getY();
    sf::Sprite getSprite(); //retorna el sprite del jugador
};


#endif //UNTITLED_JUGADOR_H
