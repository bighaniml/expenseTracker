//
// Created by hanil on 12/11/2023.
//

#include "HomePage.h"

Snapshot &HomePage::getSnapshot() {

}

void HomePage::applySnapshot(const Snapshot &snapshot) {
}

void HomePage::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    menu.addEventHandler(window,event);
    input.addEventHandler(window, event);
    if(MouseEvents<Button>::mouseClicked(input.getButton(), window)){
        transactions.addTransaction(input.getTransaction());
        if(input.getTransaction().getType() == "Expense"){
            expenses.push_front(input.getTransaction());
            graph.setLoss(expenses);
            graph.calculateLoss();
        }else{
            income.push_front(input.getTransaction());
            graph.setGains(income);
            graph.calculateGains();
        }
        input.clearInputs();
    }
}

void HomePage::update() {
    input.update();
    transactions.update();
    graph.update();
    menu.update();
}

void HomePage::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(top);
    target.draw(input);
    target.draw(transactions);
    target.draw(graph);
    target.draw(menu);

}

HomePage::HomePage() {
    input.setPosition(sf::Vector2f{100, 200});
    transactions.setPosition(sf::Vector2f{input.getGlobalBounds().left + input.getGlobalBounds().width + 25, input.getGlobalBounds().top});
    graph.setPosition(sf::Vector2f{transactions.getGlobalBounds().left, transactions.getGlobalBounds().top + transactions.getGlobalBounds().height + 50});

    trans.setDisplayLabel("Transactions");
    trans.addMenuItem("Expenses");
    trans.addMenuItem("Income");
    trans.setColorDisplay(darkerTeal, darkerTeal, sf::Color::White, 0);
    trans.setColorList(sf::Color::White, sf::Color::White, darkGrey, 0);
    file.addMenuItem("New");
    file.addMenuItem("Close");
    file.setDisplayLabel("File");
    file.setColorDisplay(darkerTeal, darkerTeal, sf::Color::White, 0);
    file.setColorList(sf::Color::White, sf::Color::White, darkGrey, 0);

    menu.addMenuItem(trans);
    menu.addMenuItem(file);
    menu.setPosition(sf::Vector2f{1200, 50});

    top.setSize(sf::Vector2f{1800,150});
    top.setFillColor(darkerTeal);
    top.setPosition(0,0);
}
