#ifndef LEVEL_MECHANICS_H
#define LEVEL_MECHANICS_H

#include <iostream>
#include <cstring>
#include "globals.h"
#include "text_graphics.h"
#include "menu_graphics.h"
#include "game_graphics.h"
#include "level_data.h"

void load_enemies(){
    lvl.enemies.clear();
    for(int i = 0; i < lvl.columns*lvl.rows; i++){
        int row = i/lvl.columns;
        int column = i %lvl.columns;
        switch (lvl.data[i]) {
            case GOBLIN:
                lvl.enemies.push_back(CreateGoblin(row, column));
                break;
            case GNOME:
                lvl.enemies.push_back(CreateGnome(row, column));
                break;
            case GOBLIN_GREAT:
                lvl.enemies.push_back(CreateGreatGoblin(row, column));
                break;
            case TROLL:
                lvl.enemies.push_back(CreateTroll(row, column));
                break;
            case SPIDER:
                lvl.enemies.push_back(CreateSpider(row, column));
                break;
            default:
                break;
        }
    }
}
void load_next_level(){
    int count = LEVEL_COUNT;
    if (ng_plus>1){
        count = NG_LEVEL_COUNT;
    }
    level_index++;
    if(player_health <= 0){
        reason_for_defeat = "You ran out of health";
        game_state = DEFEAT_STATE;
    }
    if(level_index >= count){
        game_state = VICTORY_STATE;
        run_time += (int)difftime(time(nullptr), begin_time);
        PlaySound(win_sound);
        return;
    }
    lvl = levels[level_index];
    for(size_t row = 0; row<lvl.rows; ++row){
        for(size_t column = 0; column<lvl.columns; ++column){
            char cell = lvl.data[row * lvl.columns + column];
            if(cell == ENTRANCE){
                player_row = row;
                player_column = column;
            }
        }
    }
    derive_graphics_metrics_from_loaded_level();
    load_enemies();
}
void unload_levels(){
    for (int i = 0; i < levels.size(); ++i) {
        free(levels[i].data);
    }
    levels.clear();
}

void load_levels(){
     unload_levels();
     int count = LEVEL_COUNT;
     level *templates = LEVELS;
    if (ng_plus > 1){
        count = NG_LEVEL_COUNT;
        templates = NG_LEVELS;
    }
    for (int i = 0; i < count; ++i) {
        level cur_level = templates[i];
        char *data_copy = (char *)malloc(cur_level.rows*cur_level.columns);
        std::memcpy(data_copy, cur_level.data, cur_level.rows*cur_level.columns);
        levels.push_back(level{cur_level.rows, cur_level.columns,data_copy});
    }
    silver_quantity = 0;
    gold_quantity = 0;
    if (ng_plus > 1){
        for(NGItem i : new_items){
            level l = levels[i.lvl];
            l.data[i.row*l.columns+i.column] = i.item;
        }
    }
}

void load_prev_level(){
    if (level_index == 0) {
        return;
    }
    level_index--;
    lvl = levels[level_index];
    for(size_t row = 0; row<lvl.rows; ++row){
        for(size_t column = 0; column<lvl.columns; ++column){
            char cell = lvl.data[row * lvl.columns + column];
            if(cell == EXIT){
                player_row = row;
                player_column = column;
            }
        }
    }
    derive_graphics_metrics_from_loaded_level();
    load_enemies();
}


#endif //LEVEL_MECHANICS_H
