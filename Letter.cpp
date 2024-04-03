//
// Created by hanil on 11/7/2023.
//

#include "Letter.h"


Letter::Letter() {
    setString("5");
    setFillColor(sf::Color::Black);
    sf::Text::setFont(Font::getFont(WIDGET));
//    setPosition()
}

Letter::Letter(char letter): Letter(){
    setString(letter);
    character = letter;
}
Letter::Letter(char letter, int size): Letter(letter){
    setCharacterSize(size);
}

Letter::Letter(char letter, const sf::Color &color, const fonts &font){
    setString(letter);
    setFillColor(color);
    sf::Text::setFont(Font::getFont(font));
}

char Letter::getLetter() {
    return character;
}

void Letter::setColor(const sf::Color &color) {
    setFillColor(color);
}

void Letter::setFont(fonts font) {
    sf::Text::setFont(Font::getFont(font));
}
