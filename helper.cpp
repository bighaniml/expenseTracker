//
// Created by hanil on 10/12/2023.
//

#ifndef SFML_PROJECTS_HELPER_CPP
#define SFML_PROJECTS_HELPER_CPP

#include <iostream>
#include "helper.h"





template<typename T, typename U>
void helper::leftAlign(const T &big, U &small) {
    sf::FloatRect bigBounds = big.getGlobalBounds();
    sf::FloatRect  smallBounds = small.getGlobalBounds();
    int gap = 5;
    sf::Vector2f leftCenter = {bigBounds.left + gap, bigBounds.top + (bigBounds.height/2.f) - (smallBounds.height/2.f) };
    const float yOffset = smallBounds.height/2.f + leftCenter.y;
    sf::Vector2f position = {leftCenter.x, leftCenter.y};
    small.setPosition(position);



}

template<typename T, typename U>
void helper::leftAdjacent(const T &right, U &left, int margin) {
    sf::FloatRect rightBounds = right.getGlobalBounds();
    sf::FloatRect leftBounds = left.getGlobalBounds();
    int leftXVal = rightBounds.left - leftBounds.width - margin;
    int leftYVal = rightBounds.top + rightBounds.height/2.f - leftBounds.height/2.f;
    left.setPosition(leftXVal, leftYVal);

}

template<typename T>
void helper::centerText(const T &obj, sf::Text& text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});
}

template<typename T, typename U>
void helper::verticalAlign(const T &top, U &bottom) {
    sf::FloatRect bounds = top.getGlobalBounds();
    bottom.setPosition(sf::Vector2f{bounds.left, bounds.top + bounds.height});
}

template<typename T, typename U>
void helper::verticalAlignMargin( const T &top, U &bottom, int margin) {
    sf::FloatRect bounds = top.getGlobalBounds();
    bottom.setPosition(sf::Vector2f{bounds.left, bounds.top + bounds.height + margin});
}

template<typename T, typename U>
void helper::leftAdjacent1(T &right, const U &left, int margin) {
//    sf::FloatRect rightBounds = right.getGlobalBounds();
//    sf::FloatRect leftBounds = left.getGlobalBounds();
    float rightXVal = left.getGlobalBounds().left + left.getGlobalBounds().width + margin;
    right.setPosition(sf::Vector2f{rightXVal, left.getGlobalBounds().top});
    std::cout << "in function : " << left.getGlobalBounds().top << "\n";
}

#endif