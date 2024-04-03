//
// Created by hanil on 11/11/2023.
//

#include "States.h"

bool States::isEnabled(const ObjectState &state) const  {
    if(states.at(state) == true){
        return true;
    }
    return false;
}

void States::disableState(const ObjectState &state) {
    states[state] = false;
}

void States::enableState(const ObjectState &state) {
    states[state] = true;
}

States::States(){
    //add all states in enum to map
    states[HIDDEN] = false;
    states[BLINKING] = false;
    states[HIGHLIGHTED] = false;
    states[DISABLED] = false;
    states[VISIBLE] = false;
}

