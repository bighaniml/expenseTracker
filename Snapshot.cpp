//
// Created by hanil on 11/11/2023.
//

#include "Snapshot.h"

void Snapshot::storeHistory(const std::string& history) {
    this->history = history;
}

std::string& Snapshot::getHistory(){
    return history;
}

