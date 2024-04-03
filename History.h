//
// Created by hanil on 11/24/2023.
//

#ifndef SFML_PROJECTS_HISTORY_H
#define SFML_PROJECTS_HISTORY_H
#include "HistoryNode.h"
#include <stack>

class History  {


private:
    static std::stack<HistoryNode> stack;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);

};



#endif //SFML_PROJECTS_HISTORY_H
