#include "Utilities.h"
#include "Animal.h"
#include "Food.h"
#include "raymath.h"
#include <iostream>
#include <vector>
#include <cfloat> // 1. Include this header to get FLT_MAX

Animal::Animal(Vector3 startingPosition, int uniqueId){
    position = startingPosition;
    id = uniqueId;
    hasTargetFood = false; // Initialize to false explicitly
}

void Animal::update(float dt, std::vector<Food>& foods){
    if (foods.empty()) return; // Prevent crashes if there's no food

    if (!hasTargetFood){
        currentFoodId = findFood(foods);
    }
    else{
        move(foods);
    }
}

void Animal::move(std::vector<Food> foods){
    if (hasTargetFood && currentFoodId >= 0){
        int foodIndex = findEntityIndexById(foods, currentFoodId);
        Food food = foods[foodIndex];
        Vector3 foodPositon = food.getPosition();
        Vector3 direction = Vector3Subtract(foodPositon, position);
        
        // Check if we arrived close to the food (e.g., within 0.5 units)
        if (Vector3Length(direction) < 0.5f) {
            readyToEat = true;
            hasTargetFood = false; // Stop moving so we can look for new food
            return;
        }

        direction = Vector3Normalize(direction);
        float speed = 5.0f;
        velocity = Vector3Scale(direction, speed);
        
        position = Vector3Add(position, Vector3Scale(velocity, GetFrameTime()));
    }
}

int Animal::findFood(std::vector<Food>& foods){
    // 2. Start with the absolute maximum possible float value
    float shortestDistance = FLT_MAX; 
    int closestIndex = 0;
    bool foundAny = false;

    for (int i = 0; i < foods.size(); i++){
        if (!foods[i].isActive()){continue;}
        float currentDistance = Vector3Distance(position, foods[i].getPosition());
        if (currentDistance < shortestDistance) {
            shortestDistance = currentDistance;
            closestIndex = i;
            foundAny = true;
        }
    }

    if (foundAny) {
        // 3. Fix: Use a single '=' to actually assign the value to true
        hasTargetFood = true; 
        return foods[closestIndex].getId();
    }
    
    return -1;
}

Vector3 Animal::getPosition(){
    return position;
}
int Animal::eatFood(){
    readyToEat = false;
    int eatenFood = currentFoodId;
    currentFoodId = -1;
    hasTargetFood = false;
    return eatenFood;
}
bool Animal::canEatFood(){
    return readyToEat;
}


