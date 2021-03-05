#ifndef CAMERA2D_COMPONENT_H
#define CAMERA2D_COMPONENT_H

#include "engine/EntityManager.h"
#include "engine/Components/Transform2D.h"
#include "engine/Constants.h"

class Camera2D : public Component{
    public:
        bool followTarget = false;
        Camera2D(int cameraPosX, int cameraPosY, int destinationPosX, int destinationPosY);
        virtual void Init() override;
        virtual void Update(float delta) override;
        int GetCameraPosX(), GetCameraPosY();
    private:
        int cameraPosX, cameraPosY;
        int cameraWidth, cameraHeight;
        Transform2D* mainPlayerTransform;
};

#endif