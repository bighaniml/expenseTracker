//
// Created by hanil on 12/6/2023.
//

#ifndef SFML_PROJECTS_INPUTWIDGET_H
#define SFML_PROJECTS_INPUTWIDGET_H
#include "RoundedRectangleShape.h"
#include "TextInput.h"
#include "DropDownMenu.h"
#include "GuiComponent.h"
#include "Button.h"
#include "MouseEvents.h"
#include "Transaction.h"

class InputWidget: public GuiComponent {
private:
    sf::Color lightGrey = sf::Color(250, 250, 250);
    sf::Color darkGrey = sf::Color(80, 80, 80);
    sf::Color mediumGrey = sf::Color(237, 237, 237);
    sf::Color darkMediumGrey = sf::Color(200, 200, 200);
    int margin = 40;
    RoundedRectangleShape box = RoundedRectangleShape(sf::Vector2f{800,600}, 10,20);
    TextInput amount;
    sf::Text label, typeLabel, categoryLabel;
    TextInput date;
    TextInput note;
    DropDownMenu category;
    DropDownMenu type;
    Button clear;
    Button save;
    Transaction transaction;

public:
    InputWidget();
    void setLabel(const std::string& label);
    void setUp();
    void setPosition(const sf::Vector2f& vector2);
    void setSize();
    Snapshot &getSnapshot() override;
    void applySnapshot(const Snapshot &snapshot) override;
    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;
    void update() override;
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void clearInputs();
    Button& getButton();
    Transaction getTransaction();
    sf::Vector2f getPosition();
    sf::FloatRect getGlobalBounds() const;
};


#endif //SFML_PROJECTS_INPUTWIDGET_H
