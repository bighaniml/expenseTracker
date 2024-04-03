#include <iostream>
#include <SFML/Graphics.hpp>
#include "KeyShortcuts.h"
#include "MouseEvents.h"
#include "TextInput.h"
#include "Item.h"
#include "ItemList.h"
#include "InputBox.h"
#include "DropDownMenu.h"
#include "MenuBar.h"
#include "RoundedRectangleShape.h"
#include "InputWidget.h"
#include "Transaction.h"
#include "HomePage.h"
class RenderWindow;

int main() {
    sf::RenderWindow window(sf::VideoMode(1800, 1000, 32), "Test");
    window.setFramerateLimit(32);
    HomePage home;
//    InputWidget widget;
//    Transaction nuggets;
//    Transaction watch("5.00", "12/10/2023", "Shopping", "Income", "work");
//    watch.setPosition(sf::Vector2f{200,80});
//    nuggets.setPosition(sf::Vector2f{200, 55});
//    widget.setPosition(sf::Vector2f{100, 100});
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
//            widget.addEventHandler(window, event);
            home.addEventHandler(window, event);
        }

//        widget.update();
        home.update();
        window.clear(sf::Color(250,250,250));
//        window.draw(widget);
//        window.draw(nuggets);
//        window.draw(watch);
//        window.draw(box);
        window.draw(home);
        window.display();
    }
    return 0;
}



