//
// Created by hanil on 12/10/2023.
//

#include "TransactionsWidget.h"

Snapshot &TransactionsWidget::getSnapshot() {

}

void TransactionsWidget::applySnapshot(const Snapshot &snapshot) {
}

void TransactionsWidget::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}

void TransactionsWidget::update() {
    setPosition(sf::Vector2f {box.getPosition().x, box.getPosition().y});
}

void TransactionsWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box);
    target.draw(date);
    target.draw(note);
    target.draw(amount);
    target.draw(category);
    if(!transactions.empty()) {
        auto it = transactions.begin();
        for (int i = 0; i < 10 && it != transactions.end(); i++) {
            target.draw(*it);
            it++;
        }
    }
}

void TransactionsWidget::setUp() {
    date.setFont(Font::getFont(WIDGET_SEMI_BOLD));
    date.setCharacterSize(25);
    date.setFillColor(darkGrey);
    date.setString("Date");
    //note
    note.setFont(Font::getFont(WIDGET_SEMI_BOLD));
    note.setCharacterSize(25);
    note.setFillColor(darkGrey);
    note.setString("Note");
    //category
    category.setFont(Font::getFont(WIDGET_SEMI_BOLD));
    category.setCharacterSize(25);
    category.setFillColor(darkGrey);
    category.setString("Category");
    //amount
    amount.setFont(Font::getFont(WIDGET_SEMI_BOLD));
    amount.setCharacterSize(25);
    amount.setFillColor(darkGrey);
    amount.setString("Amount");


}

void TransactionsWidget::setPosition(const sf::Vector2f& position) {
    int margin = 25;
    box.setPosition(position);
    date.setPosition(box.getPosition().x + margin, box.getPosition().y + margin);
    note.setPosition(date.getPosition().x + 150, date.getPosition().y);
    category.setPosition(note.getPosition().x + 300, date.getPosition().y);
    amount.setPosition(category.getPosition().x + 200, date.getPosition().y);
   if(!transactions.empty()) {
       auto it = transactions.begin();
       for (int i = 0; i < 10 && it != transactions.end(); i++) {
           it->setPosition(sf::Vector2f{box.getPosition().x + margin, 50 + date.getPosition().y + i * 25});
           it++;
       }
   }

}

TransactionsWidget::TransactionsWidget() {
    setUp();
    setPosition(sf::Vector2f{0,0});
}

void TransactionsWidget::setTransactions(const std::list<Transaction> &transactions) {
    this->transactions = transactions;
}

void TransactionsWidget::addTransaction(const Transaction &transaction) {
    transactions.push_front(transaction);
}

sf::FloatRect TransactionsWidget::getGlobalBounds() const {
    return box.getGlobalBounds();
}

void TransactionsWidget::clearTransactions() {
    transactions.clear();
    std::cout << "Empty? " << transactions.empty();
}

