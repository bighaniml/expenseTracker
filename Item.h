//
// Created by hanil on 11/21/2023.
//

#ifndef SFML_PROJECTS_ITEM_H
#define SFML_PROJECTS_ITEM_H
#include <SFML/Graphics.hpp>
#include "EventHandler.h"
#include "States.h"
#include "helper.h"
#include "Font.h"
#include "MouseEvents.h"

class Item: public sf::Drawable, public EventHandler{
private:
    sf::Color OGcolor = {218, 160, 109};
    sf::Text text;
    std::string textLabel = "LABEL";
    sf::RectangleShape box;
    States state;
public:
    Item();
    Item(const std::string& label);
    void setTextColor(const sf::Color& color);
    void setBoxColor(const sf::Color& color, const sf::Color& borderColor, int borderThickness);
    void setPosition(const sf::Vector2f& position);
    sf::FloatRect  getGlobalBounds() const;
    void resize(const sf::Vector2f size);
    void setLabel(const std::string& label);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    void highlight();
    sf::RectangleShape& getBox();
    std::string getString();
};


#endif //SFML_PROJECTS_ITEM_H
