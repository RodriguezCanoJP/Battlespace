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

    Button(std::string t, sf::Vector2f size,int charSize, sf::Color bgColor, sf::Color textColor);

    void setPosition(sf::Vector2f pos);

    void setFont(sf::Font &font);

    void setBackColor(sf::Color color);

    void drawTo(sf::RenderWindow &window);

    bool isMouseOver(sf::RenderWindow &window);
};


#endif //UNTITLED_BUTTON_H
