#include "Food.h"
#include "raymath.h"
#include "Utilities.h"
#include <iostream>
#include <vector>

Food::Food(int value, int uniqueId) {
    food = value;
    id = uniqueId;
}

int Food::getFood(){
    return food;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
}
Vector3 Food::getPosition(){
    return position;
}
void Food::setPosition(Vector3 newPosition){
    position = newPosition;
}