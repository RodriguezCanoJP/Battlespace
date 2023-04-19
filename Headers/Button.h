//
// Created by juanpablo on 16/04/23.
//

#ifndef UNTITLED_BUTTON_H
#define UNTITLED_BUTTON_H

#include <iostream>
#include <SFML/Graphics.hpp>


class Button {
private:
    sf::Text text;
    sf::RectangleShape button;
public:
    ///Constructor
    Button(std::string t, sf::Vector2f size,int charSize, sf::Color bgColor, sf::Color textColor);

    /**
     * Pone la posicion del objeto boton en la pantalla
     * @param pos coordenada
     */
    void setPosition(sf::Vector2f pos);

    /**
     * Carga la fuente de la letra del texto del boton
     * @param font
     */
    void setFont(sf::Font &font);

    /**
     * POne el color de fondo del boton
     * @param color
     */
    void setBackColor(sf::Color color);

    /**
     * dibuja el objeto boton en la pantalla de juego, objeto SFML
     * @param window
     */
    void drawTo(sf::RenderWindow &window);

    /**
     * Indica si el cursor del mouse esta sobre el boton
     * @param window
     * @return bool
     */
    bool isMouseOver(sf::RenderWindow &window);
};


#endif //UNTITLED_BUTTON_H
