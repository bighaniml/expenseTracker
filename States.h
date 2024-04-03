//
// Created by hanil on 11/11/2023.
//

#ifndef SFML_PROJECTS_STATES_H
#define SFML_PROJECTS_STATES_H
#include "ObjectState.h"
#include <map>

class States {
public:
    States();
    bool isEnabled(const ObjectState& state) const;
    void disableState(const ObjectState& state);
    void enableState(const ObjectState& state);
private:
    std::map<ObjectState, bool> states;
};


#endif //SFML_PROJECTS_STATES_H
