#include "CameraController.h"
#include "raymath.h"


CameraController::CameraController(){
    camera = {};
    camera.position = {0, 60, 70};
    camera.target = {0, 0, 0};
    camera.up = {0, 1, 0};
    camera.fovy = 45;
    camera.projection = CAMERA_PERSPECTIVE;
}
// Control the camera movements
void CameraController::update(float dt){
    bool dPressed = IsKeyDown(KEY_D);
    bool aPressed = IsKeyDown(KEY_A);
    bool wPressed = IsKeyDown(KEY_W);
    bool sPressed = IsKeyDown(KEY_S);
    float scroll = GetMouseWheelMove();
    float wheelPressed = IsMouseButtonDown(MOUSE_BUTTON_MIDDLE);
    float directionX = 0.0f;
    float directionZ = 0.0f;

    // change direction the camera will move depening on the key
    if (dPressed) directionX += 1.0f;
    if (aPressed) directionX -= 1.0f;
    if (sPressed) directionZ += 1.0f;
    if (wPressed) directionZ -= 1.0f;

    // move camera
    float movementX = directionX * 2.0f * dt;
    float movementZ = directionZ * 2.0f * dt;

    // ignore movement when two opposite keys pressed
    if (!(dPressed && aPressed)){
        camera.position.x += movementX;
        camera.target.x += movementX;
    }
    if (!(wPressed && sPressed)){
        camera.position.z += movementZ;
        camera.target.z += movementZ;
    }

    // zoom in
    if (scroll != 0.0f){
        Vector3 direction = Vector3Subtract(
            camera.target,
            camera.position
        );

        direction = Vector3Normalize(direction);

        camera.position = Vector3Add(
            camera.position,
            Vector3Scale(direction, scroll * 2.0f)
        );
    }
    return;
    
}
Camera3D CameraController::getCamera() const{
    return camera;
}

