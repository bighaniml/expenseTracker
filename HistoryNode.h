//
// Created by hanil on 11/24/2023.
//

#ifndef SFML_PROJECTS_HISTORYNODE_H
#define SFML_PROJECTS_HISTORYNODE_H
#include "SnapshotInterface.h"
#include "GuiComponent.h"
struct HistoryNode
{
    Snapshot snapshot;
    GuiComponent* component;
};
#endif //SFML_PROJECTS_HISTORYNODE_H
