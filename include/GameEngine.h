#ifndef JUMPJUMP_GAMEENGINE_H
#define JUMPJUMP_GAMEENGINE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <stack>
#include "CONST.h"

using namespace std;
using namespace sf;

class BaseState;

class GameEngine
{
private:
    Image icon;
    bool running;
    stack<unique_ptr<BaseState>> states;
public:
    RenderWindow window;

    GameEngine();

    void Run(unique_ptr<BaseState> state);

    void NextState();
    void LastState();

    void HandleEvents();
    void Update();
    void Draw();

    bool IsRunning()
    {
        return running;
    }
    void Quit()
    {
        running = false;
    }

    template<typename T>
    unique_ptr<T> Build (bool replacing = true);
};

template<typename T>
unique_ptr<T> GameEngine::Build (bool replacing)
{
    return move(unique_ptr<T> (new T (replacing)) );
}
#endif //JUMPJUMP_GAMEENGINE_H
