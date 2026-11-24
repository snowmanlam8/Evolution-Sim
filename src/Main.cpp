#include "raylib.h"
#include "Utilities.h"
#include "Animal.h"
#include "Food.h"
#include "CameraController.h"
#include <vector>
#include <iostream>
#include <random>
using std::string;
float getRandomNumber(float min, float max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    
    std::uniform_real_distribution<float> dist(min, max); 
    
    return dist(gen);
}


int main() {
    const int screenWidth = 1500;
    const int screenHeight = 1000;
    std::vector<Food> foods;
    float x = getRandomNumber(-20,20);
    float z = getRandomNumber(-20,20);
    Vector3 newPos = {x,5.0f,z};
    for (int i = 0; i < getRandomNumber(1,50);i++){
        Food newFood = Food(5, i);
        newFood.setPosition({getRandomNumber(-20,20), 5, getRandomNumber(-20,20)});
        foods.push_back(newFood);
    }
    foods[0].setPosition(newPos);
    InitWindow(screenWidth, screenHeight, "Raylib C++ Test");
    SetTargetFPS(60);
    CameraController camera;
    Vector3 cubeLocation = {0.0f, 5.0f, 20.0f};
    Animal animal = Animal(cubeLocation, 0);
    while (!WindowShouldClose()) {
        float dt = GetFrameTime();

        // UPDATES
        camera.update(dt);
        animal.update(dt, foods);
        cubeLocation = animal.getPosition();
        if (animal.canEatFood()){
            int id = animal.eatFood();
            int index = findEntityIndexById(foods,id);
            foods[index].setActive(false);
        }

        // draw
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(camera.getCamera());
        DrawPlane({0,0,0},{500.0f,500.0f}, DARKGREEN);
        for (int i = 0; i < foods.size(); i++){
            if (!foods[i].isActive()){continue;}
            DrawCube(foods[i].getPosition(), 2.0f, 2.0f, 2.0f, BLUE);
        }
        
        DrawCube(cubeLocation, 1.0f, 1.0f,1.0f, RED);
        // DrawGrid(50, 1.0f);
        EndMode3D();
        // Any text or 2D UI overlay goes out here, completely unaffected by the 3D depth
        DrawFPS(10, 10);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}



