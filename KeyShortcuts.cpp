//
// Created by hanil on 11/11/2023.
//

#include <iostream>
#include "KeyShortcuts.h"

bool KeyShortcuts::isUndo(sf::RenderWindow& window, sf::Event event) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)){
        return true;
    }
    else{
        return false;
    }
}
