#include "gameplay/Components/Player.h"

Player::Player(){}

void Player::Init(){
    //Getting Components
    transform = owner -> GetComponent<Transform2D>();
    animatedSprite = owner -> GetComponent<AnimatedSprite>();
    keyboardControl = owner -> GetComponent<KeyboardControl>();
    kinematicBody2D = owner -> GetComponent<KinematicBody2D>();

    //Creating Animations
    animatedSprite->AddAnimation("DownAnimation", 0, 2, 90);
    animatedSprite->AddAnimation("RightAnimation", 1, 2, 90);
    animatedSprite->AddAnimation("LeftAnimation", 2, 2, 90);
    animatedSprite->AddAnimation("UpAnimation", 3, 2, 90);

    //Playing some animation
    animatedSprite->Play("DownAnimation");
}

void Player::Update(float delta){
    //Verifying inputs for the movementation
    if(keyboardControl->IsKeyDown("UP")){
        velocity.y = -moveSpeed * delta;
        animatedSprite->Play("UpAnimation");
    } else if (keyboardControl->IsKeyDown("DOWN")){
        velocity.y = moveSpeed * delta;
        animatedSprite->Play("DownAnimation");
    }else{
        //If not pressing UP and DOWN stop the player
        velocity.y = 0;
    }
    
    if (keyboardControl->IsKeyDown("LEFT")){
        velocity.x = -moveSpeed * delta;
        animatedSprite->Play("LeftAnimation");
    } else if(keyboardControl->IsKeyDown("RIGHT")){
        velocity.x = moveSpeed * delta;
        animatedSprite->Play("RightAnimation");
    }else{
        velocity.x = 0;
    }
    
    //Moving the Player
    kinematicBody2D->Move(velocity); 
}