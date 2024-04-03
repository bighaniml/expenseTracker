//
// Created by hanil on 11/21/2023.
//

#include "Item.h"

Item::Item() {
    //set up box -- size, color, position
    box.setPosition(0, 0);
    box.setSize(sf::Vector2f{200, 100});
    box.setFillColor(OGcolor);
    //set up text -- font, color, size, string, position
    text.setFont(Font::getFont(WIDGET_SEMI_BOLD));
    text.setCharacterSize(25);
    text.setString(textLabel);
    helper::centerText(box, text);
}


Item::Item(const std::string &label): Item() {
    textLabel = label;
    text.setString(label);
}

void Item::setTextColor(const sf::Color& color) {
    text.setFillColor(color);
}



void Item::setPosition(const sf::Vector2f &position) {
    box.setPosition(position);
    helper::centerText(box, text);
}

void Item::resize(const sf::Vector2f size) {
    sf::Vector2f resizeRatio;
    resizeRatio.x = size.x/box.getSize().x;
    resizeRatio.y = size.y/box.getSize().y;
    box.setSize(size);
    text.setCharacterSize(text.getCharacterSize()*resizeRatio.x);
    helper::centerText(box, text);
}

void Item::setLabel(const std::string &label) {
    textLabel = label;
    text.setString(textLabel);
}

void Item::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    target.draw(box);
    target.draw(text);
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvents<sf::RectangleShape>::hovered(box, window)){
        state.enableState(HIGHLIGHTED);
    }
    if(!MouseEvents<sf::RectangleShape>::hovered(box, window)){
        state.disableState(HIGHLIGHTED);
    }

}

void Item::update() {
    if(state.isEnabled(HIGHLIGHTED)){
        highlight();
    }
    if(!state.isEnabled(HIGHLIGHTED)){
        box.setFillColor(OGcolor);
    }

}

void Item::highlight() {
    box.setFillColor(sf::Color(245, 222, 179));
}



std::string Item::getString() {
    return textLabel;
}

sf::FloatRect Item::getGlobalBounds() const {
    return box.getGlobalBounds();
}


sf::RectangleShape &Item::getBox() {
    return box;
}

void Item::setBoxColor(const sf::Color &color, const sf::Color &borderColor, int borderThickness) {
    box.setFillColor(color);
    OGcolor = color;
    box.setOutlineColor(borderColor);
    box.setOutlineThickness(borderThickness);
}

