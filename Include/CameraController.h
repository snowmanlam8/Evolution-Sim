#pragma once
#include "raylib.h"

class CameraController {
    public:
        CameraController();
        void update(float dt);
        Camera3D getCamera() const;

    private:
        Camera3D camera;
};