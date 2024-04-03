//
// Created by hanil on 12/11/2023.
//

#include "BarGraph.h"

Snapshot &BarGraph::getSnapshot() {
}

void BarGraph::applySnapshot(const Snapshot &snapshot) {
}

void BarGraph::addEventHandler(sf::RenderWindow &window, sf::Event event) {
}

void BarGraph::update() {
    setUp();

}

void BarGraph::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box);
    target.draw(netLabel);
    target.draw(expenseLabel);
    target.draw(incomeLabel);
    if(income1 != 0) {
        target.draw(income);
    }
    if(expenses1 != 0) {
        target.draw(expenses);
    }
    if(net1 != 0) {
        target.draw(net);
    }
}

void BarGraph::setPosition(const sf::Vector2f &position) {
    int margin = 25;
    box.setPosition(position);
    income.setPosition(box.getPosition().x + margin, box.getPosition().y + 75);
    incomeLabel.setPosition(income.getPosition().x, income.getPosition().y - incomeLabel.getGlobalBounds().height -30);
    expenses.setPosition(income.getPosition().x, income.getPosition().y +  50 + 75);
    expenseLabel.setPosition(expenses.getPosition().x, expenses.getPosition().y - expenseLabel.getGlobalBounds().height -30);
    net.setPosition(income.getPosition().x, expenses.getPosition().y + 50 + 75);
    netLabel.setPosition(net.getPosition().x, net.getPosition().y - netLabel.getGlobalBounds().height -30);
}

void BarGraph::setUp() {
    netLabel.setFont(Font::getFont(WIDGET_REGULAR));
    netLabel.setCharacterSize(15);
    netLabel.setFillColor(darkGrey);
    netLabel.setString("Net");

    expenseLabel.setFont(Font::getFont(WIDGET_REGULAR));
    expenseLabel.setCharacterSize(15);
    expenseLabel.setFillColor(darkGrey);
    expenseLabel.setString("Expenses");

    incomeLabel.setFont(Font::getFont(WIDGET_REGULAR));
    incomeLabel.setCharacterSize(15);
    incomeLabel.setFillColor(darkGrey);
    incomeLabel.setString("Income");
    if(income1 > expenses1){
        income.setSize(sf::Vector2f {300, 40});
        float ratio = expenses1/income1;
        expenses.setSize(sf::Vector2f{300*ratio,40});
        net1 = income1 - expenses1;
        net.setSize(sf::Vector2f{(net1/income1)*300, 40 });
    }else{
        expenses.setSize(sf::Vector2f {300, 40});
        float ratio = income1/expenses1;
        income.setSize(sf::Vector2f{300*ratio,40});
        net1 = income1 - expenses1;
        net.setSize(sf::Vector2f{(std::abs(net1)/expenses1)*300, 40 });
    }

    income.setFillColor(sf::Color{106, 203, 193});
    expenses.setFillColor(sf::Color{203, 106, 116});
    if(net1 < 0) {
        net.setFillColor(sf::Color{203, 106, 116});
    }else{
        net.setFillColor(sf::Color{106, 203, 193});
    }
    }

const std::list<Transaction> &BarGraph::getGains() const {
    return gains;
}

const std::list<Transaction> &BarGraph::getLoss() const {
    return loss;
}

void BarGraph::setGains(const std::list<Transaction> &gains) {
    this->gains = gains;
}

void BarGraph::setLoss(const std::list<Transaction> &loss) {
    this->loss = loss;
}

void BarGraph::calculateGains() {
    if(!gains.empty()){
        for(auto &transaction: gains){
            std::cout << transaction.getAmount();
           // std::cout << gains.size();
            income1 += std::stof(transaction.getAmount());
        }
    }else{
        income1 = 0;
    }
}

void BarGraph::calculateLoss() {
    if(!loss.empty()){
        for(auto &transaction: loss){
            expenses1 += std::stof(transaction.getAmount());
        }
    }else{
        expenses1 = 0;
    }
}
