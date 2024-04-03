//
// Created by hanil on 12/10/2023.
//

#ifndef SFML_PROJECTS_TRANSACTIONSWIDGET_H
#define SFML_PROJECTS_TRANSACTIONSWIDGET_H

#include <list>
#include "GuiComponent.h"
#include "Transaction.h"
#include "RoundedRectangleShape.h"

class TransactionsWidget: public GuiComponent{
private:
    sf::Color lightGrey = sf::Color(250, 250, 250);
    sf::Color darkGrey = sf::Color(80, 80, 80);
    sf::Color mediumGrey = sf::Color(237, 237, 237);
    sf::Color darkMediumGrey = sf::Color(200, 200, 200);
    sf::Text date, note, category, amount;
    std::list<Transaction> transactions;
    RoundedRectangleShape box = RoundedRectangleShape(sf::Vector2f{800,300}, 10,20);

public:
    Snapshot &getSnapshot() override;

    void applySnapshot(const Snapshot &snapshot) override;

    void addEventHandler(sf::RenderWindow &window, sf::Event event) override;

    void update() override;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void setUp();

    void setPosition(const sf::Vector2f &position);

    TransactionsWidget();

    void setTransactions(const std::list<Transaction> &transactions);

    void addTransaction(const Transaction& transaction);

    void clearTransactions();

    sf::FloatRect getGlobalBounds () const;

};


#endif //SFML_PROJECTS_TRANSACTIONSWIDGET_H
