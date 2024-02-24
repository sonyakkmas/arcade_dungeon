#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <raylib.h>


/* Menu Text Parameters */

const std::string MENU_TITLE     = "Dungeon";
const float MENU_TITLE_FONT_SIZE = 200.0f;
const float MENU_TITLE_Y_SHIFT   = 10.0f;
const Color MENU_TITLE_COLOR     = RED;

const std::string MENU_SUBTITLE_START    = "Press Enter to start the game";
const float MENU_SUBTITLE_FONT_SIZE_START = 30.0f;
const float MENU_SUBTITLE_Y_SHIFT_START   = 80.0f;
const Color MENU_SUBTITLE_COLOR_START     = WHITE;

const std::string MENU_SUBTITLE_QUIT    = "Press Esc to quit the game";
const float MENU_SUBTITLE_FONT_SIZE_QUIT = 30.0f;
const float MENU_SUBTITLE_Y_SHIFT_QUIT   = 80.0f;
const Color MENU_SUBTITLE_COLOR_QUIT     = WHITE;

const std::string MENU_SUBTITLE_INST    = "Press  Space  to  open  instructions";
const float MENU_SUBTITLE_FONT_SIZE_INST = 30.0f;
const float MENU_SUBTITLE_Y_SHIFT_INST   = 80.0f;
const Color MENU_SUBTITLE_COLOR_INST     = WHITE;


/* Game Text Parameters */

const float GAME_SCORE_FONT_SIZE = 70.0f;
const float GAME_SCORE_Y_SHIFT   = 30.0f;
const Color GAME_SCORE_COLOR1    = GRAY;
const Color GAME_SCORE_COLOR2    = WHITE;

const float GAME_HEALTH_FONT_SIZE = 70.0f;
const float GAME_HEALTH_Y_SHIFT   = 30.0f;
const Color GAME_HEALTH_COLOR1    = GRAY;
const Color GAME_HEALTH_COLOR2    = WHITE;

const std::string MUSIC_PAUSE_TITLE     = "Press  M  to  pause  or  unpause  the  music";
const float MUSIC_PAUSE_FONT_SIZE = 20.0f;
const float MUSIC_PAUSE_Y_SHIFT   = 10.0f;
const Color MUSIC_PAUSE_COLOR    = GRAY;

const std::string JUMP_TITLE     = "Press  Shift  and  arrow  keys  to  jump";
const float JUMP_FONT_SIZE = 20.0f;
const float JUMP_Y_SHIFT   = 35.0f;
const Color JUMP_COLOR    = GRAY;

/* Pause Text Parameters */

const std::string PAUSE_TITLE     = "Press Esc to unpause the game";
const float PAUSE_TITLE_FONT_SIZE = 40.0f;
const float PAUSE_TITLE_Y_SHIFT   = 0.0f;
const Color PAUSE_TITLE_COLOR     = WHITE;

const std::string PAUSE_TITLE_QUIT     = "Press Space to quit the game";
const float PAUSE_TITLE_FONT_SIZE_QUIT = 30.0f;
const float PAUSE_TITLE_Y_SHIFT_QUIT   = 0.0f;
const Color PAUSE_TITLE_COLOR_QUIT     = WHITE;

/* Victory Menu Background */

const int numCircles = 250;
float circleX[numCircles];
float circleY[numCircles];
float circleSpeedX[numCircles];
float circleSpeedY[numCircles];
bool first_frame = true;

/* Victory Menu Text Parameters */

const std::string VICTORY_TITLE     = "You Won!";
const float VICTORY_TITLE_FONT_SIZE = 200.0f;
const float VICTORY_TITLE_Y_SHIFT   = 10.0f;
const Color VICTORY_TITLE_COLOR     = RED;

const std::string VICTORY_SUBTITLE     = "Press Enter to go back to menu";
const float VICTORY_SUBTITLE_FONT_SIZE = 40.0f;
const float VICTORY_SUBTITLE_Y_SHIFT   = 80.0f;
const Color VICTORY_SUBTITLE_COLOR     = WHITE;

const std::string GAMEP_SUBTITLE     = "Press  Space  to  try  Game  PLUS";
const float GAMEP_SUBTITLE_FONT_SIZE = 40.0f;
const float GAMEP_SUBTITLE_Y_SHIFT   = 80.0f;
const Color GAMEP_SUBTITLE_COLOR     = WHITE;

const float STATS_SUBTITLE_FONT_SIZE = 30.0f;
const float STATS_SUBTITLE_Y_SHIFT   = 80.0f;
const Color STATS_SUBTITLE_COLOR     = WHITE;

/* Defeat Menu Text Parameters */

const std::string DEFEAT_TITLE     = "Game Over";
const float DEFEAT_TITLE_FONT_SIZE = 200.0f;
const float DEFEAT_TITLE_Y_SHIFT   = 10.0f;
const Color DEFEAT_TITLE_COLOR     = RED;

const std::string DEFEAT_SUBTITLE     = "Press Enter to go back to menu";
const float DEFEAT_SUBTITLE_FONT_SIZE = 40.0f;
const float DEFEAT_SUBTITLE_Y_SHIFT   = 80.0f;
const Color DEFEAT_SUBTITLE_COLOR     = WHITE;

const float DEFEAT_REASON_SUB_FONT_SIZE = 40.0f;
const float DEFEAT_REASON_SUB_Y_SHIFT   = -10.0f;
const Color DEFEAT_REASON_SUB_COLOR     = RED;

const std::string LAST_SUBTITLE     = "Press  Space  to  try  last  level  again";
const float LAST_SUBTITLE_FONT_SIZE = 40.0f;
const float LAST_SUBTITLE_Y_SHIFT   = 80.0f;
const Color LAST_SUBTITLE_COLOR     = WHITE;

const std::string QUIT_SUBTITLE     = "Press Esc to quit the game";
const float QUIT_SUBTITLE_FONT_SIZE = 40.0f;
const float QUIT_SUBTITLE_Y_SHIFT   = 80.0f;
const Color QUIT_SUBTITLE_COLOR     = WHITE;

#endif //TEXT_H
