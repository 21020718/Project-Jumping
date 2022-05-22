#ifndef JUMPJUMP_PLAYSTATE_H
#define JUMPJUMP_PLAYSTATE_H

#include "sstream"
#include "fstream"
#include "BaseState.h"
#include "PaddleCreate.h"

class GameEngine;

class PlayState : public BaseState
{
private:
    Texture playBackgroundTexture, playerTexture, pauseTexture, gameoverTexture;
    Sprite playBackgroundSprite, playerSprite, pauseSprite, gameoverSprite;
    Font font;
    Text score, highestScore;
    bool FirstMove, IsPause, IsGameover;
    Clock time;
    float deltaTime;
    Vector2f velocity;
    PaddleCreate generator;
    float point;

    ifstream readFile;
    ofstream writeFile;

    void InputManager();
    void CollisionManager();
    void MoveManager();
    void CountScore();
    int HighestScore();
public:
    PlayState(bool replacing = true);
    ~PlayState();

    void Pause();
    void Resume();

    void HandleEvents(GameEngine& game);
    void Update(GameEngine& game);
    void Draw(GameEngine& game);
};
#endif //JUMPJUMP_PLAYSTATE_H
