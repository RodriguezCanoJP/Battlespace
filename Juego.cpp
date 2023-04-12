//
// Created by juanpablo on 04/04/23.
//

#include "Headers/Juego.h"
#include <iostream>


void Juego::initVars(){
    this->window = nullptr;
    this->bullet_vel = 1;
    this->bullet_qty = 10;
    this->bullet_dmg = 10;
    this->vel_enemigo = 1;
    this->delay = 0.1;
    this->delay *= CLOCKS_PER_SEC;
    this->cargaBalas(this->bullet_qty, this->bullet_dmg);
    this->cargaEnemigos(10);
    this->bullet_qty = 0;
    this->enemy_clock = clock();
    this->bullet_clock = clock();
}

void Juego::initWindow() {
    this->video_mode.height = 400;
    this->video_mode.width = 800;
    this->window = new sf::RenderWindow(this->video_mode, "Battlespace");
    this->window->setFramerateLimit(144);
    this->vel_jugador = 3;
}

Juego::Juego() {
    this->initVars();
    this->initWindow();
}

Juego::~Juego() {
    delete this->window;
    Bullet::collector.liberar();
}

const bool Juego::running() const {
    return this->window->isOpen();
}

void Juego::cargaBalas(int qty, int dmg){
    for (int i = 0; i < qty; ++i) {
        Bullet *new_bullet = new Bullet(dmg);
        this->bullets_disponibles.push_back(new_bullet);
    }
}

void Juego::cargaEnemigos(int size) {
    for(int i = 0; i < size; i++){
        this->lista_enemigos.insertar(new Enemigo());
    }
}

void Juego::resetBulletClock() {
    this->bullet_clock = clock();
}

void Juego::resetEnemyClock() {
    this->enemy_clock = clock();
}

void Juego::pollEvents() {
    while(this->window->pollEvent(this->ev)){
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
        }
    }
}


void Juego::movJugador() {
    if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->jugador.update(vel_jugador,0);
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->jugador.update(0,vel_jugador);
    }
}

void Juego::setEnemigos(Enemigo* nave){
    srand(time(NULL));
    nave->setPos(800, rand()%400);
    nave->setInit();
}

void Juego::movEnemigos() {
    Enemigo* nave = this->lista_enemigos.getNave();
    if(!this->lista_enemigos.isEmpty()){
        for(int i=0; i < this->lista_enemigos.ssize(); i++){
            if(nave->getInit()){
                nave->update(vel_enemigo);
                if(nave->getNext() != nullptr){
                    nave = nave->getNext();
                }

            }else{
                if(clock() - this->enemy_clock >= delay){
                    this->setEnemigos(nave);
                    this->resetEnemyClock();
                    break;
                }else{
                    break;
                }
            }
        }
    }

}


void Juego::disparo() {
    if(!this->bullets_disponibles.empty()) {
        if(clock() - this->bullet_clock >= delay) {
            if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                this->bullets_usadas.insert(this->bullets_usadas.begin(), this->bullets_disponibles[0]);
                this->bullets_disponibles.erase(this->bullets_disponibles.begin());
                this->bullets_usadas[0]->setPath(this->jugador.getY() + 8);
                this->resetBulletClock();
            }
        }
    }else{
        this->bullet_dmg -= 3;
        cargaBalas(this->bullet_qty, this->bullet_dmg);
    }
}

void Juego::movBalas() {
    if(!this->bullets_usadas.empty()) {
        for(int i = 0; i < bullets_usadas.size(); i++){
            this->bullets_usadas[i]->update(bullet_vel);
        }
        this->reciclaBalas();
    }
}

void Juego::reciclaBalas() {
    if(this->bullets_usadas[0]->getX() >= 800){
        delete this->bullets_usadas[0];
        this->bullets_usadas.erase(this->bullets_usadas.begin());
        this->bullet_qty++;
    }
}

void Juego::update() {
    this->pollEvents();
    this->movJugador();
    this->disparo();
    this->movBalas();
    this->movEnemigos();
}

void Juego::render() {
    this->window->clear(sf::Color().Cyan);
    this->window->draw(jugador.getSprite());
    if(!this->bullets_usadas.empty()){
        for(int i = 0; i < bullets_usadas.size(); i++) {
            this->window->draw(bullets_usadas[i]->getSprite());
        }
    }
    if(!this->lista_enemigos.isEmpty()){
        Enemigo* nave = lista_enemigos.getNave();
        for(int i = 0; i < lista_enemigos.ssize(); i++) {
            this->window->draw(nave->getSprite());
            if(nave->getNext() != nullptr){
                nave = nave->getNext();
            }
        }
    }
    this->window->display();
}














