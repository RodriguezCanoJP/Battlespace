//
// Created by juanpablo on 04/04/23.
//

#ifndef UNTITLED_JUEGO_H
#define UNTITLED_JUEGO_H
#include "Jugador.h"
#include "Bullet.h"
#include "ListaEnlazada.h"
#include <iostream>
#include <vector>
#include <ctime>


struct Oleada{
public:
    int enemigo1;
    int enemigo2;
    int enemigo3;
    int bullets;
    Oleada(int one, int two, int three, int nbullets):enemigo1(one), enemigo2(two), enemigo3(three), bullets(nbullets){}
};

class Juego {
private:
    /// Variables iniciales
    sf::RenderWindow* window; ///< puntero a la ventana
    sf::Event ev; ///< Ya esta inicializado
    sf::VideoMode video_mode; ///< guarda las dimensiones de la ventana
    sf::Text oleada_text;
    std::vector <Bullet*> bullets_disponibles; ///< vector con objetos Bullet disponibles
    std::vector <Bullet*> bullets_usadas; ///< vector con objetos Bullet disparadas
    Jugador jugador; ///< Instancia de la nave del jugador
    ListaEnlazada lista_enemigos;
    float vel_jugador; ///< velocidad de la nave
    float vel_enemigo; ///< velocidad de las naves enemigas
    float bullet_vel; ///< velocidad de las balas
    float spawn_delay;
    float shot_delay;
    int bullet_qty; ///< cantidad de balas disponibles
    int bullet_dmg; ///< impacto de las balas
    int oleada_actual;
    clock_t enemy_clock;
    clock_t bullet_clock;
    Oleada oleadas[5] = {Oleada(5,0,0,10), Oleada(4,3,0,20), Oleada(5,2,2,25), Oleada(5,4,4,40), Oleada(5,5,5,45)};
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
    bool running() const;

    void cargaBalas (int qty, int dmg);

    void recargaBalas();

    void cargaOleada();

    void cargaEnemigos(int enemigo1, int enemigo2, int enemigo3);

    /**
     * consulta si hay eventos de ventana como presionar la x
     */
    void pollEvents();

    /**
     * Reasigna el valor guardado del tiempo en la variable now
     */
    void resetBulletClock();

    void resetEnemyClock();

    /**
     * consulta si hay movimientos de teclado que corresponden a input de movimiento de la nave, llama
     * a los metodos de jugador para actualizar la posicion
     */
    void movJugador();

    void setEnemigos(Enemigo* nave);

    void movEnemigos();

    /**
     * consulta si hay movimientos de teclado que corresponden a input de disparo de la nvae, llama
     * a los metodos de Bullet guardado en el vector bullets_disponibles para comenzar su trayectoria
     * y guarda el puntero de este en el vector bullets_usadas
     */
    void disparo();

    void movBalas();

    void colisiones();

    /**
     * llama al operador delete de Bullet cuando la bala sale de la pantalla y actualisa bullets_usadas
     */
    void reciclaBalas();

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
