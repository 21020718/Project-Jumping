#include "../include/GameEngine.h"
#include "../include/BaseState.h"

GameEngine::GameEngine() : running(false)
{
    window.create(VideoMode(WINDOW_W, WINDOW_H), WINDOW_TITLE);
    window.setFramerateLimit(MAX_FPS);

    icon.loadFromFile(ICON_FILEPATH);
    window.setIcon(icon.getSize().x,icon.getSize().y,icon.getPixelsPtr());

    cout<<"GameEngine Init"<<endl;
}

void GameEngine::Run(unique_ptr<BaseState> state)
{
    running = true;
    states.push(move(state));
    cout<<"GameEngine Run"<<endl;
}

void GameEngine::NextState()
{
    if( !states.empty()){
        unique_ptr<BaseState> nextState = states.top()->Next();
        if( nextState != NULL){
            if(nextState->IsReplacing())
                states.pop();
            else
                states.top()->Pause();
            states.push(move(nextState));
        }
    }
}

void GameEngine::LastState()
{
    if(!states.empty())
        states.pop();
    if(!states.empty())
        states.top()->Resume();
}

void GameEngine::HandleEvents()
{
    states.top()->HandleEvents(*this);
}

void GameEngine::Update()
{
    states.top()->Update(*this);

}

void GameEngine::Draw()
{
    states.top()->Draw(*this);

}