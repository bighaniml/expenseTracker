//
// Created by hanil on 11/9/2023.
//

#ifndef SFML_PROJECTS_EVENTHANDLER_H
#define SFML_PROJECTS_EVENTHANDLER_H
#include <SFML/Graphics.hpp>


class EventHandler {
public:
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event) = 0;
    virtual void update() = 0;
};


#endif //SFML_PROJECTS_EVENTHANDLER_H
