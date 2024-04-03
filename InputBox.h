//
// Created by hanil on 11/22/2023.
//

#ifndef SFML_PROJECTS_INPUTBOX_H
#define SFML_PROJECTS_INPUTBOX_H
#include <SFML/Graphics.hpp>
#include "States.h"
#include "Font.h"
#include "helper.h"
#include "MouseEvents.h"

class InputBox: public sf::Drawable {
private:
    sf::Color OGcolor = {218, 160, 109};
    sf::Color boxOutline = {149, 69, 53};
    sf::Text text;
    const std::string DefaultTextLabel = "LABEL";
    std::string textLabel;
    sf::RectangleShape box;
    States state;
public:
    InputBox();
    InputBox(const std::string& label);
    void setBoxSize(const sf::Vector2f& size);
    void setTextColor(const sf::Color& color);
    void setBoxColor(const sf::Color& background, const sf::Color& borderColor, int outlineThickness);
    void setPosition(const sf::Vector2f& position);
    sf::FloatRect  getGlobalBounds() const;
    void resize(const sf::Vector2f size);
    void setLabelSize(int size);
    void leftAlignText();
    std::string getLabel();
    void setLabel(const std::string& label);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    sf::Vector2f getSize();
    sf::Vector2f getPosition() const;
};


#endif //SFML_PROJECTS_INPUTBOX_H
