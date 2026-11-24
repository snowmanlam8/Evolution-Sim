#pragma once
#include "raylib.h"
#include "Food.h"
#include "Utilities.h"
#include <iostream>
#include <vector>


class Animal : public Entity{ 
    public:
        Animal(Vector3 startingPosition, int uniqueId);
        void update(float dt, std::vector<Food>& foods);
        void move(std::vector<Food> foods);
        Vector3 getPosition();
        bool canEatFood();
        int eatFood();

    private:
        int findFood(std::vector<Food>& foods);
        int currentFoodId = -1;
        bool hasTargetFood = false;
        Vector3 position = {0.0f,0.0f,0.0f};
        Vector3 velocity;
        Vector3 acceleration;
        bool readyToEat = false;
        
        
};