//
// Created by juanpablo on 04/04/23.
//

#include "Headers/Juego.h"

void Juego::initVars(){
    this->window = nullptr;
    this->bullet_vel = 2;
    this->bullet_qty = 30;
    this->bullets_usadas = {};
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
        std::cout << jugador.getY() << "\n";
    }else if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        jugador.update(0,velJugador);
        std::cout << jugador.getY() << "\n";
    }
    //jugador.getSprite().setPosition(jugador.getX(), jugador.getY());
}

void Juego::disparo() {
    if(1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        std::cout << "Presiona espacio" << "\n";
        this->bullets_disponibles[0]->update(jugador.getY() + 12, bullet_vel);
        //this->bullets_usadas.push_back(bullets_disponibles[0]);
        this->bullets_disponibles.erase(this->bullets_disponibles.begin());
    }

}

void Juego::recicla_balas() {
    if(this->bullets_usadas[0]->outOfBounds()){
        delete this->bullets_usadas[0];
        std::cout << "bullet deleted";
        this->bullets_usadas.erase(this->bullets_usadas.begin());
    }
}

void Juego::update() {
    this->pollEvents();
    this->movJugador();
    this->disparo();
    //this->recicla_balas();
}

void Juego::render() {
    this->window->clear(sf::Color().Cyan);
    this->window->draw(jugador.getSprite());
    if(not this->bullets_usadas.empty()){
        for(int i = 0; i <= this->bullets_usadas.size(); i++ ){
            this->window->draw(bullets_usadas[i]->getSprite());
        }
    }

    this->window->display();
}




