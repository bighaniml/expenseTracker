//
// Created by hanil on 11/7/2023.
//

#ifndef SFML_PROJECTS_LETTER_H
#define SFML_PROJECTS_LETTER_H


#include <SFML/Graphics.hpp>
#include "Font.h"

class Letter: public sf::Text {
private:
    char character;

public:
    //constructors
    Letter();
    Letter(char letter);
    Letter(char letter, int size);
    Letter(char letter, const sf::Color& color, const fonts& font);
    //getter
    char getLetter();
    //setter
    void setColor(const sf::Color& color);
    void setFont(fonts font);




};


#endif //SFML_PROJECTS_LETTER_H
