#include "../include/Paddle.h"

Paddle::Paddle() :
    type(0),
    moveType(0),
    moveDistance(0),
    direction(1),
    speed(80)
{

}

void Paddle::Update(float deltaTime)
{
    if(type == 4){
        if(moveType == 1) // honrizontal
            sprite.setPosition(sprite.getPosition().x + speed*deltaTime*direction, sprite.getPosition().y);
        else if (moveType == 2) // vertical
            sprite.setPosition(sprite.getPosition().x, sprite.getPosition().y + speed*deltaTime*direction);
        else{
            moveType = 1 + rand()%2;
        }

    }
    moveDistance += speed*deltaTime*direction;

    if(moveDistance > MAX_MOVE_DISTANCE)
        direction = -1;
    else if(moveDistance < -MAX_MOVE_DISTANCE)
        direction = 1;
}