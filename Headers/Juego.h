//
// Created by juanpablo on 04/04/23.
//

#ifndef UNTITLED_JUEGO_H
#define UNTITLED_JUEGO_H
#include "Jugador.h"
#include "Bullet.h"
#include <iostream>
#include <vector>
#include <ctime>

class Juego {
private:
    /// Variables iniciales
    sf::RenderWindow* window; ///< puntero a la ventana
    sf::Event ev; ///< Ya esta inicializado
    sf::VideoMode videoMode; ///< guarda las dimensiones de la ventana
    Jugador jugador; ///< Instancia de la nave del jugador
    float velJugador; ///< velocidad de la nave
    int bullet_qty; ///< cantidad de balas disponibles
    float bullet_vel; ///< velocidad de las balas
    float delay;
    clock_t now;
    std::vector <Bullet*> bullets_disponibles; ///< vector con objetos Bullet disponibles
    std::vector <Bullet*> bullets_usadas; ///< vector con objetos Bullet disparadas

    //Funciones privadas
    void initVars();
    void initWindow();
public:
    //Constructor/Destructor
    /**
     * Inicializa las variables del juego
     */
    Juego();

    /**
     * Elimina ventana
     */
    ~Juego();

    //Funciones publicas
    /**
     * consulta si la ventana de juego sigue abierta
     * @return bool
     */
    const bool running() const;

    /**
     * consulta si hay eventos de ventana como presionar la x
     */
    void pollEvents();

    void reset_clock();

    /**
     * consulta si hay movimientos de teclado que corresponden a input de movimiento de la nave, llama
     * a los metodos de jugador para actualizar la posicion
     */
    void movJugador();

    /**
     * consulta is hay movimientos de teclado que corresponden a input de disparo de la nvae, llama
     * a los metodos de Bullet guardado en el vector bullets_disponibles para comenzar su trayectoria
     * y guarda el puntero de este en el vector bullets_usadas
     */
    void disparo();

    /**
     * llama al operador delete de Bullet cuando la bala sale de la pantalla y actualisa bullets_usadas
     */
    void recicla_balas();

    /**
     * llama a las otras funciones que son recurrentes a traves del juego
     */
    void update();

    /**
     * dibuja los objetos en la ventana
     */
    void render();

};


#endif //UNTITLED_JUEGO_H
