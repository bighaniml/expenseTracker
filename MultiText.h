//
// Created by hanil on 11/7/2023.
//

#ifndef SFML_PROJECTS_MULTITEXT_H
#define SFML_PROJECTS_MULTITEXT_H
#include <SFML/Graphics.hpp>
#include "Letter.h"
#include "helper.h"
#include <list>

class MultiText: public sf::Drawable{
private:
    std::list<Letter> letters;
    sf::Vector2f initPos;
public:
    const sf::FloatRect getGlobalBounds() const;
    void push_back(const Letter& letter);
    void pop_back();
    void setPosition(const sf::Vector2f& position);
    void recolor();
    void clear();
    bool empty();
    //iterators
    std::list<Letter>::iterator begin();
    std::list<Letter>::iterator end();
    std::list<Letter>::reverse_iterator rbegin();
    std::list<Letter>::reverse_iterator rend();
    std::list<Letter>::const_iterator begin() const;
    std::list<Letter>::const_iterator end() const;
    //draw
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    //getter
    int getSize();
    void setSize(int size);
};


#endif //SFML_PROJECTS_MULTITEXT_H
