#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "level_mechanics.h"
#include "level_data.h"
#include "iostream"
#include "enemy_data.h"

using namespace std;


int collision_check_dx(int dx, int dy) {
    int sign;
    int tmp_dx = 1;
    if (dx > 0) {
        sign = 1;
    } else {
        sign = -1;
    }
    tmp_dx *= sign;
    int tmp_next_player_column = static_cast<int>(player_column) + tmp_dx;
    int tmp_next_player_row = static_cast<int>(player_row) + dy;
    if ((tmp_next_player_row < 0 || tmp_next_player_row >= lvl.rows) ||
        (tmp_next_player_column < 0 || tmp_next_player_column >= lvl.columns)) {
        return 0;
    }
    char cell = lvl.data[tmp_next_player_row * lvl.columns + tmp_next_player_column];
    if (dx > 1 || dx < -1) {
        if (lvl.data[tmp_next_player_row * lvl.columns + tmp_next_player_column] != WALL) {
            if (cell == GOBLIN) {
                return tmp_dx * sign;
            } else if (cell == GOBLIN_GREAT) {
                return tmp_dx * sign;
            } else if (cell == GNOME) {
                return tmp_dx * sign;
            } else if (cell == GOLD_DOOR) {
                return tmp_dx;
            } else if (cell == SILVER_DOOR) {
                return tmp_dx;
            } else {
                PlaySound(jump_sound);
                return dx;
            }
        } else if (lvl.data[tmp_next_player_row * lvl.columns + tmp_next_player_column] == WALL) {
            return tmp_dx;
        }

    } else {
        return dx;
    }
    return 0;
}

int collision_check_dy(int dx, int dy) {
    int sign;
    int tmp_dy = 1;
    if (dy > 0) {
        sign = 1;
    } else {
        sign = -1;
    }
    tmp_dy *= sign;
    int tmp_next_player_column = static_cast<int>(player_column) + dx;
    int tmp_next_player_row = static_cast<int>(player_row) + tmp_dy;
    if ((tmp_next_player_row < 0 || tmp_next_player_row >= lvl.rows) ||
        (tmp_next_player_column < 0 || tmp_next_player_column >= lvl.columns)) {
        return 0;
    }
    char cell = lvl.data[tmp_next_player_row * lvl.columns + tmp_next_player_column];
    if (dy > 1 || dy < -1) {
        if (lvl.data[tmp_next_player_row * lvl.columns + tmp_next_player_column] != WALL) {
            if (lvl.data[tmp_next_player_row * lvl.columns + tmp_next_player_column] != WALL) {
                if (cell == GOBLIN) {
                    return tmp_dy * sign;
                } else if (cell == GOBLIN_GREAT) {
                    return tmp_dy * sign;
                } else if (cell == GNOME) {
                    return tmp_dy * sign;
                } else if (cell == GOLD_DOOR) {
                    return tmp_dy;
                } else if (cell == SILVER_DOOR) {
                    return tmp_dy;
                } else {
                    PlaySound(jump_sound);
                    return dy;
                }
            }
        } else if (lvl.data[tmp_next_player_row * lvl.columns + tmp_next_player_column] == WALL) {
            return tmp_dy;
        }
    } else {
        return dy;
    }
    return 0;
}

void play_enemy_sound(Enemy *e) {
    if (e->Name == "Goblin" || e->Name == "GreatGoblin") {
        PlaySound(hurt_sound);
    } else if (e->Name == "Gnome") {
        PlaySound(gnome_laugh_sound);
        PlaySound(hurt_sound);
    } else if (e->Name == "Troll") {
        PlaySound(troll_sound);
        PlaySound(hurt_sound);
    } else if (e->Name == "Spider") {
        PlaySound(spider_sound);
        PlaySound(hurt_sound);
    }
}

void fight(int dx, int dy) {
    int player_damage = 20;
    if (ng_plus > 1) {
        player_damage = (player_damage - 2.5) * ng_plus;
    }
    int new_dx = collision_check_dx(dx, dy);
    int new_dy = collision_check_dy(dx, dy);
    int dx_sign = 0;
    if (dx != 0) {
        dx_sign = dx / abs(new_dx);
    }
    int dy_sign = 0;
    if (dy != 0) {
        dy_sign = dy / abs(new_dy);
    }
    int prev_player_column = static_cast<int>(player_column) - dx_sign;
    int prev_player_row = static_cast<int>(player_row) - dy_sign;
    int next_player_column = static_cast<int>(player_column) + new_dx;
    int next_player_row = static_cast<int>(player_row) + new_dy;
    Enemy *e = NULL;
    for (int i = 0; i < lvl.enemies.size(); ++i) {
        if (lvl.enemies[i].row == next_player_row && lvl.enemies[i].column == next_player_column) {
            e = &lvl.enemies[i];
        }
    }
    player_health -= e->damage;
    save_health -= e->damage;
    player_score -= e->takes_score;
    e->health -= player_damage;
    if (player_health <= 0 || player_score < 0) {
        PlaySound(defeat_sound);
        game_state = DEFEAT_STATE;
        run_time += (int) difftime(time(nullptr), begin_time);
        if (player_health <= 0) {
            reason_for_defeat = "You  ran  out  of  health";
        } else {
            reason_for_defeat = "You  ran  out  of  score";
        }
    } else if (e->health <= 0) {
        PlaySound(win_enemy_sound);
        player_row = static_cast<size_t>(next_player_row);
        player_column = static_cast<size_t>(next_player_column);
        lvl.data[next_player_row * lvl.columns + next_player_column] = FLOOR;
        player_score += e->gives_score;
        player_health += e->gives_health;
        save_health += e->gives_health;
        counter_monsters++;
    } else {
        if (lvl.data[prev_player_row * lvl.columns + prev_player_column] != WALL) {
            player_row = static_cast<size_t>(prev_player_row);
            player_column = static_cast<size_t>(prev_player_column);
        }
        play_enemy_sound(e);
    }
}

void move_player(int dx, int dy) {
    int new_dx = collision_check_dx(dx, dy);
    int new_dy = collision_check_dy(dx, dy);
    if (new_dx == 0 && new_dy == 0) {
        return;
    }
    int next_player_column = static_cast<int>(player_column) + new_dx;
    int next_player_row = static_cast<int>(player_row) + new_dy;
    if (!(next_player_row >= 0 && next_player_row < lvl.rows &&
          next_player_column >= 0 && next_player_column < lvl.columns)) {
        return;
    }
    char cell = lvl.data[next_player_row * lvl.columns + next_player_column];
    if ((cell != WALL)) {
        if (cell != GOLD_DOOR) {
            if (cell != SILVER_DOOR) {
                if (cell == GOBLIN || cell == GNOME || cell == GOBLIN_GREAT || cell == TROLL || cell == SPIDER) {
                    fight(dx, dy);
                } else {
                    player_row = static_cast<size_t>(next_player_row);
                    player_column = static_cast<size_t>(next_player_column);
                    switch (cell) {
                        case COIN:
                            lvl.data[next_player_row * lvl.columns + next_player_column] = FLOOR;
                            player_score += POINTS_FOR_COIN;
                            PlaySound(coin_sound);
                            break;
                        case EXIT:
                            load_next_level();
                            PlaySound(exit_sound);
                            break;
                        case ENTRANCE:
                            load_prev_level();
                            break;
                        case APPLE:
                            lvl.data[next_player_row * lvl.columns + next_player_column] = FLOOR;
                            player_health += POINTS_FOR_APPLE;
                            save_health += POINTS_FOR_APPLE;
                            PlaySound(apple_sound);
                            break;
                        case SPIKE:
                            PlaySound(defeat_sound);
                            reason_for_defeat = "You  stepped  on  the  spike";
                            game_state = DEFEAT_STATE;
                            run_time += (int) difftime(time(nullptr), begin_time);
                            break;
                        case DIAMOND:
                            lvl.data[next_player_row * lvl.columns + next_player_column] = FLOOR;
                            player_score += POINTS_FOR_DIAMOND;
                            PlaySound(diamond_sound);
                            break;
                        case POTION:
                            lvl.data[next_player_row * lvl.columns + next_player_column] = FLOOR;
                            player_health += POINTS_FOR_POTION;
                            save_health += POINTS_FOR_POTION;
                            PlaySound(potion_sound);
                            break;
                        case POTION_SMALL:
                            lvl.data[next_player_row * lvl.columns + next_player_column] = FLOOR;
                            player_health += POINTS_FOR_SMALL_POTION;
                            save_health += POINTS_FOR_SMALL_POTION;
                            PlaySound(potion_sound);
                            break;
                        case GOLD_KEY:
                            lvl.data[next_player_row * lvl.columns + next_player_column] = FLOOR;
                            gold_quantity += 1;
                            PlaySound(keys_sound);
                            break;
                        case SILVER_KEY:
                            PlaySound(keys_sound);
                            lvl.data[next_player_row * lvl.columns + next_player_column] = FLOOR;
                            silver_quantity += 1;
                            break;
                        case BOMB:
                            PlaySound(bomb_sound);
                            lvl.data[next_player_row * lvl.columns + next_player_column] = FLOOR;
                            if (ng_plus == 1) {
                                player_health -= POINTS_FOR_BOMB;
                                save_health -= POINTS_FOR_BOMB;
                            } else {
                                player_health -= POINTS_FOR_BOMB * 2;
                                save_health -= POINTS_FOR_BOMB * 2;
                            }
                            break;
                        case FIRE:
                            PlaySound(fire_sound);
                            player_health -= POINTS_FOR_FIRE;
                            break;
                        case SNAKE:
                            PlaySound(defeat_sound);
                            reason_for_defeat = "You  stepped  on  the  snake";
                            game_state = DEFEAT_STATE;
                            run_time += (int) difftime(time(nullptr), begin_time);
                            break;
                        default:
                            break;
                    }
                }
            } else {
                if (silver_quantity > 0) {
                    player_row = static_cast<size_t>(next_player_row);
                    player_column = static_cast<size_t>(next_player_column);
                    PlaySound(door_sound);
                    lvl.data[next_player_row * lvl.columns + next_player_column] = FLOOR;
                    silver_quantity--;
                }
            }
        } else {
            if (gold_quantity > 0) {
                player_row = static_cast<size_t>(next_player_row);
                player_column = static_cast<size_t>(next_player_column);
                PlaySound(door_sound);
                lvl.data[next_player_row * lvl.columns + next_player_column] = FLOOR;
                gold_quantity--;
            }
        }
    } else {
        if (abs(new_dy) == 2 || abs(new_dx) == 2) {
            new_dy /= 2;
            new_dx /= 2;
            move_player(new_dx, new_dy);
        }
    }
}

#endif //PLAYER_H