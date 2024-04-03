//
// Created by hanil on 10/12/2023.
//



#include "Button.h"


sf::Color lightGrey = sf::Color(250, 250, 250);
sf::Color darkGrey = sf::Color(80, 80, 80);
sf::Color mediumGrey = sf::Color(237, 237, 237);
sf::Color darkMediumGrey = sf::Color(200, 200, 200);

Button::Button() {
    label.setString("");
    label.setFont(Font::getFont(WIDGET));
    label.setCharacterSize(20);
    circle.setSize(sf::Vector2f{100, 30});
    circle.setFillColor(sf::Color::White);
    circle.setOutlineColor(darkMediumGrey);
}

Button::Button(const sf::Color &color, const std::string &label, int x, int y): x(x), y(y){
    this->label.setString(label);
    this->label.setFont(Font::getFont(WIDGET_SEMI_BOLD));
    circle.setFillColor(color);
    circle.setSize(sf::Vector2f{100, 50});
    circle.setPosition(x, y);
    helper::centerText(circle, this->label);
    this->color = sf::Color::White;

}

//void Button::setColor(sf::Color color) {
//    circle.setFillColor(color);
//}

void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(circle);
    window.draw(label);
}

void Button::setUp()  {

}

int Button::getX() {
    return x;
}

int Button::getY() {
    return y;
}

void Button::setFontColor(const sf::Color& color) {
    label.setFillColor(color);
}

void Button::setColor(const sf::Color& color) {
    circle.setFillColor(color);
}

std::string Button::getLabel() {
    return label.getString();
}

sf::FloatRect Button::getGlobalBounds() const {
    return circle.getGlobalBounds();
}


sf::Color Button::getColor() {
    return this->color;
}

void Button::setPosition(const sf::Vector2f &position) {
    circle.setPosition(position);
    x = position.x;
    y = position.y;
    helper::centerText(circle, this->label);
}

Snapshot &Button::getSnapshot() {
    return GuiComponent::getSnapshot();
}

void Button::applySnapshot(const Snapshot &snapshot) {
    GuiComponent::applySnapshot(snapshot);
}

void Button::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //don't handle this here
}

void Button::update() {
    //don't handle this here
}

void Button::setLabel(const std::string& str) {
    label.setString(str);
}

void Button::setSize(const sf::Vector2f &size) {
    float resizeFactor = size.x / circle.getSize().x;
    circle.setSize(sf::Vector2f{circle.getSize().x*resizeFactor, circle.getSize().y*resizeFactor});
    label.setCharacterSize(label.getCharacterSize()*resizeFactor);
    helper::centerText(circle, this->label);
}

//bool Button::hover(sf::Window &window)
//{
//    if ((pow((sf::Mouse::getPosition(window).x - (circle.getGlobalBounds().left + circle.getGlobalBounds().width/2)), 2) +
//         pow((sf::Mouse::getPosition(window).y - (circle.getGlobalBounds().top + circle.getGlobalBounds().height/2)), 2)) <
//        pow(circle.getRadius(), 2))
//    {
////        std::cout << "Button Center:\nx: " << std::to_string(circle.getGlobalBounds().left + circle.getGlobalBounds().width/2) << "| y: " << (circle.getGlobalBounds().top + circle.getGlobalBounds().height/2) << std::endl;
////        std::cout << "Cursor Location:\nx: " << std::to_string(sf::Mouse::getPosition(window).x) << "| y: " << std::to_string(sf::Mouse::getPosition(window).y) << std::endl;
//        return true;
//    }
//    return false;
//}
