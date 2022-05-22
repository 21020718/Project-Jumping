#ifndef JUMPJUMP_BASESTATE_H
#define JUMPJUMP_BASESTATE_H

#include <SFML/Graphics.hpp>
#include "GameEngine.h"
#include <memory>
#include <string>

using namespace std;
using namespace sf;

class BaseState
{
protected:
    bool replacing;
    unique_ptr<BaseState> next;
public:
    BaseState(bool replacing = true) : replacing(replacing){}
    ~BaseState(){}
    bool IsReplacing()
    {
        return replacing;
    }

    virtual void Pause() = 0;
    virtual void Resume() = 0;

    virtual void HandleEvents(GameEngine& game) = 0;
    virtual void Update(GameEngine& game) = 0;
    virtual void Draw(GameEngine& game) = 0;

    unique_ptr<BaseState> Next()
    {
        return move(next);
    }
};

#endif //JUMPJUMP_BASESTATE_H
