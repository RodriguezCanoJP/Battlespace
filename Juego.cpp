//
// Created by juanpablo on 04/04/23.
//

#include "Headers/Juego.h"
#include <iostream>


void Juego::initVars(){
    this->window = nullptr;
    this->bullet_vel = 1;
    this->bullet_qty = 10;
    this->delay = 0.1;
    delay *= CLOCKS_PER_SEC;
    this->now = clock();
    for (int i = 0; i < this->bullet_qty; ++i) {
        Bullet* new_bullet = new Bullet();
        this->bullets_disponibles.push_back(new_bullet);
    }
}

void Juego::initWindow() {
    this->videoMode.height = 400;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Battlespace");
    this->window->setFramerateLimit(144);
    velJugador = 3;
}

Juego::Juego() {
    this->initVars();
    this->initWindow();
}

Juego::~Juego() {
    delete this->window;
    Bullet().collector.liberar();
}

const bool Juego::running() const {
    return this->window->isOpen();
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
        jugador.update(velJugador,0);
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        jugador.update(0,velJugador);
    }
}

void Juego::disparo() {
    if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        this->bullets_usadas.insert(this->bullets_usadas.begin(), this->bullets_disponibles[0]);
        this->bullets_disponibles.erase(this->bullets_disponibles.begin());
        this->bullets_usadas[0]->setPath(this->jugador.getY() + 8);
        this->reset_clock();
    }

}

void Juego::recicla_balas() {
    if(this->bullets_usadas[0]->getX() >=800){
        delete this->bullets_usadas[0];
        this->bullets_usadas.erase(this->bullets_usadas.begin());
    }
}

void Juego::update() {
    this->pollEvents();
    this->movJugador();
    if(!this->bullets_disponibles.empty()){
        if(clock() - this-> now >= delay){
            this->disparo();
        }
    }else{
        Bullet().collector.lista_punteros();
        for(int i = 0; i < this->bullet_qty; i++){
            Bullet* new_bullet = new Bullet();
            this->bullets_disponibles.push_back(new_bullet);
        }
    }

    if(!this->bullets_usadas.empty()) {
        for(int i = 0; i < bullets_usadas.size(); i++){
            this->bullets_usadas[i]->setPos(bullet_vel);
        }
        this->recicla_balas();
    }
}

void Juego::render() {
    this->window->clear(sf::Color().Cyan);
    this->window->draw(jugador.getSprite());
    if(!this->bullets_usadas.empty()){
        for(int i = 0; i < bullets_usadas.size(); i++) {
            this->window->draw(bullets_usadas[i]->getSprite());
        }
    }
    this->window->display();
}

void Juego::reset_clock() {
    this->now = clock();
}




