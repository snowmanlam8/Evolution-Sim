#pragma once
#include "raylib.h"
#include "Utilities.h"
#include <iostream>



class Food : public Entity {
    public:
        Food(int value, int uniqueId);
        int getFood();
        Vector3 getPosition();
        void setPosition(Vector3 newPosition);

    private:
        int food;
        Vector3 position;
};