//
// Created by hanil on 11/11/2023.
//

#ifndef SFML_PROJECTS_SNAPSHOTINTERFACE_H
#define SFML_PROJECTS_SNAPSHOTINTERFACE_H
#include "SnapShot.h"

class SnapshotInterface {
public:
    virtual Snapshot& getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot& snapshot) = 0;
};


#endif //SFML_PROJECTS_SNAPSHOTINTERFACE_H
