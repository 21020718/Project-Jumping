#ifndef JUMPJUMP_PADDLE_H
#define JUMPJUMP_PADDLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <cstdlib>
#include "CONST.h"

using namespace std;
using namespace sf;

class Paddle
{
private:
    int moveType;
    float moveDistance;
    int direction;
    int speed;
public:
    int type;
    Sprite sprite;
    Paddle();
    void Update(float deltaTime);
};
#endif //JUMPJUMP_PADDLE_H
