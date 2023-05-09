//
// Created by juanpablo on 04/04/23.
//

#include "Headers/Juego.h"
#include <iostream>


const int MAX_DAMAGE = 50;

void Juego::initVars(std::string dif){
    this->window = nullptr;
    this->hit = false;
    this->oleada_actual = 0;
    this->bullet_vel = 2;
    this->bullet_dmg = MAX_DAMAGE;
    this->bullet_qty = oleadas1[oleada_actual].bullets;
    if(dif == "facil"){
        dificultad = 1;
        vel_enemigo = 1;
        this->cargaOleada(oleadas1);
    }else if(dif == "medio"){
        dificultad =2;
        vel_enemigo = 2;
        this->cargaOleada(oleadas2);
    }else if(dif == "dificil"){
        dificultad =3;
        vel_enemigo = 3;
        this->cargaOleada(oleadas3);
    }
    this->vel_jugador = 3;
    this->spawn_delay = 0.2;
    this->spawn_delay *= CLOCKS_PER_SEC;
    this->shot_delay = 0.01;
    this->shot_delay *= CLOCKS_PER_SEC;

    this->bullet_qty = 0;
    this->enemy_clock = clock();
    this->bullet_clock = clock();
}

void Juego::initWindow() {
    this->video_mode.height = 400;
    this->video_mode.width = 800;
    this->window = new sf::RenderWindow(this->video_mode, "Battlespace");
    this->window->setFramerateLimit(120);
}

Juego::Juego(std::string dificultad){
    this->initVars(dificultad);
    this->initWindow();
}

Juego::~Juego() {
    delete this->window;
    Bullet::collector.liberar();
}

bool Juego::running() const {
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

void Juego::cargaOleada(Oleada* oleadas) {
    if(!bullets_disponibles.empty()){
        for(int i=0; i < this->bullets_disponibles.size(); i++){
            delete bullets_disponibles[i];
            this->bullets_disponibles.erase(this->bullets_disponibles.begin());
        }
    }
    this->bullet_qty = 0;
    this->bullet_dmg = MAX_DAMAGE;
    if(oleada_actual <= 4){
        this->cargaEnemigos(oleadas[oleada_actual].enemigo1, oleadas[oleada_actual].enemigo2, oleadas[oleada_actual].enemigo3);
        this->cargaBalas(oleadas[oleada_actual].bullets, this->bullet_dmg);
    }else{
        oleada_actual = 0;
        this->cargaEnemigos(oleadas[oleada_actual].enemigo1, oleadas[oleada_actual].enemigo2, oleadas[oleada_actual].enemigo3);
        this->cargaBalas(oleadas[oleada_actual].bullets, this->bullet_dmg);
    }

}

void Juego::cargaBalas(int qty, int dmg){
    for (int i = 0; i < qty; ++i) {
        Bullet *new_bullet = new Bullet(dmg);
        this->bullets_disponibles.push_back(new_bullet);
    }
}

void Juego::cargaEnemigos(int enemigo1, int enemigo2, int enemigo3) {
    for(int i = 0; i < enemigo3; i++){
        this->lista_enemigos.insertar(new Enemigo(3));
    }
    for(int i = 0; i < enemigo2; i++){
        this->lista_enemigos.insertar(new Enemigo(2));
    }
    for(int i = 0; i < enemigo1; i++){
        this->lista_enemigos.insertar(new Enemigo(1));
    }

}

void Juego::resetBulletClock() {
    this->bullet_clock = clock();
}

void Juego::resetEnemyClock() {
    this->enemy_clock = clock();
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
    nave->setPos(800, rand()%390);
    nave->setInit();
}

void Juego::movEnemigos() {
    Enemigo* nave = this->lista_enemigos.getNave();
    if(!this->lista_enemigos.isEmpty()){
        for(int i=0; i < this->lista_enemigos.ssize(); i++){
            if(nave->getInit()){
                nave->update(vel_enemigo);
                if(nave->getX() <= 60){
                    jugador.getHit();
                    this->hit = true;
                    lista_enemigos.eliminar(nave);
                    nave = lista_enemigos.getNave();
                }else{
                    if(nave->getNext() != nullptr){
                        nave = nave->getNext();
                    }else{
                        break;
                    }
                }
            }else{
                if(clock() - this->enemy_clock >= spawn_delay){
                    this->setEnemigos(nave);
                    this->resetEnemyClock();
                    break;
                }else{
                    break;
                }
            }
        }
    }else{
        oleada_actual++;
        if(dificultad == 1){
            cargaOleada(oleadas1);
        }else if(dificultad ==2){
            cargaOleada(oleadas2);
        }else{
            cargaOleada(oleadas3);
        }

    }

}

void Juego::colisiones() {
    Enemigo* nave = lista_enemigos.getNave();
    if(!bullets_usadas.empty()){
        for (auto & bullets_usada : bullets_usadas) {
            for (int j = 0; j < lista_enemigos.ssize(); ++j) {
                sf::FloatRect rectBullet = bullets_usada->getSprite().getGlobalBounds();
                sf::FloatRect rectNave = nave->getSprite().getGlobalBounds();
                if(rectNave.contains(rectBullet.left+rectBullet.width, rectBullet.top+(rectBullet.height/2))){
                    nave->setDamage(bullets_usada->getDamage());
                    delete this->bullets_usadas[0];
                    this->bullets_usadas.erase(this->bullets_usadas.begin());
                    if(nave->getDead()){
                        lista_enemigos.eliminar(nave);
                        nave = lista_enemigos.getNave();
                    }else{
                        if(nave->getNext() != nullptr){
                            nave = nave->getNext();
                        }else{
                            break;
                        }
                    }
                }else{
                    if(nave->getNext() != nullptr){
                        nave = nave->getNext();
                    }else{
                        break;
                    }
                }
            }
        }
    }

}

void Juego::disparo() {
    if(!this->bullets_disponibles.empty()) {
        if(clock() - this->bullet_clock >= shot_delay) {
            if (1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                this->bullets_usadas.insert(this->bullets_usadas.begin(), this->bullets_disponibles[0]);
                this->bullets_disponibles.erase(this->bullets_disponibles.begin());
                this->bullets_usadas[0]->setPath(this->jugador.getY() + 8);
                this->resetBulletClock();
            }
        }
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
    if(this->bullets_usadas[0]->outOfBounds()){
        delete this->bullets_usadas[0];
        this->bullets_usadas.erase(this->bullets_usadas.begin());
        this->bullet_qty ++;
    }
}

void Juego::recargaBalas() {
    if(this->bullets_disponibles.empty() && this->bullets_usadas.empty()){
        this->bullet_dmg -= 15;
        cargaBalas(this->bullet_qty, this->bullet_dmg);
        this->bullet_qty = 0;
    }
}

void Juego::update() {
    this->pollEvents();
    this->movJugador();
    this->disparo();
    this->movBalas();
    this->movEnemigos();
    this->colisiones();
    this->recargaBalas();
}

void Juego::render() {
    if(jugador.isDead()){
        this->window->clear(sf::Color::Black);
        sf::Text game_over_text;
        sf::Font chivo;
        chivo.loadFromFile("/home/juanpablo/CLionProjects/Battlespace/Fonts/Chivo_Mono/ChivoMono-Italic-VariableFont_wght.ttf");
        game_over_text.setString("Game Over");
        game_over_text.setFont(chivo);
        game_over_text.setColor(sf::Color::White);
        game_over_text.setPosition(300,200);
        game_over_text.setCharacterSize(40);
        this->window->draw(game_over_text);
    }else{
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
    }
    this->window->display();
}

std::string Juego::retornaOleada() const {
    std::string str = std::to_string(5 - oleada_actual);
    str += "\n";
    return str;
}

void Juego::cambiaVelocidad(int i) {
    this->bullet_vel = i;
}

bool Juego::isPlayerDead() {
    return jugador.isDead();
}

bool Juego::ishit() {
    bool state = this->hit;
    this->hit = false;
    return state;
}




