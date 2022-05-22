#include "../include/PaddleCreate.h"

PaddleCreate::PaddleCreate() : totalMove(0)
{
    srand(static_cast<float>(time(0)));
    paddleNormalTexture.loadFromFile(PADDLE_NORMAL_FILEPATH);
    paddleFastTexture.loadFromFile(PADDLE_FAST_FILEPATH);
    paddleSlowTexture.loadFromFile(PADDLE_SLOW_FILEPATH);

    jumpSoundBuffer.loadFromFile(SOUND_JUMP_FILEPATH);
    jumpSound.setBuffer(jumpSoundBuffer);
    createInit();
}

int PaddleCreate::random(int min, int max)
{
    return (rand()%(max-min+1) + min);
}

void PaddleCreate::create(Vector2f pos)
{
    Paddle paddle;
    paddle.sprite.setPosition(pos);
    int tmp = random(1,12);
    //nothing
    if(tmp>=1 && tmp<=2) {}
    //normal
    else if(tmp>=3 && tmp<=5){
        paddle.sprite.setTexture(paddleNormalTexture);
        paddle.type = 1;
    }
    //breaked, slow
    else if(tmp>=6 && tmp<=8){
        paddle.sprite.setTexture(paddleSlowTexture);
        paddle.type = 2;
    }
    //fast
    else if(tmp>=9 && tmp<=10){
        paddle.sprite.setTexture(paddleFastTexture);
        paddle.type = 3;
    }
    //move
    else if(tmp>=11 && tmp<=12){
        paddle.sprite.setTexture(paddleNormalTexture);
        paddle.type = 4;
    }
    paddles.push_back(paddle);
}

void PaddleCreate::createInit()
{
    Vector2f position;
    for(int y=0; y<5; y++){
        for(int x=0; x<2; x++){
            position.x= static_cast<float>( random(x*250, x*250+180) ) ;
            position.y= static_cast<float>( WINDOW_H - random(y*140, y*140+120) );
            create(position);
        }
    }
}

void PaddleCreate::createNext()
{
    Vector2f position;
    totalMove=0;
    for(int x=0; x<2; x++){
        position.x= static_cast<float>( random(x*250, x*250+180) ) ;
        position.y= static_cast<float>( - random(0, 110) );
        create(position);
    }
}

void PaddleCreate::Update(float deltaTime)
{
    for(auto it = paddles.begin(); it != paddles.end(); it++){
        it->Update(deltaTime);
    }
}

void PaddleCreate::Move(float distance)
{
    for(auto it = paddles.begin(); it != paddles.end(); it++){
        it->sprite.setPosition(it->sprite.getPosition().x,it->sprite.getPosition().y+distance);
        if(it->sprite.getPosition().y + PADDLE_H > WINDOW_H)
            it = paddles.erase(it);
    }
    totalMove += distance;

    if(totalMove > 150)
        createNext();
}

float PaddleCreate::Collision(const Sprite player)
{
    FloatRect playerRect(player.getPosition().x+20, player.getPosition().y + PLAYER_H -10,PLAYER_W-20,10);
    for(auto it = paddles.begin(); it != paddles.end(); it++){
        FloatRect paddleRect;
        if (it->type == 3)
            paddleRect = FloatRect(it->sprite.getPosition().x,
                                   it->sprite.getPosition().y + PADDLE_FAST_H - PADDLE_H, PADDLE_W, 1);
        else
            paddleRect = FloatRect(it->sprite.getPosition().x, it->sprite.getPosition().y, PADDLE_W, 1);

        if (playerRect.intersects(paddleRect)) {
            if (it->type == 1 || it->type == 4)//normal || move
                return 450;
            else if (it->type == 2) { //slow
                it = paddles.erase(it);
                return 380;
            }
            else if (it->type == 3) //fast
                return 800;
        }
    }
    return 0;
}

void PaddleCreate::Draw(RenderTarget &target)
{
    for(auto it = paddles.begin(); it != paddles.end(); it++){
        target.draw(it->sprite);
    }
}

