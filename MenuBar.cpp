//
// Created by hanil on 12/3/2023.
//

#include "MenuBar.h"

Snapshot &MenuBar::getSnapshot() {

}

void MenuBar::align() {
    sf::FloatRect bounds = menu.front().getGlobalBounds();
    int counter = 0;
    if(!menu.empty()) {
        for (auto &item: menu) {
            item.setPosition(sf::Vector2f{bounds.left + bounds.width * counter, bounds.top});
            counter++;
        }
    }
}



void MenuBar::addMenuItem(const DropDownMenu &menuItem) {
    menu.push_back(menuItem);
}

void MenuBar::setSize(const sf::Vector2f &size) {
    for(auto& item: menu){
        item.setSize(size);
    }
}

void MenuBar::setPosition(const sf::Vector2f &position) {
    menu.front().setPosition(position);
    align();
}

void MenuBar::applySnapshot(const Snapshot &snapshot) {

}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(!menu.empty()){
        for(auto& items: menu){
            items.addEventHandler(window, event);
        }
    }
}

void MenuBar::update() {
    if(!menu.empty()){
        for(auto& items: menu){
            items.update();
        }
    }
}

void MenuBar::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for(auto& items: menu){
        target.draw(items);
    }
}
