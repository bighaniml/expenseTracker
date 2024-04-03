//
// Created by hanil on 11/11/2023.
//

#include "GuiComponent.h"


Snapshot& GuiComponent::getSnapshot(){
    snapshot.getHistory();
}

void GuiComponent::applySnapshot(const Snapshot &snapshot){
    this->snapshot = snapshot;
}

void GuiComponent::addEventHandler(sf::RenderWindow& window, sf::Event event){
    //this matters
}

void GuiComponent::update(){
    //this matters
}

void GuiComponent::draw(sf::RenderTarget &target, sf::RenderStates states) const{
    //this matters
}

