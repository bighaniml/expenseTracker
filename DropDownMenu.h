//
// Created by hanil on 11/22/2023.
//

#ifndef SFML_PROJECTS_DROPDOWNMENU_H
#define SFML_PROJECTS_DROPDOWNMENU_H
#include <SFML/Graphics.hpp>
#include "InputBox.h"
#include "ItemList.h"
#include "GuiComponent.h"
#include "States.h"

class DropDownMenu: public GuiComponent {
private:
    ItemList items;
    InputBox displayBox;
    States state;
public:
    Snapshot &getSnapshot();
    void applySnapshot(const Snapshot &snapshot);
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    void addMenuItem(const std::string& label);
    void setSize(const sf::Vector2f& size);
    void setPosition(const sf::Vector2f& position);
    void setColorDisplay(const sf::Color& fill, const sf::Color& outline,  const sf::Color& charColor, int outlineThickness);
    void setColorList(const sf::Color& fill, const sf::Color& outline, const sf::Color& charColor, int outlineThickness );
    void setDisplayLabel(const std::string& str);
    std::string getLabelString();
    sf::FloatRect getGlobalBounds() const;
};


#endif //SFML_PROJECTS_DROPDOWNMENU_H
