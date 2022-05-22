#include "../include/IntroState.h"
#include "../include/PlayState.h"

IntroState::IntroState(bool replacing) :
    BaseState(replacing),
    IsStart(false)
{
    introBackgroundTexture.loadFromFile(INTRO_BACKGROUND_FILEPATH);
    introBackgroundSprite.setTexture(introBackgroundTexture,true);

    arrowTexture.loadFromFile(ARROW_FILEPATH);
    arrowSprite.setTexture(arrowTexture);
    arrowSprite.setPosition(0,390);

    cout<<"IntroState Init"<<endl;
}

IntroState::~IntroState() {

}

void IntroState::Pause()
{

}

void IntroState::Resume()
{

}

void IntroState::HandleEvents(GameEngine &game)
{
    Event event;
    while(game.window.pollEvent(event)){
        switch(event.type){
            case Event::Closed:
                game.Quit();
                break;
            case Event::MouseButtonReleased:
                if(IsStart)
                    next = game.Build<PlayState>();
                break;
        }
    }
}

void IntroState::Update(GameEngine &game)
{
    if(playingButtonRect.contains(Mouse::getPosition(game.window)))
        IsStart = true;
    else
        IsStart = false;
}

void IntroState::Draw(GameEngine &game)
{
    game.window.clear();
    game.window.draw(introBackgroundSprite);
    if(IsStart)
        game.window.draw(arrowSprite);
    game.window.display();
}