//
// Created by juanpablo on 04/04/23.
//

#include "Juego.h"

void Juego::initVars() {
    this->window = nullptr;
}

void Juego::initWindow() {
    this->videoMode.height = 400;
    this->videoMode.width = 800;
    this->window = new sf::RenderWindow(this->videoMode, "Battlespace");
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

void Juego::update() {
    this->pollEvents();
}

void Juego::render() {
    this->window->clear(sf::Color().Cyan);
    this->window->display();
}