//
// Created by juanpablo on 04/04/23.
//

#ifndef UNTITLED_JUEGO_H
#define UNTITLED_JUEGO_H
#include "Jugador.h"
#include "Bullet.h"
#include "ListaEnlazada.h"
#include <iostream>
#include <string>
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
    float spawn_delay; ///< indica el tiempo entre inicializaciones del enemigo
    float shot_delay; ///< indica el tiempo entre disparos
    int bullet_qty; ///< cantidad de balas disponibles
    int bullet_dmg; ///< impacto de las balas
    int oleada_actual; ///< numero de oleada actual
    clock_t enemy_clock;
    clock_t bullet_clock;
    int dificultad; ///< dificultad seleccionada en el menu
    Oleada oleadas1[5] = {Oleada(3,0,0,15), Oleada(3,2,0,35), Oleada(3,2,1,40), Oleada(3,2,1,50), Oleada(3,3,3,60)};
    Oleada oleadas2[5] = {Oleada(4,0,0,20), Oleada(3,3,0,30), Oleada(4,2,1,35), Oleada(4,3,2,45), Oleada(4,4,4,55)};
    Oleada oleadas3[5] = {Oleada(5,0,0,15), Oleada(4,3,0,25), Oleada(5,2,2,30), Oleada(5,4,3,40), Oleada(5,5,5,50)};
    //Funciones privadas
    void initVars(std::string dif);
    void initWindow();
public:
    //Constructor/Destructor
    /**
     * Inicializa las variables del juego
     */
    Juego(std::string dificultad);

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

    /**
     * retorna un string con el numero de la oleada para ser leido por el arduino
     * @return
     */
    std::string retornaOleada() const;

    /**
     * carga las balas de la oleada en un vector
     * @param qty cantidad de balas
     * @param dmg cantidad de dano de cada bala
     */
    void cargaBalas (int qty, int dmg);

    /**
     * recarga las balas perdidas con un dano reducido
     */
    void recargaBalas();

    /**
     * carga la informacion del arreglo de oleadas
     * @param oleadas
     */
    void cargaOleada(Oleada* oleadas);

    /**
     * carga la lista enlazada que contiene los enemigos de cada oleada
     * @param enemigo1
     * @param enemigo2
     * @param enemigo3
     */
    void cargaEnemigos(int enemigo1, int enemigo2, int enemigo3);

    /**
     * funcion para cambiar la velocidad con entradas del arduino;
     * @param i
     */
    void cambiaVelocidad(int i);

    /**
     * consulta si hay eventos de ventana como presionar la x
     */
    void pollEvents();

    /**
     * Reasigna el valor guardado del tiempo en la variable bullet_clock
     */
    void resetBulletClock();

    /**
     * Reasigna el valor guardado del tiempo en la variable enemy_clock
     */
    void resetEnemyClock();

    /**
     * consulta si hay movimientos de teclado que corresponden a input de movimiento de la nave, llama
     * a los metodos de jugador para actualizar la posicion
     */
    void movJugador();

    /**
     * Inicializa la posicion de las naves enemigas
     * @param nave
     */
    void setEnemigos(Enemigo* nave);

    /**
     * actualiza la posicion de todos los enemigos inicializados y los elimina si se pasan de la posicion del jugador
     */
    void movEnemigos();

    /**
     * consulta si hay movimientos de teclado que corresponden a input de disparo de la nvae, llama
     * a los metodos de Bullet guardado en el vector bullets_disponibles para comenzar su trayectoria
     * y guarda el puntero de este en el vector bullets_usadas
     */
    void disparo();

    /**
     * llama a las funciones de Bullet para mover todas las balas almacenadas en el vector
     */
    void movBalas();

    /**
     * indica si hay colisiones entre enemigos y las balas y los elimina debidamente
     */
    void colisiones();

    /**
     * llama al operador delete de Bullet cuando la bala sale de la pantalla y actualisa bullets_usadas
     */
    void reciclaBalas();

    bool isPlayerDead();

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
