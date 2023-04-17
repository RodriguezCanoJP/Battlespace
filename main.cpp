#include <iostream>
#include "third-party/include/serial/serial.h"
#include "Headers/Juego.h"
#include "Headers/Button.h"
#include <thread>
#include <ctime>


clock_t now = clock();
float write_delay = 0.15 * CLOCKS_PER_SEC;
void foo(serial::Serial serial1 , Juego juego){
    serial1.write(juego.retornaOleada());
}

int main() {
    sf::RenderWindow menu = sf::RenderWindow(sf::VideoMode(800, 400), "Battlespace");
    sf::Text text;
    sf::Font mono;
    mono.loadFromFile("/home/juanpablo/CLionProjects/Battlespace/Fonts/Chivo_Mono/ChivoMono-Italic-VariableFont_wght.ttf");

    Button btn1("Inicial", {150, 50}, 20, sf::Color::Green, sf::Color::White);
    btn1.setPosition({300, 50});
    btn1.setFont(mono);

    Button btn2("Intermedio", {150, 50}, 20, sf::Color::Green, sf::Color::White);
    btn2.setPosition({300, 180});
    btn2.setFont(mono);

    Button btn3("Experto", {150, 50}, 20, sf::Color::Green, sf::Color::White);
    btn3.setPosition({300, 310});
    btn3.setFont(mono);

    std::string dificultad = "";

    while (menu.isOpen()) {
        sf::Event event;
        while (menu.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                menu.close();
            else if (event.type == sf::Event::MouseMoved) {
                if (btn1.isMouseOver(menu)) {
                    btn1.setBackColor(sf::Color::Blue);
                } else if (btn2.isMouseOver(menu)) {
                    btn2.setBackColor(sf::Color::Blue);
                } else if (btn3.isMouseOver(menu)) {
                    btn3.setBackColor(sf::Color::Blue);
                } else {
                    btn1.setBackColor(sf::Color::Green);
                    btn2.setBackColor(sf::Color::Green);
                    btn3.setBackColor(sf::Color::Green);
                }
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (btn1.isMouseOver(menu)) {
                    dificultad = "facil";
                    menu.close();
                } else if (btn2.isMouseOver(menu)) {
                    dificultad = "medio";
                    menu.close();
                } else if (btn3.isMouseOver(menu)) {
                    dificultad = "dificil";
                    menu.close();
                }
            }
        }
        menu.clear();
        // Draw the string
        menu.draw(text);
        btn1.drawTo(menu);
        btn2.drawTo(menu);
        btn3.drawTo(menu);
        // Update the window150
        menu.display();
    }

    serial::Serial my_serial("/dev/ttyUSB0", 9600, serial::Timeout::simpleTimeout(3000));

    if (my_serial.isOpen())
    {
        std::cout << "Port opened succesfully" << std::endl;
    }
    else
    {
        std::cout << "Port failed to open" << std::endl;
        exit(1);
    }
    my_serial.flushOutput();
    Juego juego(dificultad);


    while (juego.running()) {
        if(clock() - now > write_delay){
            my_serial.write(juego.retornaOleada());
            std::cout << clock() - now << "\n";
            now = clock();
        }

        if(juego.)
        my_serial.flushOutput();
        juego.update();
        juego.render();
    }

    return 0;
}