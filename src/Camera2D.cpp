#include "engine/Components/Camera2D.h"

Camera2D::Camera2D(int cameraPosX, int cameraPosY, int cameraWidth, int cameraHeight)
: cameraPosX(cameraPosX), cameraPosY(cameraPosY), cameraWidth(cameraWidth), cameraHeight(cameraHeight){}

void Camera2D::Init(){
    mainPlayerTransform = owner -> GetComponent<Transform2D>();
}

void Camera2D::Update(float delta){
    if(followTarget){
        cameraPosX = mainPlayerTransform-> position.x - (cameraWidth/2);
        cameraPosY = mainPlayerTransform-> position.y - (cameraHeight/2);


        //Clamping the camera position into the map
        cameraPosX = cameraPosX < 0 ? 0 : cameraPosX;
        cameraPosY = cameraPosY < 0 ? 0 : cameraPosY;
        cameraPosX = cameraPosX > cameraWidth ? cameraWidth : cameraPosX;
        cameraPosY = cameraPosY > cameraHeight ? cameraHeight : cameraPosY;
    }
}

int Camera2D::GetCameraPosX(){
    return cameraPosX;
}

int Camera2D::GetCameraPosY(){
    return cameraPosY;
}