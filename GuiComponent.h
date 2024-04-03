//
// Created by hanil on 11/11/2023.
//

#ifndef SFML_PROJECTS_GUICOMPONENT_H
#define SFML_PROJECTS_GUICOMPONENT_H


#include "EventHandler.h"
#include "SnapshotInterface.h"

class GuiComponent: public EventHandler, public sf::Drawable, public SnapshotInterface {
public:
    //virtual void snapShotInterface functions
    Snapshot &getSnapshot() = 0;
    void applySnapshot(const Snapshot &snapshot)= 0;
    //virtual void EventHandler functions
    void addEventHandler(sf::RenderWindow& window, sf::Event event)= 0;
    void update() = 0;
    //drawable virtual void functions
    void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
private:
    Snapshot snapshot;
};

#endif //SFML_PROJECTS_GUICOMPONENT_H
