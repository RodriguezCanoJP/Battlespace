//
// Created by juanpablo on 04/04/23.
//

#include "Headers/Juego.h"

void Juego::initVars(){
    this->window = nullptr;
    for (int i = 0; i < this->bulletQty; ++i) {
        Bullet* nbullet = new Bullet();
        this->bullets.push_back(nbullet);
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

    }
}

void Juego::update() {
    this->pollEvents();
    this->movJugador();
}

void Juego::render() {
    this->window->clear(sf::Color().Cyan);
    this->window->draw(jugador.getSprite());
    this->window->display();
}


