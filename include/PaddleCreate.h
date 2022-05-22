#ifndef JUMPJUMP_PADDLECREATE_H
#define JUMPJUMP_PADDLECREATE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Paddle.h"
#include <cstdlib>
#include <ctime>
#include <list>
#include <iostream>

using namespace std;
using namespace sf;

class PaddleCreate
{
private:
    Texture paddleFastTexture, paddleNormalTexture, paddleSlowTexture;
    SoundBuffer jumpSoundBuffer;
    float totalMove;
    list <Paddle> paddles;
    int random(int min, int max);
    void create (Vector2f pos);
    void createInit();
    void createNext();
public:
    Sound jumpSound;
    PaddleCreate();
    void Update(float deltaTime);
    void Move(float distance);
    void Draw(RenderTarget& target);
    float Collision(const Sprite player);
};
#endif //JUMPJUMP_PADDLECREATE_H
