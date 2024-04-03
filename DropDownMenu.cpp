//
// Created by hanil on 11/22/2023.
//

#include "DropDownMenu.h"

Snapshot &DropDownMenu::getSnapshot() {

}

void DropDownMenu::applySnapshot(const Snapshot &snapshot) {

}

void DropDownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    items.addEventHandler(window, event);
    if (MouseEvents<InputBox>::mouseClicked(displayBox, window) && !state.isEnabled(VISIBLE)) {
        state.enableState(VISIBLE);
    }
    else if (MouseEvents<InputBox>::mouseClicked(displayBox, window) && state.isEnabled(VISIBLE)) {
        state.disableState(VISIBLE);
    }
    for(auto& item: items){
        if(MouseEvents<sf::RectangleShape>::mouseClicked(item.getBox(), window) && state.isEnabled(VISIBLE)){
            displayBox.setLabel(item.getString());
            state.disableState(VISIBLE);
        }
    }
}
void DropDownMenu::update() {
    items.update();
    displayBox.update();
}

void DropDownMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(displayBox);
    if(state.isEnabled(VISIBLE)) {
        target.draw(items);
    }
}

void DropDownMenu::addMenuItem(const std::string &label) {
    //align inputBox and itemList
    items.push_back(label);
    items.resize(displayBox.getSize());
    helper::verticalAlign<InputBox, ItemList>(displayBox, items);
}

void DropDownMenu::setSize(const sf::Vector2f &size) {
    displayBox.resize(size);
    items.resize(size);
    helper::verticalAlign<InputBox, ItemList>(displayBox, items);
}

void DropDownMenu::setPosition(const sf::Vector2f &position) {
    displayBox.setPosition(position);
    sf::Vector2f itemsPosition = {position.x, position.y + displayBox.getGlobalBounds().height};
    items.setPosition(itemsPosition);
    helper::verticalAlign<InputBox, ItemList>(displayBox, items);
}

sf::FloatRect DropDownMenu::getGlobalBounds() const {
    sf::FloatRect bounds;
    bounds.top = displayBox.getGlobalBounds().top;
    bounds.left = displayBox.getGlobalBounds().left;
    bounds.width = displayBox.getGlobalBounds().width;
    bounds.height = displayBox.getGlobalBounds().height;
    if(state.isEnabled(VISIBLE)){
        sf::FloatRect boundsVisible(bounds.left, bounds.top, bounds.width, items.front().getGlobalBounds().height * items.size());
        return boundsVisible;
    }
    return bounds;
}

void DropDownMenu::setColorDisplay(const sf::Color &fill, const sf::Color &outline,  const sf::Color& charColor, int outlineThickness) {
    displayBox.setBoxColor(fill, outline, outlineThickness);
    displayBox.setTextColor(charColor);
}

void DropDownMenu::setColorList(const sf::Color &fill, const sf::Color &outline, const sf::Color& charColor, int outlineThickness) {
    items.setColor(fill, outline, charColor, outlineThickness);

}

void DropDownMenu::setDisplayLabel(const std::string &str) {
    displayBox.setLabel(str);
}

std::string DropDownMenu::getLabelString() {
    return displayBox.getLabel();
}
