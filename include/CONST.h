#ifndef JUMPJUMP_CONST_H
#define JUMPJUMP_CONST_H

#include <string>

using namespace std;
using namespace sf;

const int WINDOW_W = 500, WINDOW_H = 700;
const int PLAYER_W = 80, PLAYER_H = 83;
const int PADDLE_W = 68, PADDLE_H = 14, PADDLE_FAST_H = 55;
const string WINDOW_TITLE = "Jump Jump";
const int MAX_FPS = 60;

const string INTRO_BACKGROUND_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\images\\introBackground.png";
const string ARROW_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\images\\arrow.png";
const string PLAY_BACKGROUND_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\images\\playBackground.png";
const string ICON_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\images\\UET_logo.png";
const string PLAYER_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\images\\normal.png";
const string PADDLE_NORMAL_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\images\\paddleNormal.png";
const string PADDLE_FAST_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\images\\paddleFast.png";
const string PADDLE_SLOW_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\images\\paddleSlow.png";
const string PAUSE_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\images\\pause.png";
const string GAMEOVER_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\images\\gameOver.png";
const string HIGHEST_SCORE_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\txt\\HighestScore.txt";

const string FONT_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\fonts\\FreeSans.ttf";

const string SOUND_JUMP_FILEPATH = "D:\\CLionProjects\\JumpJump\\res\\musics\\_jump.wav";

const IntRect playingButtonRect = IntRect (180,400,140,45);

const float MAX_MOVE_DISTANCE = 80;


#endif //JUMPJUMP_CONST_H
