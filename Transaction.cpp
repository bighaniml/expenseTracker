//
// Created by hanil on 12/9/2023.
//

#include "Transaction.h"


Transaction::Transaction() {
    setUp();
    setPosition(sf::Vector2f{20,20});
}

Transaction::Transaction(const std::string &amount, const std::string &date, const std::string &category,
                         const std::string &type, const std::string &note) : amount(amount), date(date),
                                                                             category(category), type(type),
                                                                             note(note) {
    //set all sf Text, font, size, and color -- or make a diff function to do it
    setUp();
    setPosition(sf::Vector2f{20,20});

}

void Transaction::setAmount(const std::string &amount) {
    Transaction::amount = amount;
}

void Transaction::setDate(const std::string &date) {
    Transaction::date = date;
}

void Transaction::setCategory(const std::string &category) {
    Transaction::category = category;
}

void Transaction::setType(const std::string &type) {
    Transaction::type = type;
}

void Transaction::setNote(const std::string &note) {
    Transaction::note = note;
}

const std::string &Transaction::getAmount() const {
    return amount;
}

const std::string &Transaction::getDate() const {
    return date;
}

const std::string &Transaction::getCategory() const {
    return category;
}

const std::string &Transaction::getType() const {
    return type;
}

const std::string &Transaction::getNote() const {
    return note;
}

Snapshot &Transaction::getSnapshot() {
    //later
}

void Transaction::applySnapshot(const Snapshot &snapshot) {
    //later
}

void Transaction::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //does nothing
}

void Transaction::update() {
    dateLabel.setLabel(date);
    noteLabel.setLabel(note);
    categoryLabel.setLabel(category);
    amountLabel.setLabel("$" + amount);

    if(type == "Expense") {
        amountLabel.setLabel("-$" + amount);
        amountLabel.setTextColor(darkGrey);
    }
    else{
        amountLabel.setTextColor(teal);
    }
}

void Transaction::draw(sf::RenderTarget &target, sf::RenderStates states) const {
//    target.draw(box);
    target.draw(dateLabel);
    target.draw(noteLabel);
    target.draw(categoryLabel);
    target.draw(amountLabel);
}



void Transaction::setUp() {
    dateLabel.setBoxSize(sf::Vector2f{150, 25});
    dateLabel.setLabelSize(20);
    dateLabel.setLabel(date);
    dateLabel.setBoxColor(sf::Color::White, sf::Color::Black, 0);
    dateLabel.setTextColor(darkGrey);
    noteLabel.setBoxSize(sf::Vector2f{300, 25});
    noteLabel.setLabel(note);
    noteLabel.setLabelSize(20);
    noteLabel.setBoxColor(sf::Color::White, sf::Color::White, 0);
    noteLabel.setTextColor(darkGrey);
    categoryLabel.setBoxSize(sf::Vector2f{200, 25});
    categoryLabel.setLabelSize(20);
    categoryLabel.setLabel(category);
    categoryLabel.setBoxColor(sf::Color::White, sf::Color::White, 0);
    categoryLabel.setTextColor(darkGrey);
    amountLabel.setBoxSize(sf::Vector2f{100, 25});
    amountLabel.setLabelSize(20);
    amountLabel.setLabel("$" + amount);
    amountLabel.setBoxColor(sf::Color::White, sf::Color::White, 0);
    if(type == "Expense") {
        amountLabel.setLabel("-$" + amount);
        amountLabel.setTextColor(darkGrey);
    }
    else{
        amountLabel.setTextColor(teal);
    }
}

void Transaction::setPosition(const sf::Vector2f &position) {
    box.setPosition(position);
    dateLabel.setPosition(sf::Vector2f{box.getPosition().x, box.getPosition().y});
    noteLabel.setPosition(sf::Vector2f {dateLabel.getGlobalBounds().left + dateLabel.getGlobalBounds().width, dateLabel.getPosition().y});
    categoryLabel.setPosition(sf::Vector2f{noteLabel.getGlobalBounds().left + noteLabel.getGlobalBounds().width, dateLabel.getPosition().y});
    amountLabel.setPosition(sf::Vector2f{categoryLabel.getGlobalBounds().left + categoryLabel.getGlobalBounds().width, dateLabel.getPosition().y});

}

sf::FloatRect Transaction::getGlobalBounds() const {
    sf::FloatRect bounds;
    bounds.top = dateLabel.getGlobalBounds().top;
    bounds.left = dateLabel.getGlobalBounds().left;
    bounds.width = amountLabel.getGlobalBounds().width + amountLabel.getGlobalBounds().left - dateLabel.getGlobalBounds().left;
    bounds.height = dateLabel.getGlobalBounds().height;
    return bounds;
}

void Transaction::operator=(const Transaction &rhs) {
    amount = rhs.amount;
    date = rhs.date;
    category = rhs.category;
    type = rhs.type;
    note = rhs.note;
}


