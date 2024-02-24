#ifndef GLOBALS_H
#define GLOBALS_H

#include "raylib.h"

#include <string>
#include <cstddef>
#include <vector>
#include <time.h>

/* Player Data */

int counter_monsters = 0;
time_t begin_time;
int run_time = 0;

int gold_quantity = 0;
int silver_quantity = 0;

const int POINTS_FOR_COIN = 10;
const int POINTS_FOR_DIAMOND = 20;

const int POINTS_FOR_APPLE = 10;
const int POINTS_FOR_POTION = 70;
const int POINTS_FOR_SMALL_POTION = 30;

const int POINTS_FOR_BOMB = 10;
const int POINTS_FOR_FIRE = 10;

size_t player_row;
size_t player_column;

int ng_plus = 1;

int player_score = 0;
int player_health = 100;
int save_health = 100;

std::string reason_for_defeat;

/* Graphics Metrics */

const float CELL_SCALE = 0.6f; // An aesthetic parameter to add some negative space around level
const float SCREEN_SCALE_DIVISOR = 700.0f; // The divisor was found through experimentation
// to scale things accordingly to look pleasant.

int screen_width = 1024;
int screen_height = 500;
float screen_scale; // Used to scale text/UI components size and displacements based on the screen size
float cell_size;
float shift_to_center_cell_by_x;
float shift_to_center_cell_by_y;

/* Fonts */

Font menu_font;
Font instruction_font;

/* Images and Sprites */

Texture2D wall_image;
Texture2D floor_image;
Texture2D entrance_image;
Texture2D exit_image;
Texture2D apple_image;
Texture2D diamond_image;
Texture2D potion_image;
Texture2D potion_small_image;
Texture2D gold_key_image;
Texture2D silver_key_image;
Texture2D gold_door_image;
Texture2D silver_door_image;
Texture2D spider_image;
Texture2D bomb_image;
Texture2D snake_image;

struct sprite {
    size_t frame_count    = 0;
    size_t frames_to_skip = 3;
    size_t frames_skipped = 0;
    size_t frame_index    = 0;
    bool loop = true;
    size_t prev_game_frame = 0;
    Texture2D *frames = nullptr;
};

sprite coin_sprite;
sprite player_sprite;
sprite goblin_great_sprite;
sprite spike_sprite;
sprite gnome_sprite;
sprite goblin_sprite;
sprite troll_sprite;
sprite fire_sprite;

/* Sounds */

Sound coin_sound;
Sound exit_sound;
Sound apple_sound;
Sound hurt_sound;
Sound gnome_laugh_sound;
Sound defeat_sound;
Sound diamond_sound;
Sound win_enemy_sound;
Sound potion_sound;
Sound jump_sound;
Sound keys_sound;
Sound win_sound;
Sound door_sound;
Sound bomb_sound;
Sound fire_sound;
Sound troll_sound;
Sound spider_sound;

Music soundtrack_music;

// TODO: try next level again?

/* Frame Counter */

size_t game_frame = 0;

/* Game State */

enum game_state {
    MENU_STATE,
    GAME_STATE,
    PAUSED_STATE,
    VICTORY_STATE,
    DEFEAT_STATE,
};

game_state game_state = MENU_STATE;

/* Forward Declarations */


// MENU_GRAPHICS.H
void draw_menu_quit();
void draw_menu();
void draw_pause_menu();
void draw_victory_menu_background();
void prepare_victory_background();
void animate_victory_menu_background();
void draw_stats();
void draw_victory_menu();
void draw_defeat_menu_background();
void draw_reason_for_defeat();
void draw_last_level_again();
void draw_quit_defeat();
void draw_defeat_menu();
void draw_choices();

// TEXT_GRAPHICS.H
void draw_player_score();
void draw_player_health();
void draw_stop_music();
void draw_instr_for_jump();

//GAME_GRAPHICS.H
void derive_graphics_general_metrics();
void derive_graphics_metrics_from_loaded_level();
void draw_level();
void draw_player();

// IMAGES_H
void load_fonts();
void unload_fonts();
void load_images();
void unload_images();
void draw_image(Texture2D image, float x, float y, float width, float height);
void draw_image(Texture2D image, float x, float y, float size);
sprite load_sprite(
        const std::string &file_name_prefix,
        const std::string &file_name_suffix,
        size_t frame_count = 1,
        bool loop = true,
        size_t frames_to_skip = 3
);
void unload_sprite(sprite &sprite);
void draw_sprite(sprite &sprite, float x, float y, float width, float height);
void draw_sprite(sprite &sprite, float x, float y, float size);
void load_sound();
void unload_sound();

// LEVEL_MECHANICS.H

void load_enemies();
void load_next_level();
void unload_levels();
void load_levels();
void load_prev_level();

// PLAYER.H

int collision_check_dx(int dx, int dy);
int collision_check_dy(int dx, int dy);
void play_enemy_sound();
void fight(int dx, int dy);
void move_player(int dx, int dy);



//UTILITIES.H
float rand_from_to(float from, float to);

// TODO: Add forward declarations of all your functions to avoid circular dependencies.

#endif // GLOBALS_H