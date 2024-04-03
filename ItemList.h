//
// Created by hanil on 11/21/2023.
//

#ifndef SFML_PROJECTS_ITEMLIST_H
#define SFML_PROJECTS_ITEMLIST_H
#include <SFML/Graphics.hpp>
#include <list>
#include "Item.h"

class ItemList: public sf::Drawable {
private:
    std::list<Item> items;
    void align();
    States state;
public:
    int size() const;
    bool empty() const;
    void push_back(const std::string& label);
    void remove(const std::string& label);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void resize(const sf::Vector2f& size);
    void setPosition(const sf::Vector2f& position);
    void setColor(const sf::Color& fillColor, const sf::Color& outlineColor, const sf::Color& charColor, int outlineThickness);
    const Item & front() const;
    sf::FloatRect getGlobalBounds() const;
    std::list<Item>::iterator begin();
    std::list<Item>::iterator end();
    std::list<Item>::reverse_iterator rbegin();
    std::list<Item>::reverse_iterator rend();
    std::list<Item>::const_iterator cbegin() const;
    std::list<Item>::const_iterator cend() const;
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();


};


#endif //SFML_PROJECTS_ITEMLIST_H
