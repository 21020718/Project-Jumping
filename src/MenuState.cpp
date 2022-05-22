#include "../include/MenuState.h"

MenuState::MenuState(bool replacing) : BaseState(replacing)
{
    cout<<"MenuState Init"<<endl;
}

MenuState::~MenuState()
{

}

void MenuState::Pause()
{

}

void MenuState::Resume()
{

}

void MenuState::HandleEvents(GameEngine &game)
{
    Event event;
    while (game.window.pollEvent(event)){
        switch(event.type){
            case Event::Closed:
                game.Quit();
                break;
            case Event::KeyPressed:
                switch (event.key.code) {
                    case Keyboard::Escape:
                        game.LastState();
                        break;
                }
                break;
        }
    }
}

void MenuState::Update(GameEngine &game)
{

}
void MenuState::Draw(GameEngine &game)
{

}