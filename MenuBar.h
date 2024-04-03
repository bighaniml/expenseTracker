//
// Created by hanil on 12/3/2023.
//

#ifndef SFML_PROJECTS_MENUBAR_H
#define SFML_PROJECTS_MENUBAR_H
#include "GuiComponent.h"
#include "DropDownMenu.h"
#include <list>

class MenuBar: public GuiComponent {
private:
    std::list<DropDownMenu> menu;
    void align();
public:
    Snapshot &getSnapshot();

    void applySnapshot(const Snapshot &snapshot);

    void addEventHandler(sf::RenderWindow &window, sf::Event event);

    void update();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void addMenuItem(const DropDownMenu& menuItem);
    void setSize(const sf::Vector2f& size);
    void setPosition(const sf::Vector2f& position);


};


#endif //SFML_PROJECTS_MENUBAR_H
