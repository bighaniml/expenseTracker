//
// Created by hanil on 11/21/2023.
//

#include "ItemList.h"

void ItemList::align() {
    sf::FloatRect bounds = items.begin()->getGlobalBounds();
    int counter = 0;
    for(auto& item : items){
        item.setPosition(sf::Vector2f{bounds.left, bounds.top + bounds.height*counter});
        counter++;
    }

}

void ItemList::push_back(const std::string &label) {
    Item toPush(label);
    items.push_back(toPush);
    align();
}

void ItemList::remove(const std::string &label) {
//    const Item toRemove(label);
//    items.remove(toRemove);
}

void ItemList::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if(!items.empty()) {
        for (auto &item: items) {
            target.draw(item);
        }
    }
}

void ItemList::resize(const sf::Vector2f &size) {
    for(auto& item: items){
        item.resize(size);
    }
    align();
}

void ItemList::setPosition(const sf::Vector2f &position) {
    items.begin()->setPosition(position);
    align();
}

std::list<Item>::iterator ItemList::begin() {
    return items.begin();
}

std::list<Item>::iterator ItemList::end() {
    return items.end();
}

std::list<Item>::reverse_iterator ItemList::rbegin() {
    return items.rbegin();
}

std::list<Item>::reverse_iterator ItemList::rend() {
    return items.rend();
}

std::list<Item>::const_iterator ItemList::cbegin() const {
    return items.begin();
}
std::list<Item>::const_iterator ItemList::cend() const {
    return items.end();
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for(auto& item: items){
        item.addEventHandler(window, event);
    }
}

void ItemList::update() {
    for(auto& item: items){
        item.update();
    }
}
 sf::FloatRect ItemList::getGlobalBounds() const {
    sf::FloatRect bounds;
    bounds.left = items.cbegin()->getGlobalBounds().left;
    bounds.top = items.begin()->getGlobalBounds().top;
    bounds.width = items.begin()->getGlobalBounds().width;
    bounds.height = items.begin()->getGlobalBounds().height*items.size();
    return bounds;
}

bool ItemList::empty() const {
    if(items.empty()){
        return true;
    }
    return false;
}

int ItemList::size() const {
    return items.size();
}

void ItemList::setColor(const sf::Color &fillColor, const sf::Color &outlineColor, const sf::Color& charColor, int outlineThickness) {
    for(auto& item: items){
        item.setBoxColor(fillColor, outlineColor, outlineThickness);
        item.setTextColor(charColor);
    }
}

const Item & ItemList::front() const {
    return items.front();
}
