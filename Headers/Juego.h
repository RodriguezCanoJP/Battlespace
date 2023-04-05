//
// Created by juanpablo on 04/04/23.
//

#ifndef UNTITLED_JUEGO_H
#define UNTITLED_JUEGO_H
#include "Jugador.h"
#include "Bullet.h"
#include <iostream>
#include <vector>

class Juego {
private:
    //Variables iniciales
    sf::RenderWindow* window; //puntero a la ventana
    sf::Event ev; //Ya esta inicializado
    sf::VideoMode videoMode; //guarda las dimensiones de la ventana
    Jugador jugador;
    float velJugador;
    int bulletQty;
    std::vector <Bullet*> bullets;


    //Funciones privadas
    void initVars();
    void initWindow();
public:
    //Constructor/Destructor
    Juego();
    ~Juego();

    //Funciones publicas
    const bool running() const;
    void pollEvents();
    void movJugador();
    void disparo();
    void update();
    void render();

};


#endif //UNTITLED_JUEGO_H
