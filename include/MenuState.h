#ifndef JUMPJUMP_MENUSTATE_H
#define JUMPJUMP_MENUSTATE_H

#include "BaseState.h"

using namespace std;
using namespace sf;

class GameEngine;

class MenuState : public BaseState
{
public:
    MenuState(bool replacing = true);
    ~MenuState();

    void Pause();
    void Resume();

    void HandleEvents(GameEngine& game);
    void Update(GameEngine& game);
    void Draw(GameEngine& game);
};
#endif //JUMPJUMP_MENUSTATE_H
