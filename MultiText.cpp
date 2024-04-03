//
// Created by hanil on 11/7/2023.
//

#include "MultiText.h"

void MultiText::push_back(const Letter &letter) {
    letters.push_back(letter);
//    recolor();
}

void MultiText::pop_back() {
    if(!letters.empty()) {
        letters.pop_back();
    }
}
std::list<Letter>::reverse_iterator MultiText::rbegin(){
    return letters.rbegin();
}
std::list<Letter>::reverse_iterator MultiText::rend(){
    return letters.rend();
}
std::list<Letter>::iterator MultiText::begin() {
    return letters.begin();
}

std::list<Letter>::iterator MultiText::end() {
    return letters.end();
}

std::list<Letter>::const_iterator MultiText::begin() const {
    return letters.begin();
}

std::list<Letter>::const_iterator MultiText::end() const {
    return letters.end();
}

void MultiText::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(std::list<Letter>::const_iterator it = letters.begin(); it != letters.end(); it++){
        window.draw(*it);
    }
}

int MultiText::getSize() {
    return letters.size();
}

void MultiText::setPosition(const sf::Vector2f &position) {
        if(!letters.empty()){
            initPos = position;
        }
        float xPos = initPos.x;
        int gap = 2;
        for(auto &letter : letters){
            letter.setPosition(xPos, position.y);
            xPos += letter.getGlobalBounds().width + gap;
        }
}

bool MultiText::empty() {
    if(letters.empty()){
        return true;
    }
    return false;
}

void MultiText::recolor() {
        int random = rand() %3;
        if(random == 2){
            letters.back().setColor(sf::Color::Magenta);
        }
        else if(random == 1){
            letters.back().setColor(sf::Color::Cyan);
        }
        else{
            letters.back().setColor(sf::Color::White);
        }
}
const sf::FloatRect MultiText::getGlobalBounds() const {
    if(!letters.empty()) {
        float top = letters.front().getGlobalBounds().top;
        float left = letters.front().getGlobalBounds().left;
        float height = letters.front().getGlobalBounds().height;
        float width = letters.size()*(letters.back().getGlobalBounds().width);
        return sf::FloatRect(top, left, height, width);
    }
    else{
        return sf::FloatRect{0,0,0,0};
    }
}

void MultiText::setSize(int size) {
    for(auto &letter : letters) {
        letter.setCharacterSize(size);
    }
}

void MultiText::clear() {
    letters.clear();
}


