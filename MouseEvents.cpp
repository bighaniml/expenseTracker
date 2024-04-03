//
// Created by hanil on 11/13/2023.
//
#ifndef SFML_PROJECTS_MOUSEEVENTS_CPP
#define SFML_PROJECTS_MOUSEEVENTS_CPP

#include <iostream>
#include "MouseEvents.h"
template<class T>
bool MouseEvents<T>::hovered(T &object, sf::RenderWindow &window) {
    sf::Vector2f npos = (sf::Vector2f) sf::Mouse::getPosition(window);
    return object.getGlobalBounds().contains(npos);
}

template<class T>
bool MouseEvents<T>::mouseClicked(T &object, sf::RenderWindow &window) {
    return hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

template<class T>
bool MouseEvents<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
    return (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left);
}

template<class T>
bool MouseEvents<T>::mouseDoubleClicked() {
    if(clicks == 2){
        return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::mouseTripleClicked() {
    if(clicks == 3){
        return true;
    }
    return false;
}

template<class T>
bool MouseEvents<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    return false;
}


template<class T>
void MouseEvents<T>::countClicks(sf::Event event) {
    clicks = 0;
    sf::Time time = clock.restart();
   // time = clock.getElapsedTime();
    while (clock.getElapsedTime() > sf::seconds(2)){
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
            std::cout << "clicks: " << clicks << std::endl;
            clicks++;
        }
    }
}

#endif //SFML_PROJECTS_MOUSEEVENTS_CPP