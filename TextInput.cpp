//
// Created by hanil on 11/16/2023.
//

#include "TextInput.h"

void TextInput::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(label);
    target.draw(textBox);
    target.draw(cursor);
    target.draw(text);

}

Snapshot &TextInput::getSnapshot() {
    //make snapshot when we add or get rid of stuff in multitext
}

void TextInput::applySnapshot(const Snapshot &snapshot) {
    //do this when we control z
}

//changes the state & handles specific events
void TextInput::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(event.type == sf::Event::TextEntered && text.getSize() < 25 && cursorState.isEnabled(BLINKING)){
        if(event.text.unicode >= 32 && event.text.unicode <= 126 || event.text.unicode == 20){
            // text.rbegin()->getPosition().x < textBox.getGlobalBounds().left + textBox.getGlobalBounds().width - 3*text.rbegin()->getGlobalBounds().width
            if((cursor.getGlobalBounds().left + 10 < textBox.getGlobalBounds().left + textBox.getGlobalBounds().width)) {
                std::cout << static_cast<char>(event.text.unicode) << std::endl;
                text.push_back(Letter(static_cast<char>(event.text.unicode), cursor.getSize().y));
            }
            if(text.getSize() == 1)
            {
                //positions letters after first
                text.setPosition(cursor.getPosition());
            }

        }
    }
    if(event.type == sf::Event::KeyPressed && cursorState.isEnabled(BLINKING)){
        if(event.key.code == sf::Keyboard::Key::Backspace && !text.empty()){
            text.pop_back();
        }
        if(KeyShortcuts::isUndo(window, event) && !text.empty()){
            text.pop_back();
        }
    }
//
    if(MouseEvents<sf::RectangleShape>::mouseClicked(textBox, window)){
        cursorState.disableState(HIDDEN);
        cursorState.enableState(BLINKING);
    }
    if(!MouseEvents<sf::RectangleShape>::mouseClicked(textBox, window) && MouseEvents<sf::RectangleShape>::mouseClicked(window, event)){
        cursorState.disableState(BLINKING);
        cursorState.enableState(HIDDEN);
    }
}

//handles the states
void TextInput::update() {
    //position cursor when no text, just incase letters is empty(like when popback)
    if(text.empty()){
        helper::leftAlign(textBox, cursor);
    }
    if(cursorState.isEnabled(BLINKING)){
        blinkCursor();
    }
    if(cursorState.isEnabled(HIDDEN)){
        hideCursor();
    }
    text.setPosition(sf::Vector2f(text.begin()->getPosition().x, text.begin()->getPosition().y));
    moveCursor();
    //checks for int and turns it blue if found, then do the same for other type words
//    turnIntBlue();
//    turnDoubleBlue();
//    turnCharBlue();
//    turnFloatBlue();
//    turnOpRed();
//    turnNumGreen();
}

TextInput::TextInput(){

    clock.restart();
    textBox.setOutlineThickness(2);
    textBox.setOutlineColor(sf::Color(173,173,173));
    textBox.setPosition(100, 100);
    textBox.setFillColor(sf::Color::White);
    textBox.setSize(sf::Vector2f{200,50});
    cursor.setSize(sf::Vector2f{2, 20});
    cursor.setFillColor(sf::Color::Black);
    helper::leftAlign(textBox, cursor);
    hideCursor();
    label.setCharacterSize(textBox.getSize().y/2);
    label.setString(labelString);
    label.setFillColor(sf::Color(210, 145, 188));
    label.setPosition(0,0);
    label.setFont(Font::getFont(WIDGET));
    //position textBox
    helper::leftAdjacent(textBox, label, 10);
}

void TextInput::blinkCursor() {
    sf::Time time = clock.getElapsedTime();
    if(static_cast<int>(time.asSeconds()) % 2 == 0){
        hideCursor();
    }else{
        cursor.setFillColor(sf::Color::Black);
    }
}

void TextInput::hideCursor() {
    cursor.setFillColor(sf::Color::Transparent);
}

void TextInput::moveCursor() {
    int offsetX = 2;
    if(!text.empty()) {
        //there's a bug here. sometimes rbegin first pos is read as 0. I think something gets pushed back
        //and doesn't get repositioned. so cursorX just gets set to whats added. ==> I think I fixed this
        int cursorX = text.rbegin()->getPosition().x + text.rbegin()->getGlobalBounds().width + offsetX;
            cursor.setPosition(cursorX, cursor.getPosition().y);
    }

}

void TextInput::setPosition(const sf::Vector2f &position) {
    textBox.setPosition(position);
    if(orientation == BELOW) {
        helper::verticalAlignMargin(textBox, label, labelMargin);
    }
    else if(orientation == LEFT) {
        helper::leftAdjacent(textBox, label, labelMargin);
    }
    else if(orientation == ABOVE) {
        label.setPosition(position);
//        float newY = position.y + label.getGlobalBounds().height;
//        textBox.setPosition(position.x, newY);
        helper::verticalAlignMargin(label, textBox, labelMargin);
    }
}


std::string TextInput::listToString() {
    std::list<Letter>::iterator it;
    std::string toString;
    for(it = text.begin(); it != text.end(); it++){
        toString += it->getLetter();
    }
    return toString;
}

int TextInput::findInt(const std::string &string) {
    return string.find("int");
}

void TextInput::turnBlue(int start, int length) {
    if(start != std::string::npos){
        std::list<Letter>::iterator it = text.begin();
        int counter = 0;
        while(counter < start){
            it++;
            counter++;
        }
        for(int i = 0; i < length; i++){
            it->setColor(sf::Color::Blue);
            it++;
        }
    }
}

void TextInput::turnIntBlue() {
    std::string str = listToString();
    int start = findInt(str);
    turnBlue(start, 3);
}

int TextInput::findDouble(const std::string &string) {
    return string.find("double");
}

int TextInput::findChar(const std::string &string) {
    return string.find("char");
}

int TextInput::findFloat(const std::string &string) {
    return string.find("float");
}

void TextInput::turnDoubleBlue() {
    std::string str = listToString();
    int start = findDouble(str);
    turnBlue(start, 6);
}

void TextInput::turnCharBlue() {
    std::string str = listToString();
    int start = findChar(str);
    turnBlue(start, 4);
}

void TextInput::turnFloatBlue() {
    std::string str = listToString();
    int start = findFloat(str);
    turnBlue(start, 5);
}

void TextInput::turnNumGreen() {
    std::list<Letter>::reverse_iterator it = text.rbegin();
    if(std::isdigit(it->getLetter())){
        it->setColor(sf::Color::Green);
    }
}

void TextInput::turnOpRed() {
    std::list<Letter>::reverse_iterator it = text.rbegin();
    if(isOp(it->getLetter())){
        it->setColor(sf::Color::Red);
    }
}

bool TextInput::isOp(char letter) {
    return (letter == '*' || letter == '/' || letter == '+' || letter == '-' || letter == '=');
}

sf::FloatRect TextInput::getGlobalBounds() const {
    sf::FloatRect bounds;
    bounds.width = label.getGlobalBounds().width + textBox.getGlobalBounds().width;
    bounds.left = label.getGlobalBounds().left;
    if(orientation == LEFT || orientation == BELOW) {
        bounds.top = textBox.getGlobalBounds().top;
    } else{
        bounds.top = label.getGlobalBounds().top;
        bounds.width =  textBox.getGlobalBounds().width;
    }
    bounds.height = textBox.getGlobalBounds().height;
    return bounds;
}

void TextInput::orientLabel(const Position &position) {
    if(position == ABOVE){
        orientation = ABOVE;
        helper::verticalAlignMargin(label, textBox, 5);
    }
    else if( position == BELOW){
        orientation = BELOW;
        helper::verticalAlignMargin(textBox, label, 5);
    }
    else{
        orientation = LEFT;
        helper::leftAdjacent(textBox, label, 10);
    }
}
void TextInput::setLabel(const std::string &label) {
    this->label.setString(label);
}

void TextInput::setLabelSize(int size) {
    label.setCharacterSize(size);
    orientLabel(orientation);
}

void TextInput::setLabelColor(const sf::Color &color) {
    label.setFillColor(color);
}

sf::FloatRect TextInput::labelGlobalBounds() const {
    return label.getLocalBounds();
}

sf::FloatRect TextInput::boxGetGlobalBounds() const {
    return textBox.getGlobalBounds();
}

void TextInput::setSize(const sf::Vector2f &size) {
    textBox.setSize(size);
}

void TextInput::clear() {
    text.clear();
    helper::leftAlign(textBox, cursor);
}

std::string TextInput::getLabel() {
    return label.getString();
}
