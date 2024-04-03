//
// Created by hanil on 10/12/2023.
//

#ifndef SFML_PROJECTS_HELPER_H
#define SFML_PROJECTS_HELPER_H
#include <SFML/Graphics.hpp>
#include <cmath>

class helper {
public:

    template<typename T, typename U>
    static void leftAlign(const T &big, U& small);
    template<typename T, typename U>
    static void leftAdjacent(const T &right, U& Left, int margin);
    template<typename T, typename U>
    static void leftAdjacent1(T &right, const U& Left, int margin);
    template<typename T>
    static void centerText(const T &obj, sf::Text& text);
    template<typename T, typename U>
    static void verticalAlign(const T &top, U& bottom);
    template<typename T, typename U>
    static void verticalAlignMargin(const T &top,  U& bottom, int margin);

};




#include "helper.cpp"
#endif //SFML_PROJECTS_HELPER_H
