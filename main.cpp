#include "include/GameEngine.h"
#include "include/IntroState.h"

using namespace sf;
using namespace std;

int main() {
    GameEngine game;
    game.Run(game.Build<IntroState>());

    while(game.IsRunning()){
        game.NextState();
        game.HandleEvents();
        game.Update();
        game.Draw();
    }

    return 0;
}