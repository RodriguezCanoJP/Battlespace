//
// Created by juanpablo on 04/04/23.
//
#include <SFML/Graphics.hpp>

#ifndef UNTITLED_JUEGO_H
#define UNTITLED_JUEGO_H


class Juego {
private:
    sf::RenderWindow* window;
    sf::Event ev;
    sf::VideoMode videoMode;

    //Funciones privadas
    void initVars();
    void initWindow();
public:
    //Constructor/Destructor
    Juego();
    ~Juego();

    //Funciones
    const bool running() const;
    void pollEvents();
    void update();
    void render();

};


#endif //UNTITLED_JUEGO_H
