//
// Created by hanil on 12/6/2023.
//

#include "InputWidget.h"

Snapshot &InputWidget::getSnapshot() {
    return GuiComponent::getSnapshot();
}

void InputWidget::applySnapshot(const Snapshot &snapshot) {
    GuiComponent::applySnapshot(snapshot);
}

void InputWidget::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    amount.addEventHandler(window, event);
    date.addEventHandler(window, event);
    note.addEventHandler(window,event);
    category.addEventHandler(window,event);
    type.addEventHandler(window,event);

    if(MouseEvents<Button>::hovered(clear, window)){
        clear.setColor(lightGrey);
    }else{
        clear.setColor(sf::Color::White);
    }
    if(MouseEvents<Button>::hovered(save, window)){
        save.setColor(lightGrey);
    }else{
        save.setColor(sf::Color::White);
    }
    if(MouseEvents<Button>::mouseClicked(clear, window)){
        clearInputs();
    }
    if(MouseEvents<Button>::mouseClicked(save, window)){
        transaction = getTransaction();
    }
    if(type.getLabelString() == "Income"){
        category.setDisplayLabel("Income");
    }

}

void InputWidget::update() {
    amount.update();
    date.update();
    note.update();
    type.update();
    category.update();
    transaction.update();

}

void InputWidget::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(box);
    target.draw(clear);
    target.draw(save);
    target.draw(label);
    target.draw(amount);
    target.draw(date);
    target.draw(note);
    target.draw(typeLabel);
    target.draw(categoryLabel);
    target.draw(type);
    target.draw(category);
}

InputWidget::InputWidget() {
    setUp();
    setPosition(sf::Vector2f{100,100});
}

void InputWidget::setUp() {
    //label set up
    setLabel("Add Transaction");
    label.setFont(Font::getFont(WIDGET_BOLD));
    label.setCharacterSize(28);
    label.setFillColor(darkGrey);
    label.setPosition(box.getGlobalBounds().left + margin, box.getGlobalBounds().top + margin);
    box.setFillColor(mediumGrey);
    box.setOutlineThickness(1);
    box.setOutlineColor(darkMediumGrey);
    //amount
    amount.setLabel("$");
    amount.orientLabel(ABOVE);
    amount.setLabelColor(darkGrey);
    amount.setLabelSize(25);
    //date
    date.setLabel("Date");
    date.orientLabel(ABOVE);
    date.setLabelColor(darkGrey);
    date.setLabelSize(25);
    //notes
    note.setLabel("Note");
    note.orientLabel(ABOVE);
    note.setLabelColor(darkGrey);
    note.setLabelSize(25);
    note.setSize(sf::Vector2f{amount.getGlobalBounds().width + margin + date.getGlobalBounds().width, 200});
    //category set up;
    category.addMenuItem("Food");
    category.addMenuItem("Entertainment");
    category.addMenuItem("Utilities");
    category.addMenuItem("Personal");
    category.addMenuItem("Transportation");
    category.addMenuItem("Housing");
    category.addMenuItem("Misc.");
    category.setSize(sf::Vector2f{200,50});
    category.setColorList(sf::Color::White, darkMediumGrey, darkGrey, 0);
    category.setColorDisplay(sf::Color::White, darkMediumGrey, darkGrey, 1);
    category.setDisplayLabel("Select Category");
    categoryLabel.setFont(Font::getFont(WIDGET));
    categoryLabel.setCharacterSize(25);
    categoryLabel.setFillColor(darkGrey);
    categoryLabel.setString("Category");
    //category set up;
    type.addMenuItem("Income");
    type.addMenuItem("Expense");
    type.setSize(sf::Vector2f{200,50});
    type.setColorList(sf::Color::White, darkMediumGrey, darkGrey, 0);
    type.setColorDisplay(sf::Color::White, darkMediumGrey, darkGrey, 1);
    type.setDisplayLabel("Select type");
    typeLabel.setFont(Font::getFont(WIDGET));
    typeLabel.setCharacterSize(25);
    typeLabel.setFillColor(darkGrey);
    typeLabel.setString("Type");
    //CLEAR set up
    clear.setLabel("Clear");
    clear.setFontColor(darkGrey);
    clear.setSize(sf::Vector2f{90, 50});
    //Save set up
    save.setLabel("Save");
    save.setFontColor(darkGrey);
    save.setSize(sf::Vector2f{90, 50});

//    if(!transactions.empty()){
//        transactions.front().setPosition(sf::Vector2f{100, 50});
//    }
}

void InputWidget::setPosition(const sf::Vector2f& position) {
    box.setPosition(position);
    label.setPosition(box.getGlobalBounds().left + margin, box.getGlobalBounds().top + margin);
    amount.setPosition(sf::Vector2f{label.getGlobalBounds().left, label.getGlobalBounds().top + label.getGlobalBounds().height + margin});
    helper::leftAdjacent1(date, amount, margin);
//    note.reposition(sf::Vector2f{box.getGlobalBounds().left + 20, box.getGlobalBounds().top + 100});
//    category.setPosition(sf::Vector2f{amount.getGlobalBounds().left + 2*amount.getGlobalBounds().width, amount.getGlobalBounds().top});
    //sets position of category according to date, but aligns vertically with label of date ==> next line corrects this
    helper::leftAdjacent1(category, date, margin);
    //corrects vertical aspect of category
    category.setPosition(sf::Vector2f{category.getGlobalBounds().left, date.boxGetGlobalBounds().top});
    helper::verticalAlignMargin(amount, note, 100);
    //this must be below the positioning of note!
    type.setPosition(sf::Vector2f{category.getGlobalBounds().left, note.boxGetGlobalBounds().top});
    clear.setPosition(sf::Vector2f{type.getGlobalBounds().left + type.getGlobalBounds().width - clear.getGlobalBounds().width, box.getGlobalBounds().top + box.getGlobalBounds().height - (margin + clear.getGlobalBounds().height)});
    save.setPosition(sf::Vector2f{type.getGlobalBounds().left, clear.getGlobalBounds().top});
    categoryLabel.setPosition(category.getGlobalBounds().left, amount.getGlobalBounds().top);
    typeLabel.setPosition(type.getGlobalBounds().left, note.getGlobalBounds().top);
}

void InputWidget::setSize() {

}

void InputWidget::setLabel(const std::string &label) {
    this->label.setString(label);
}

void InputWidget::clearInputs() {
    category.setDisplayLabel("Select category");
    type.setDisplayLabel("Select type");
    amount.clear();
    note.clear();
    date.clear();
}

Transaction InputWidget::getTransaction() {
    Transaction transaction(amount.listToString(), date.listToString(), category.getLabelString(),type.getLabelString(),note.listToString()  );
    return transaction;
}

sf::Vector2f InputWidget::getPosition() {
    return box.getPosition();
}

sf::FloatRect InputWidget::getGlobalBounds() const {
    return box.getGlobalBounds();
}

Button &InputWidget::getButton() {
    return save;
}
