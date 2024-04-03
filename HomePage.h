//
// Created by hanil on 12/11/2023.
//

#ifndef SFML_PROJECTS_HOMEPAGE_H
#define SFML_PROJECTS_HOMEPAGE_H
#include "GuiComponent.h"
#include "TransactionsWidget.h"
#include "InputWidget.h"
#include "MouseEvents.h"
#include "BarGraph.h"
#include "MenuBar.h"
class HomePage: public GuiComponent {
private:
    DropDownMenu file;
    DropDownMenu trans;
    sf::RectangleShape top;
    sf::Color darkerTeal = sf::Color(106, 203, 193);
    sf::Color teal = sf::Color(77, 173, 153);
    sf::Color lightGrey = sf::Color(250, 250, 250);
    sf::Color darkGrey = sf::Color(80, 80, 80);
    sf::Color mediumGrey = sf::Color(237, 237, 237);
    sf::Color darkMediumGrey = sf::Color(200, 200, 200);
    InputWidget input;
    BarGraph graph;
    MenuBar menu;
    TransactionsWidget transactions;
    std::list<Transaction> expenses;
    std::list<Transaction> income;

public:
    Snapshot &getSnapshot() override;

    void applySnapshot(const Snapshot &snapshot) override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    HomePage();
};


#endif //SFML_PROJECTS_HOMEPAGE_H
