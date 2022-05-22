#include "../include/PlayState.h"
PlayState::PlayState(bool replacing) :
    BaseState(replacing),
    FirstMove(false),
    IsPause(false),
    IsGameover(false),
    velocity(0,0),
    point(0)
{
    playBackgroundTexture.loadFromFile(PLAY_BACKGROUND_FILEPATH);
    playBackgroundSprite.setTexture(playBackgroundTexture);

    playerTexture.loadFromFile(PLAYER_FILEPATH);
    playerSprite.setTexture(playerTexture);
    playerSprite.setPosition(200,150);

    pauseTexture.loadFromFile(PAUSE_FILEPATH);
    pauseSprite.setTexture(pauseTexture);
    gameoverTexture.loadFromFile(GAMEOVER_FILEPATH);
    gameoverSprite.setTexture(gameoverTexture);

    font.loadFromFile(FONT_FILEPATH);
    score.setFont(font);
    score.setCharacterSize(20);
    score.setFillColor(Color::Red);
    score.setPosition(10,10);

    highestScore.setFont(font);
    highestScore.setCharacterSize(70);
    highestScore.setFillColor(Color::Red);
    highestScore.setPosition(180,410);

    cout<<"PlayState Init"<<endl;
}

PlayState::~PlayState() {
    cout<<"PlayState Cleanup"<<endl;
}

void PlayState::Pause()
{
    cout<<"PlayState Pause"<<endl;
}

void PlayState::Resume()
{
    cout<<"PlayState Resume"<<endl;
}

void PlayState::HandleEvents(GameEngine &game)
{
    Event event;
    while(game.window.pollEvent(event)){
        switch(event.type){
            case Event::Closed:
                game.Quit();
                break;
            case Event::LostFocus:
                IsPause = true;
                break;
            case Event::GainedFocus:
                IsPause = false;
                break;
            case Event::MouseButtonReleased: case Event::KeyReleased: //restart
                if(IsGameover)
                    next = game.Build<PlayState>();
        }
    }
}

void PlayState::Update(GameEngine &game)
{
    deltaTime = time.restart().asSeconds();
    if(playerSprite.getPosition().y + PLAYER_H > WINDOW_H) {
        if (FirstMove)
            IsGameover = true;
        else //prevent die from start
            velocity.y = 450;
    }

    if(IsGameover)
    {
        score.setCharacterSize(50);
        score.setFillColor(Color::Black);
        score.setPosition(310,575);
        ostringstream out;
        out << static_cast< int >(point);
        score.setString(out.str());
        ostringstream _out;
        _out << HighestScore();
        highestScore.setString(_out.str());
        return;
    }

    if(IsPause)
        return;

    InputManager();
    CollisionManager();
    MoveManager();
    generator.Update(deltaTime);
    CountScore();

    velocity.y -= 280*deltaTime;
}

void PlayState::Draw(GameEngine &game)
{
    game.window.clear();
    game.window.draw(playBackgroundSprite);
    if(IsGameover) {
        game.window.draw(gameoverSprite);
        game.window.draw(score);
        game.window.draw(highestScore);
        //ostringstream out;
        //out << static_cast< int >(point);
        //score.setString(out.str());


    }
    else{
        generator.Draw(game.window);
        game.window.draw(playerSprite);
        if(IsPause)
            game.window.draw(pauseSprite);
    }
    game.window.draw(score);
    game.window.display();
}

void PlayState::InputManager()
{
    // Stop horizontal movement
    if(!sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) && !sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) && velocity.x < 20 && velocity.x > -20 )
        velocity.x = 0;
        // Deaccelerate
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && velocity.x < 0)
        velocity.x += 350 * deltaTime;
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && velocity.x > 0)
        velocity.x -= 350 * deltaTime;
        // Accelerate
    else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity.x = 250;
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity.x = -250;
        //both keys press
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        velocity.x = 0;
}
void PlayState::CollisionManager()
{
    if( velocity.y < 0 ) //falling
    {
        float newVelocity = generator.Collision( playerSprite );
        if( newVelocity != 0 ) {
            velocity.y = newVelocity;
            generator.jumpSound.play();
        }
    }
}

void PlayState::MoveManager()
{
    Vector2f position = playerSprite.getPosition();

    if(playerSprite.getPosition().y <= WINDOW_H/5)
    {
        FirstMove = true;
        if(velocity.y<0)
            playerSprite.setPosition(position.x + velocity.x*deltaTime, position.y + 50*deltaTime);
        else
            playerSprite.setPosition(position.x + velocity.x*deltaTime, position.y);

        generator.Move(velocity.y*deltaTime);
    }
    else
        playerSprite.setPosition(position.x + velocity.x*deltaTime, position.y - velocity.y*deltaTime);

    if(playerSprite.getPosition().x + PLAYER_W < 0)
        playerSprite.setPosition(WINDOW_W - PLAYER_W, playerSprite.getPosition().y);
    if(playerSprite.getPosition().x > WINDOW_W)
        playerSprite.setPosition(0, playerSprite.getPosition().y);
}

void PlayState::CountScore()
{
    point += (velocity.y * deltaTime) / 10.f;
    if(point < 0)
        point = 0;

    ostringstream out;
    out << static_cast< int >(point);
    score.setString(out.str());
}

int PlayState::HighestScore()
{
    int _highestScore = 0;
    readFile.open(HIGHEST_SCORE_FILEPATH);
    if(readFile.is_open())
        while(!readFile.eof())
            readFile >> _highestScore;
    readFile.close();

    writeFile.open(HIGHEST_SCORE_FILEPATH);
    if(writeFile.is_open()) {
        if (point > _highestScore)
            _highestScore = static_cast<int>(point);
        writeFile << _highestScore;
    }
    writeFile.close();
    return _highestScore;
}