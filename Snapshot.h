//
// Created by hanil on 11/11/2023.
//

#ifndef SFML_PROJECTS_SNAPSHOT_H
#define SFML_PROJECTS_SNAPSHOT_H
#include <string>

class Snapshot {
private:
    std::string history;
public:
    void storeHistory(const std::string& history);
    std::string& getHistory();
};


#endif //SFML_PROJECTS_SNAPSHOT_H
