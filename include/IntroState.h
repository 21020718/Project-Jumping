#ifndef JUMPJUMP_INTROSTATE_H
#define JUMPJUMP_INTROSTATE_H

#include "BaseState.h"

using namespace std;
using namespace sf;

class GameEngine;

class IntroState : public BaseState
{
private:
    bool IsStart;
    Texture introBackgroundTexture, arrowTexture;
    Sprite introBackgroundSprite, arrowSprite;
public:
    IntroState(bool replacing = true);
    ~IntroState();

    void Pause();
    void Resume();

    void HandleEvents(GameEngine& game);
    void Update(GameEngine& game);
    void Draw(GameEngine& game);
};
#endif //JUMPJUMP_INTROSTATE_H
