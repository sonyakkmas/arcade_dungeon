#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "raylib.h"

#include "globals.h"
#include "images.h"
#include "utilities.h"
#include "level_data.h"
#include "enemy_data.h"
#include "text.h"

#include <string>
#include <cmath>



void draw_player_score() {
    const float score_font_size  = GAME_SCORE_FONT_SIZE * screen_scale;
    const float score_top_margin = GAME_SCORE_Y_SHIFT   * screen_scale;

    std::string score_text = std::string("Score ");
    score_text += std::to_string(player_score);

    Vector2 score_size = MeasureTextEx(menu_font, score_text.c_str(), score_font_size, 1);
    Vector2 score_position = { (screen_width - score_size.x) * 0.2f, score_top_margin };
    DrawTextEx(menu_font, score_text.c_str(), score_position, score_font_size, 1, GAME_SCORE_COLOR1);
    score_position.x -= 4 * screen_scale;
    score_position.y -= 4 * screen_scale;
    DrawTextEx(menu_font, score_text.c_str(), score_position, score_font_size, 1, GAME_SCORE_COLOR2);
}
void draw_player_health(){
    const float health_font_size  = GAME_HEALTH_FONT_SIZE * screen_scale;
    const float health_top_margin = GAME_HEALTH_Y_SHIFT   * screen_scale;

    std::string health_text = std::string("Health ");
    health_text += std::to_string(player_health);

    Vector2 health_size = MeasureTextEx(menu_font, health_text.c_str(), health_font_size, 1);
    Vector2 health_position = { (screen_width - health_size.x) * 0.8f, health_top_margin };
    DrawTextEx(menu_font, health_text.c_str(), health_position, health_font_size, 1, GAME_HEALTH_COLOR1);
    health_position.x -= 4 * screen_scale;
    health_position.y -= 4 * screen_scale;
    DrawTextEx(menu_font, health_text.c_str(), health_position, health_font_size, 1, GAME_HEALTH_COLOR2);

}
void draw_stop_music(){
    const char *title = MUSIC_PAUSE_TITLE.c_str();
    const float title_font_size = MUSIC_PAUSE_FONT_SIZE * screen_scale;
    const float title_y_shift   = MUSIC_PAUSE_Y_SHIFT   * screen_scale;
    Vector2 title_size = MeasureTextEx(menu_font, title, title_font_size, 1);
    Vector2 title_position = {
            (screen_width - title_size.x) * 0.5f,
            screen_height * 0.9f - title_size.y * 0.1f + title_y_shift
    };
    DrawTextEx(menu_font, title, title_position, title_font_size, 1, MUSIC_PAUSE_COLOR);
}
void draw_instr_for_jump(){
    const char *title = JUMP_TITLE.c_str();
    const float title_font_size = JUMP_FONT_SIZE * screen_scale;
    const float title_y_shift   = JUMP_Y_SHIFT   * screen_scale;
    Vector2 title_size = MeasureTextEx(menu_font, title, title_font_size, 1);
    Vector2 title_position = {
            (screen_width - title_size.x) * 0.5f,
            screen_height * 0.9f - title_size.y * 0.1f + title_y_shift
    };
    DrawTextEx(menu_font, title, title_position, title_font_size, 1, JUMP_COLOR);
}

#endif // GRAPHICS_H