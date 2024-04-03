//
// Created by hanil on 11/22/2023.
//

#include "InputBox.h"

InputBox::InputBox() {
    box.setPosition(0, 0);
    box.setSize(sf::Vector2f{200, 100});
    box.setFillColor(OGcolor);
    box.setOutlineThickness(5);
    box.setOutlineColor(boxOutline);
    //set up text -- font, color, size, string, position
    text.setFont(Font::getFont(WIDGET_REGULAR));
    text.setCharacterSize(25);
    text.setString(DefaultTextLabel);
    helper::centerText(box, text);
    textLabel = DefaultTextLabel;
}


InputBox::InputBox(const std::string &label):InputBox() {
    text.setString(label);
}

void InputBox::setTextColor(const sf::Color &color) {
    text.setFillColor(color);
}

void InputBox::setBoxColor(const sf::Color &color, const sf::Color &outlineColor, int outlineThickness) {
    box.setFillColor(color);
    box.setOutlineColor(outlineColor);
    box.setOutlineThickness(outlineThickness);
}

void InputBox::setPosition(const sf::Vector2f &position) {
    box.setPosition(position);
    helper::centerText(box, text);
}

sf::FloatRect InputBox::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void InputBox::resize(const sf::Vector2f size) {
    sf::Vector2f resizeRatio;
    resizeRatio.x = size.x/box.getSize().x;
    resizeRatio.y = size.y/box.getSize().y;
    box.setSize(size);
    text.setCharacterSize(text.getCharacterSize()*resizeRatio.x);
    helper::centerText(box, text);
}

void InputBox::setLabel(const std::string &label) {
    textLabel = label;
    text.setString(textLabel);
    helper::centerText(box, text);
}

void InputBox::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box);
    target.draw(text);
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void InputBox::update() {
    text.setString(textLabel);
}

sf::Vector2f InputBox::getSize() {
    return box.getSize();
}

std::string InputBox::getLabel() {
    return text.getString();
}

sf::Vector2f InputBox::getPosition() const {
    return box.getPosition();
}

void InputBox::setBoxSize(const sf::Vector2f &size) {
    box.setSize(size);
    helper::leftAlign(box, text);
}

void InputBox::setLabelSize(int size) {
    text.setCharacterSize(size);
    helper::leftAlign(box, text);
}




