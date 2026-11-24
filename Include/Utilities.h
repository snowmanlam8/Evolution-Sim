#pragma once
#include <iostream>
#include <vector>
template <typename T>
int findEntityIndexById(const std::vector<T>& entities, int targetId) {
    int low = 0;
    int high = static_cast<int>(entities.size()) - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // As long as class T has a .getId() method, this compiles perfectly!
        if (entities[mid].getId() == targetId) {
            return mid; 
        }
        else if (entities[mid].getId() < targetId) {
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    }

    return -1; 
}

class Entity {
protected:
    int id;
    bool active = true;
public:
    int getId() const { return id; }
    bool isActive() const { return active; }
    void setActive(bool status) { active = status; }
};