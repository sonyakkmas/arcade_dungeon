#include "raylib.h"

#include "globals.h"
#include "level_mechanics.h"
#include "images.h"
#include "text_graphics.h"
#include "player.h"
#include "level_data.h"
#include "menu_graphics.h"
#include "game_graphics.h"

bool pause = false;

void update_music(){
    UpdateMusicStream(soundtrack_music);
}
void update_game() {
    switch (game_state) {
        case MENU_STATE: {
            PauseMusicStream(soundtrack_music);
            if (IsKeyPressed(KEY_ENTER)) {
                game_state = GAME_STATE;
                level_index = -1;
                ng_plus = 1;
                player_score = 0;
                player_health = 100;
                usage_save_last = 2;
                load_levels();
                load_next_level();
                PlayMusicStream(soundtrack_music);
                begin_time = time(nullptr);
                run_time = 0;
                break;
            } else if (IsKeyPressed(KEY_ESCAPE)) {
                CloseWindow();
            }
        }
        case GAME_STATE: {
            if(IsKeyPressed(KEY_M)){
                if(pause){
                    ResumeMusicStream(soundtrack_music);
                    pause = false;
                }
                else{
                    PauseMusicStream(soundtrack_music);
                    pause = true;
                }
            }
            SetExitKey(0);
            int step = 1;
            bool is_shift_down = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
            if (is_shift_down) {
                step = 2;
            }
            if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
                move_player(0, -1 * step);
            } else if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
                move_player(0, 1 * step);
            } else if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
                move_player(-1 * step, 0);
            } else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
                move_player(1 * step, 0);
            }
            if (IsKeyPressed(KEY_ESCAPE)) {
                game_state = PAUSED_STATE;
                run_time += (int)difftime(time(nullptr), begin_time);
            }
            break;
        }
        case PAUSED_STATE: {
            PauseMusicStream(soundtrack_music);
            if (IsKeyPressed(KEY_ESCAPE)) {
                ResumeMusicStream(soundtrack_music);
                game_state = GAME_STATE;
                begin_time = time(nullptr);
            }
            else if(IsKeyPressed(KEY_SPACE)){
                CloseWindow();
            }
            break;
        }
        case VICTORY_STATE:
            PauseMusicStream(soundtrack_music);
            SetExitKey(KEY_ESCAPE);
            if (IsKeyPressed(KEY_ENTER)) {
                game_state = MENU_STATE;
                level_index = -1;
                player_health = 100;
                counter_monsters = 0;
            }
            else if(IsKeyPressed(KEY_SPACE) && ng_plus == 1){
                ng_plus++;
                level_index = -1;
                player_health = 150;
                usage_save_last = 4;
                save_health = 150;
                game_state = GAME_STATE;
                load_levels();
                load_next_level();
                ResumeMusicStream(soundtrack_music);
            }
            else if(IsKeyPressed(KEY_ESCAPE)){
                CloseWindow();
            }
            break;
        case DEFEAT_STATE: {
            PauseMusicStream(soundtrack_music);
            if (IsKeyPressed(KEY_ENTER)) {
                game_state = MENU_STATE;
                level_index = -1;
                player_health = 100;
                player_score = 0;
            }
            else if(IsKeyPressed(KEY_SPACE)){
                if(usage_save_last > 0){
                    player_health = save_health;
                    if (player_health <= 0){
                        player_health = 50;
                    }
                    if (player_score <=0){
                        player_score = 50;
                    }
                    usage_save_last--;
                    begin_time = time(nullptr);
                    game_state = GAME_STATE;
                    ResumeMusicStream(soundtrack_music);
                }
                else{
                    return;
                }
            }
            else if(IsKeyPressed(KEY_ESCAPE)){
                CloseWindow();
            }
            break;
        }
    }
}

void draw_game(){
    game_frame++;

    switch (game_state) {
        case MENU_STATE: {
            draw_menu();
            break;
        }
        case GAME_STATE: {
            draw_instr_for_jump();
            draw_stop_music();
            draw_level();
            draw_player();
            draw_player_score();
            draw_player_health();
            break;
        }
        case PAUSED_STATE: {
            draw_pause_menu();
            break;
        }
        case VICTORY_STATE: {
            draw_victory_menu();
            break;
        }
        case DEFEAT_STATE: {
            draw_defeat_menu();
            break;
        }
    }
}


int main() {
    SetConfigFlags(FLAG_VSYNC_HINT | FLAG_MSAA_4X_HINT);
    InitWindow(GetMonitorWidth(0), GetMonitorHeight(0), "Dungeon");
    screen_width = GetMonitorWidth(0);
    screen_height = GetMonitorHeight(0);

    InitAudioDevice();
    SetTargetFPS(60);
    ToggleFullscreen();
    HideCursor();

    load_fonts();
    load_images();
    load_sound();
    init_ng();

    derive_graphics_general_metrics();
    prepare_victory_background();

    while (!WindowShouldClose()) {
        update_music();

        BeginDrawing();
        update_game();
        draw_game();

        EndDrawing();
    }
    CloseWindow();
    CloseAudioDevice();
    unload_levels();
    unload_fonts();
    unload_images();
    unload_sound();
    return 0;
}
//TODO: BUGS - with levels from defeat, with coins thorugh defeat/win, with moving though shift key