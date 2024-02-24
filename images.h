#ifndef IMAGES_H
#define IMAGES_H

#include "raylib.h"

#include "globals.h"
#include "level_data.h"
#include "enemy_data.h"

#include <string>
#include <cassert>

void load_fonts() {
    menu_font = LoadFont("data/fonts/ARCADECLASSIC.TTF");
    instruction_font = LoadFont("data/fonts/PixeloidSans.ttf");
}

void unload_fonts() {
    UnloadFont(menu_font);
    UnloadFont(instruction_font);
}

void load_images() {
    wall_image     = LoadTexture("data/images/textures/wall.png");
    floor_image    = LoadTexture("data/images/textures/floor.png");
    entrance_image = LoadTexture("data/images/textures/entrance.png");
    exit_image     = LoadTexture("data/images/textures/exit.png");
    apple_image    = LoadTexture("data/images/textures/apple1.png");
    diamond_image  = LoadTexture("data/images/textures/diamond_8b.png");
    potion_image   = LoadTexture("data/images/textures/potion.png");
    potion_small_image = LoadTexture("data/images/textures/potion_small.png");
    gold_key_image = LoadTexture("data/images/textures/gold_key.png");
    silver_key_image = LoadTexture("data/images/textures/silver_key.png");
    silver_door_image = LoadTexture("data/images/textures/silver_door.png");
    gold_door_image = LoadTexture("data/images/textures/gold_door.png");
    spider_image = LoadTexture("data/images/textures/spider1.png");
    bomb_image = LoadTexture("data/images/textures/bomb.png");
    snake_image = LoadTexture("data/images/textures/snake.png");
    coin_sprite    = load_sprite("data/images/coin/coin", ".png", 9);
    player_sprite  = load_sprite("data/images/player/player", ".png", 11);
    goblin_great_sprite  = load_sprite("data/images/goblin/goblin", ".png", 11);
    spike_sprite   = load_sprite("data/images/spikes/spikes", ".png", 8);
    gnome_sprite   = load_sprite("data/images/gnome/gnome", ".png", 11);
    goblin_sprite = load_sprite("data/images/goblin_small/goblin_small", ".png", 11);
    troll_sprite = load_sprite("data/images/troll/troll", ".png", 11);
    fire_sprite  = load_sprite("data/images/fire/fire", ".png", 4);
}

void unload_images() {
    UnloadTexture(wall_image);
    UnloadTexture(floor_image);
    UnloadTexture(entrance_image);
    UnloadTexture(exit_image);
    UnloadTexture(apple_image);
    UnloadTexture(diamond_image);
    UnloadTexture(potion_image);
    UnloadTexture(potion_small_image);
    UnloadTexture(gold_key_image);
    UnloadTexture(silver_key_image);
    UnloadTexture(spider_image);
    UnloadTexture(bomb_image);
    UnloadTexture(snake_image);
    unload_sprite(coin_sprite);
    unload_sprite(player_sprite);
    unload_sprite(goblin_great_sprite);
    unload_sprite(spike_sprite);
    unload_sprite(gnome_sprite);
    unload_sprite(goblin_sprite);
    unload_sprite(troll_sprite);
    unload_sprite(fire_sprite);
}

void draw_image(Texture2D image, float x, float y, float size) {
    draw_image(image, x, y, size, size);
}

void draw_image(Texture2D image, float x, float y, float width, float height) {
    Rectangle source = { 0.0f, 0.0f, static_cast<float>(image.width), static_cast<float>(image.height) };
    Rectangle destination = { x, y, width, height };
    DrawTexturePro(image, source, destination, { 0.0f, 0.0f }, 0.0f, WHITE);
}

sprite load_sprite(
        const std::string &file_name_prefix,
        const std::string &file_name_suffix,
        size_t frame_count,
        bool loop,
        size_t frames_to_skip
) {
    assert(frame_count < 100);

    sprite result = {
            frame_count, frames_to_skip, 0, 0, loop, 0, new Texture2D[frame_count]
    };

    for (size_t i = 0; i < frame_count; ++i) {
        std::string file_name;
        if (frame_count < 10) {
            file_name = file_name_prefix;
            file_name += std::to_string(i);
            file_name += file_name_suffix;
        } else {
            file_name = file_name_prefix;
            file_name += i < 10 ? ("0" + std::to_string(i)) : std::to_string(i);
            file_name += file_name_suffix;
        }
        result.frames[i] = LoadTexture(file_name.c_str());
    }

    return result;
}

void unload_sprite(sprite &sprite) {
    assert(sprite.frames != nullptr);

    for (size_t i = 0; i < sprite.frame_count; ++i) {
        UnloadTexture(sprite.frames[i]);
    }
    delete[] sprite.frames;
    sprite.frames = nullptr;
}

void draw_sprite(sprite &sprite, float x, float y, float size) {
    draw_sprite(sprite, x, y, size, size);
}

void draw_sprite(sprite &sprite, float x, float y, float width, float height) {
    draw_image(sprite.frames[sprite.frame_index], x, y, width, height);

    if (sprite.prev_game_frame == game_frame) {
        return;
    }
    if (sprite.frames_skipped < sprite.frames_to_skip) {
        ++sprite.frames_skipped;
    } else {
        sprite.frames_skipped = 0;

        ++sprite.frame_index;
        if (sprite.frame_index >= sprite.frame_count) {
            sprite.frame_index = sprite.loop ? 0 : sprite.frame_count - 1;
        }
    }
    sprite.prev_game_frame = game_frame;
}

void load_sound(){
    coin_sound = LoadSound("data/sounds/coin.wav");
    //exit_sound = LoadSound("data/sounds/exit.wav");
    apple_sound = LoadSound("data/sounds/apple.wav");
    hurt_sound = LoadSound("data/sounds/hurt3.wav");
    gnome_laugh_sound = LoadSound("data/sounds/gnome_laugh.wav");
    defeat_sound = LoadSound("data/sounds/defeat.wav");
    diamond_sound = LoadSound("data/sounds/diamond.wav");
    win_enemy_sound = LoadSound("data/sounds/win_enemy.wav");
    potion_sound = LoadSound("data/sounds/potion2.wav");
    jump_sound = LoadSound("data/sounds/jump3.wav");
    keys_sound = LoadSound("data/sounds/keys1.wav");
    win_sound = LoadSound("data/sounds/win.wav");
    soundtrack_music = LoadMusicStream("data/music/soundtrack3.mp3");
    door_sound = LoadSound("data/sounds/door3.wav");
    bomb_sound = LoadSound("data/sounds/bomb.wav");
    fire_sound = LoadSound("data/sounds/fire.wav");
    troll_sound = LoadSound("data/sounds/troll3.wav");
    spider_sound = LoadSound("data/sounds/spider.wav");
}
void unload_sound(){
    UnloadSound(coin_sound);
    UnloadSound(exit_sound);
    UnloadSound(apple_sound);
    UnloadSound(hurt_sound);
    UnloadSound(defeat_sound);
    UnloadSound(diamond_sound);
    UnloadSound(win_enemy_sound);
    UnloadSound(potion_sound);
    UnloadSound(jump_sound);
    UnloadSound(keys_sound);
    UnloadSound(win_sound);
    UnloadSound(door_sound);
    UnloadSound(bomb_sound);
    UnloadSound(fire_sound);
    UnloadSound(troll_sound);
    UnloadSound(spider_sound);
    UnloadMusicStream(soundtrack_music);
}

#endif // IMAGES_H