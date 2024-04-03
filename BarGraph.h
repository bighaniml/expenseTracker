//
// Created by hanil on 12/11/2023.
//

#ifndef SFML_PROJECTS_BARGRAPH_H
#define SFML_PROJECTS_BARGRAPH_H
#include "GuiComponent.h"
#include "Transaction.h"
#include "RoundedRectangleShape.h"
#include <list>
class BarGraph: public GuiComponent {
private:
    sf::Color lightGrey = sf::Color(250, 250, 250);
    sf::Color darkGrey = sf::Color(80, 80, 80);
    sf::Color mediumGrey = sf::Color(237, 237, 237);
    sf::Color darkMediumGrey = sf::Color(200, 200, 200);
    sf::Text incomeLabel;
    sf::Text expenseLabel;
    sf::Text netLabel;
    RoundedRectangleShape box  = RoundedRectangleShape(sf::Vector2f{400,400}, 10,20);
    sf::RectangleShape income;
    sf::RectangleShape expenses;
    float income1 = 0;
    float expenses1 = 0;
    float net1 = 0;
public:
    void setGains(const std::list<Transaction> &gains);

    void setLoss(const std::list<Transaction> &loss);
    const std::list<Transaction> &getGains() const;

    const std::list<Transaction> &getLoss() const;
    void calculateGains();
    void calculateLoss();

private:
    sf::RectangleShape net;

    std::list<Transaction> gains;
    std::list<Transaction> loss;

public:

    Snapshot &getSnapshot() override;

    void applySnapshot(const Snapshot &snapshot) override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    void setUp();

    void setPosition(const sf::Vector2f& position);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};


#endif //SFML_PROJECTS_BARGRAPH_H
