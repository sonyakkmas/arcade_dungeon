#ifndef GAME_GRAPHICS_H
#define GAME_GRAPHICS_H

#include "globals.h"
#include "level_data.h"
void derive_graphics_general_metrics() {
    screen_width  = static_cast<float>(GetScreenWidth());
    screen_height = static_cast<float>(GetScreenHeight());
    screen_scale = std::min(screen_width, screen_height) / SCREEN_SCALE_DIVISOR;
}

void derive_graphics_metrics_from_loaded_level() {
    cell_size = std::min(
            screen_width  / static_cast<float>(lvl.columns),
            screen_height / static_cast<float>(lvl.rows)
    ) * CELL_SCALE;
    float level_width  = static_cast<float>(lvl.columns) * cell_size;
    float level_height = static_cast<float>(lvl.rows)    * cell_size;
    shift_to_center_cell_by_x = (screen_width - level_width)   * 0.5f;
    shift_to_center_cell_by_y = (screen_height - level_height) * 0.5f;
}
void draw_level(){
    ClearBackground(BLACK);
    for(size_t row = 0; row < lvl.rows; ++row){
        for(size_t column = 0; column < lvl.columns; ++column){
            float x = shift_to_center_cell_by_x + static_cast<float>(column) * cell_size;
            float y = shift_to_center_cell_by_y + static_cast<float>(row) * cell_size;
            char cell = lvl.data[row*lvl.columns + column];
            switch (cell) {
                case FLOOR:
                    draw_image(floor_image, x, y, cell_size);
                    break;
                case WALL:
                    draw_image(wall_image, x, y, cell_size);
                    break;
                case ENTRANCE:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(entrance_image, x, y, cell_size);
                    break;
                case EXIT:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(exit_image, x, y, cell_size);
                    break;
                case APPLE:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(apple_image, x, y, cell_size);
                    break;
                case COIN:
                    draw_image(floor_image, x, y, cell_size);
                    draw_sprite(coin_sprite, x, y, cell_size);
                    break;
                case GOBLIN_GREAT:
                    draw_image(floor_image, x, y, cell_size);
                    draw_sprite(goblin_great_sprite, x, y, cell_size);
                    break;
                case SPIKE:
                    draw_image(floor_image, x, y, cell_size);
                    draw_sprite(spike_sprite, x, y, cell_size);
                    break;
                case GNOME:
                    draw_image(floor_image, x, y, cell_size);
                    draw_sprite(gnome_sprite, x, y, cell_size);
                    break;
                case DIAMOND:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(diamond_image, x, y, cell_size);
                    break;
                case POTION:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(potion_image, x, y, cell_size);
                    break;
                case POTION_SMALL:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(potion_small_image, x, y, cell_size);
                    break;
                case GOLD_KEY:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(gold_key_image, x, y, cell_size);
                    break;
                case SILVER_KEY:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(silver_key_image, x, y, cell_size);
                    break;
                case GOBLIN:
                    draw_image(floor_image, x, y, cell_size);
                    draw_sprite(goblin_sprite, x, y, cell_size);
                    break;
                case SILVER_DOOR:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(silver_door_image, x, y, cell_size);
                    break;
                case GOLD_DOOR:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(gold_door_image, x, y, cell_size);
                    break;
                case SPIDER:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(spider_image, x, y, cell_size);
                    break;
                case BOMB:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(bomb_image, x, y, cell_size);
                    break;
                case TROLL:
                    draw_image(floor_image, x, y, cell_size);
                    draw_sprite(troll_sprite, x, y, cell_size);
                    break;
                case FIRE:
                    draw_image(floor_image, x, y, cell_size);
                    draw_sprite(fire_sprite, x, y, cell_size);
                    break;
                case SNAKE:
                    draw_image(floor_image, x, y, cell_size);
                    draw_image(snake_image, x, y, cell_size);
                    break;
                default:
                    break;
            }
        }
    }
}
void draw_player(){
    float x = shift_to_center_cell_by_x + static_cast<float>(player_column) * cell_size;
    float y = shift_to_center_cell_by_y + static_cast<float>(player_row) * cell_size;
    draw_sprite(player_sprite, x, y, cell_size);
}
#endif //GAME_GRAPHICS_H
