#ifndef MENU_GRAPHICS_H
#define MENU_GRAPHICS_H

#include "text.h"
#include "globals.h"

/* Main Menu*/
void draw_menu_quit(){
    const char *subtitle_quit = MENU_SUBTITLE_QUIT.c_str();
    const float subtitle_font_size_quit = MENU_SUBTITLE_FONT_SIZE_QUIT * screen_scale;
    const float subtitle_y_shift_quit   = MENU_SUBTITLE_Y_SHIFT_QUIT   * screen_scale;
    Vector2 subtitle_size_quit = MeasureTextEx(menu_font, subtitle_quit, subtitle_font_size_quit, 1);
    Vector2 subtitle_position_quit = {
            (screen_width - subtitle_size_quit.x) * 0.5f,
            screen_height * 0.55f - subtitle_size_quit.y * 0.5f + subtitle_y_shift_quit
    };
    DrawTextEx(menu_font, subtitle_quit, subtitle_position_quit, subtitle_font_size_quit, 1, MENU_SUBTITLE_COLOR_START);
}

void draw_menu() {
    ClearBackground(BLACK);
    draw_menu_quit();
    const char *title = MENU_TITLE.c_str();
    const float title_font_size = MENU_TITLE_FONT_SIZE * screen_scale;
    const float title_y_shift   = MENU_TITLE_Y_SHIFT   * screen_scale;
    Vector2 title_size = MeasureTextEx(menu_font, title, title_font_size, 1);
    Vector2 title_position = {
            (screen_width - title_size.x) * 0.5f,
            screen_height * 0.5f - title_size.y * 0.5f - title_y_shift
    };
    DrawTextEx(menu_font, title, title_position, title_font_size, 1, MENU_TITLE_COLOR);

    const char *subtitle_start = MENU_SUBTITLE_START.c_str();
    const float subtitle_font_size_start = MENU_SUBTITLE_FONT_SIZE_START * screen_scale;
    const float subtitle_y_shift_start   = MENU_SUBTITLE_Y_SHIFT_START   * screen_scale;
    Vector2 subtitle_size_start = MeasureTextEx(menu_font, subtitle_start, subtitle_font_size_start, 1);
    Vector2 subtitle_position_start = {
            (screen_width - subtitle_size_start.x) * 0.5f,
            screen_height * 0.5f - subtitle_size_start.y * 0.5f + subtitle_y_shift_start
    };
    DrawTextEx(menu_font, subtitle_start, subtitle_position_start, subtitle_font_size_start, 1, MENU_SUBTITLE_COLOR_START);

}

/*Pause Menu*/

void draw_pause_menu(){
    ClearBackground(BLACK);

    const char *title = PAUSE_TITLE.c_str();
    const float title_font_size = PAUSE_TITLE_FONT_SIZE * screen_scale;
    const float title_y_shift   = PAUSE_TITLE_Y_SHIFT   * screen_scale;
    Vector2 title_size = MeasureTextEx(menu_font, title, title_font_size, 1);
    Vector2 title_position = {
            (screen_width - title_size.x) * 0.5f,
            screen_height * 0.5f - title_size.y * 0.5f + title_y_shift
    };
    DrawTextEx(menu_font, title, title_position, title_font_size, 1, PAUSE_TITLE_COLOR);

    const char *subtitle_quit = PAUSE_TITLE_QUIT.c_str();
    const float subtitle_font_size_quit = PAUSE_TITLE_FONT_SIZE_QUIT * screen_scale;
    const float subtitle_y_shift_quit   = PAUSE_TITLE_Y_SHIFT_QUIT   * screen_scale;
    Vector2 subtitle_size_quit = MeasureTextEx(menu_font, subtitle_quit, subtitle_font_size_quit, 1);
    Vector2 subtitle_position_quit = {
            (screen_width - subtitle_size_quit.x) * 0.5f,
            screen_height * 0.55f - subtitle_size_quit.y * 0.5f + subtitle_y_shift_quit
    };
    DrawTextEx(menu_font, subtitle_quit, subtitle_position_quit, subtitle_font_size_quit, 1, PAUSE_TITLE_COLOR_QUIT);

}

/*Victory Menu*/

void draw_victory_menu_background() {
    const char *title = VICTORY_TITLE.c_str();
    const float title_font_size = VICTORY_TITLE_FONT_SIZE * screen_scale;
    const float title_y_shift   =  VICTORY_TITLE_Y_SHIFT   * screen_scale;
    Vector2 title_size = MeasureTextEx(menu_font, title, title_font_size, 1);
    Vector2 title_position = {
            (screen_width - title_size.x) * 0.5f,
            screen_height * 0.5f - title_size.y * 0.5f + title_y_shift
    };
    DrawTextEx(menu_font, title, title_position, title_font_size, 1, VICTORY_TITLE_COLOR);
}


void prepare_victory_background(){
    for (int i = 0; i < numCircles; ++i) {
        circleX[i] = GetRandomValue(0, screen_width);
        circleY[i] = GetRandomValue(0, screen_height);
        circleSpeedX[i] = GetRandomValue(-200, 200);
        circleSpeedY[i] = GetRandomValue(-200, 200);
    }
}

void animate_victory_menu_background(){
    for (int i = 0; i < numCircles; ++i) {
        circleX[i] += circleSpeedX[i] * GetFrameTime();
        circleY[i] += circleSpeedY[i] * GetFrameTime();

        if (circleX[i] <= 0 || circleX[i] >= screen_width) {
            circleSpeedX[i] *= -1;
        }

        if (circleY[i] <= 0 || circleY[i] >= screen_height) {
            circleSpeedY[i] *= -1;
        }
    }

    for (int i = 0; i < numCircles; ++i) {
        DrawCircle(circleX[i], circleY[i], 3, WHITE);
    }
}
void draw_stats() {
    const float stats_font_size = STATS_SUBTITLE_FONT_SIZE * screen_scale;
    const float stats_top_margin = STATS_SUBTITLE_Y_SHIFT * screen_scale;

    std::string monster_killed_text = std::string("MONSTERS KILLED  ");
    monster_killed_text += std::to_string(counter_monsters);

    Vector2 monster_killed_size = MeasureTextEx(menu_font, monster_killed_text.c_str(), stats_font_size, 1);
    Vector2 monster_killed_position = {(screen_width - monster_killed_size.x) * 0.5f, (stats_top_margin) * 6.5f};
    DrawTextEx(menu_font, monster_killed_text.c_str(), monster_killed_position, stats_font_size, 1, STATS_SUBTITLE_COLOR);

    std::string score_text = std::string("SCORE  ");
    score_text += std::to_string(player_score);

    Vector2 score_size = MeasureTextEx(menu_font, score_text.c_str(), stats_font_size, 1);
    Vector2 score_position = { (screen_width - score_size.x) * 0.5f, (stats_top_margin)*6.9f };
    DrawTextEx(menu_font, score_text.c_str(), score_position, stats_font_size, 1, STATS_SUBTITLE_COLOR);

    std::string time_text = std::string("TIME ");
    time_text += std::to_string(abs(run_time/60)) + "m " + std::to_string(abs(run_time%60))+"s";

    Vector2 time_size = MeasureTextEx(menu_font, time_text.c_str(), stats_font_size, 1);
    Vector2 time_position = { (screen_width - time_size.x) * 0.5f, (stats_top_margin)*6.1f };
    DrawTextEx(menu_font, time_text.c_str(), time_position, stats_font_size, 1, STATS_SUBTITLE_COLOR);
}
void draw_victory_menu(){
    if (first_frame) {
        ClearBackground(BLACK);
        first_frame = false;
    } else {
        DrawRectangle(
                0, 0,
                static_cast<int>(screen_width), static_cast<int>(screen_height),
                { 0, 0, 0, 33 }
        );
    }
    animate_victory_menu_background();
    draw_victory_menu_background();
    draw_stats();
    const char *subtitle = VICTORY_SUBTITLE.c_str();
    const float subtitle_font_size = VICTORY_SUBTITLE_FONT_SIZE * screen_scale;
    const float subtitle_y_shift   = VICTORY_SUBTITLE_Y_SHIFT   * screen_scale;
    Vector2 subtitle_size = MeasureTextEx(menu_font, subtitle, subtitle_font_size, 1);
    Vector2 subtitle_position = {
            (screen_width - subtitle_size.x) * 0.5f,
            screen_height * 0.5f - subtitle_size.y * 0.5f + subtitle_y_shift
    };
    DrawTextEx(menu_font, subtitle, subtitle_position, subtitle_font_size, 1, VICTORY_SUBTITLE_COLOR);

    if (ng_plus == 1){
        const char *subtitle_game = GAMEP_SUBTITLE.c_str();
        const float subtitle_font_size_game = GAMEP_SUBTITLE_FONT_SIZE * screen_scale;
        const float subtitle_y_shift_game   = GAMEP_SUBTITLE_Y_SHIFT   * screen_scale;
        Vector2 subtitle_size_game = MeasureTextEx(menu_font, subtitle, subtitle_font_size, 1);
        Vector2 subtitle_position_game = {
                (screen_width - subtitle_size_game.x) * 0.5f,
                screen_height * 0.55f - subtitle_size_game.y * 0.5f + subtitle_y_shift_game
        };
        DrawTextEx(menu_font, subtitle_game, subtitle_position_game, subtitle_font_size_game, 1, GAMEP_SUBTITLE_COLOR);
    }
}

/*Defeat Menu*/

void draw_defeat_menu_background(){
    ClearBackground(BLACK);
    const char *title = DEFEAT_TITLE.c_str();
    const float title_font_size = DEFEAT_TITLE_FONT_SIZE* screen_scale;
    const float title_y_shift   =  DEFEAT_TITLE_Y_SHIFT   * screen_scale;
    Vector2 title_size = MeasureTextEx(menu_font, title, title_font_size, 1);
    Vector2 title_position = {
            (screen_width - title_size.x) * 0.5f,
            screen_height * 0.5f - title_size.y * 0.5f + title_y_shift
    };
    DrawTextEx(menu_font, title, title_position, title_font_size, 1, DEFEAT_TITLE_COLOR);
}
void draw_reason_for_defeat(){
    const char *title = reason_for_defeat.c_str();
    const float title_font_size = DEFEAT_REASON_SUB_FONT_SIZE* screen_scale;
    const float title_y_shift   =  DEFEAT_REASON_SUB_Y_SHIFT   * screen_scale;
    Vector2 title_size = MeasureTextEx(menu_font, title, title_font_size, 1);
    Vector2 title_position = {
            (screen_width - title_size.x) * 0.5f,
            screen_height * 0.65f - title_size.y * 0.5f + title_y_shift
    };
    DrawTextEx(menu_font, title, title_position, title_font_size, 1, DEFEAT_REASON_SUB_COLOR);
}
void draw_last_level_again(){
    const char *subtitle_last = LAST_SUBTITLE.c_str();
    const float subtitle_font_size_last = LAST_SUBTITLE_FONT_SIZE * screen_scale;
    const float subtitle_y_shift_last   = LAST_SUBTITLE_Y_SHIFT   * screen_scale;
    Vector2 subtitle_size_last = MeasureTextEx(menu_font, subtitle_last, subtitle_font_size_last, 1);
    Vector2 subtitle_position_last = {
            (screen_width - subtitle_size_last.x) * 0.55f,
            screen_height * 0.6f - subtitle_size_last.y * 0.1f + subtitle_y_shift_last
    };
    DrawTextEx(menu_font, subtitle_last, subtitle_position_last, subtitle_font_size_last, 1, LAST_SUBTITLE_COLOR);
}
void draw_quit_defeat(){
    const char *subtitle_quit = QUIT_SUBTITLE.c_str();
    const float subtitle_font_size_quit = QUIT_SUBTITLE_FONT_SIZE * screen_scale;
    const float subtitle_y_shift_quit   = QUIT_SUBTITLE_Y_SHIFT   * screen_scale;
    Vector2 subtitle_size_quit = MeasureTextEx(menu_font, subtitle_quit, subtitle_font_size_quit, 1);
    Vector2 subtitle_position_quit = {
            (screen_width - subtitle_size_quit.x) * 0.5f,
            screen_height * 0.65f - subtitle_size_quit.y * 0.1f + subtitle_y_shift_quit
    };
    DrawTextEx(menu_font, subtitle_quit, subtitle_position_quit, subtitle_font_size_quit, 1, QUIT_SUBTITLE_COLOR);
}
void draw_defeat_menu(){
    DrawRectangle(
            0, 0,
            static_cast<int>(screen_width), static_cast<int>(screen_height),
            { 0, 0, 0, 0 }
    );

    draw_defeat_menu_background();
    draw_reason_for_defeat();
    if( usage_save_last > 0){
        draw_last_level_again();
    }
    draw_quit_defeat();

    const char *subtitle = DEFEAT_SUBTITLE.c_str();
    const float subtitle_font_size = DEFEAT_SUBTITLE_FONT_SIZE * screen_scale;
    const float subtitle_y_shift   = DEFEAT_SUBTITLE_Y_SHIFT   * screen_scale;
    Vector2 subtitle_size = MeasureTextEx(menu_font, subtitle, subtitle_font_size, 1);
    Vector2 subtitle_position = {
            (screen_width - subtitle_size.x) * 0.5f,
            screen_height * 0.55f - subtitle_size.y * 0.1f + subtitle_y_shift
    };
    DrawTextEx(menu_font, subtitle, subtitle_position, subtitle_font_size, 1, DEFEAT_SUBTITLE_COLOR);

}

#endif // MENU_GRAPHICS_H
