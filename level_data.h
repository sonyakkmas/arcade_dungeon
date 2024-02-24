#ifndef LEVEL_DESCRIPTION_H
#define LEVEL_DESCRIPTION_H

#include "globals.h"
#include "enemy_data.h"

const char FLOOR = ' ';
const char WALL = '#';
const char ENTRANCE = 'V';
const char EXIT = 'E';
const char COIN = '*';
const char GOBLIN_GREAT = 'G';
const char GOBLIN = 'g';
const char APPLE = 'A';
const char SPIKE = 'S';
const char GNOME = '$';
const char DIAMOND = 'D';
const char POTION = 'P';
const char POTION_SMALL = 'p';
const char GOLD_KEY = '?';
const char SILVER_KEY = '/';
const char SILVER_DOOR = 'l';
const char GOLD_DOOR = 'L';
const char SPIDER = '{';
const char BOMB = 'B';
const char TROLL = 'T';
const char FIRE = 'F';
const char SNAKE = '~';

struct level {
    size_t rows = 0, columns = 0;
    char *data;
    std::vector<Enemy> enemies;
};
char LEVEL_1_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', 'V', ' ', ' ', '*', 'p', 'g', 'E', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#'
};
level LEVEL_1 = {
        3, 9,
        LEVEL_1_DATA
};

char LEVEL_2_DATA[] = {
        '#', '#', '#',
        '#', 'V', '#',
        '#', 'A', '#',
        '#', ' ', '#',
        '#', '*', '#',
        '#', '?', '#',
        '#', 'L', '#',
        '#', 'E', '#',
        '#', '#', '#'
};
level LEVEL_2 = {
        9, 3,
        LEVEL_2_DATA
};
char LEVEL_3_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', 'V', ' ', ' ', '#', 'E', ' ', ' ', '#',
        '#', '#', '#', ' ', '#', '#', '#', ' ', '#',
        '#', ' ', ' ', ' ', '#', '*', ' ', ' ', '#',
        '#', 'A', '#', '#', '#', ' ', '#', '#', '#',
        '#', '*', '#', '$', '#', ' ', ' ', ' ', '#',
        '#', ' ', '#', ' ', '#', '#', '#', ' ', '#',
        '#', '{', '~', ' ', ' ', 'A', 'G', ' ', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
};
level LEVEL_3 = {
        9, 9,
        LEVEL_3_DATA
};
char LEVEL_4_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', 'V', ' ', ' ', ' ', 'p', ' ', ' ', '#',
        '#', '#', '#', '#', '#', '#', '#', ' ', '#',
        '#', ' ', 'F', ' ', ' ', 'p', '#', '*', '#',
        '#', 'T', '#', 'S', '#', '*', '#', ' ', '#',
        '#', 'A', '#', '*', '#', 'E', '#', ' ', '#',
        '#', ' ', '#', '#', '#', '#', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', 'A', ' ', ' ', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
};
level LEVEL_4 = {
        9, 9,
        LEVEL_4_DATA
};

char LEVEL_5_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '#', '#', '#', '#', 'A', '#', '?', '#',
        '#', 'V', ' ', ' ', ' ', ' ', '#', 'S', '#',
        '#', '#', '#', '#', '#', ' ', 'l', '*', '#',
        '#', 'p', 'l', 'A', 'g', ' ', '#', '#', '#',
        '#', '/', '#', 'D', '#', ' ', '#', '#', '#',
        '#', '#', '#', '#', '#', ' ', '#', '#', '#',
        '#', 'E', 'A', '*', ' ', ' ', '$', '/', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
};
level LEVEL_5 = {
        9, 9,
        LEVEL_5_DATA
};


char LEVEL_6_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', 'A', 'A', 'A', '#', '*', '#', '*', '#',
        '#', 'g', '#', '#', '#', '~', '#', ' ', '#',
        '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#',
        '#', ' ', '#', ' ', '#', '*', '#', '*', '#',
        '#', ' ', '#', 'g', '#', '#', '#', 'S', '#',
        '#', ' ', '#', 'g', '#', '#', '#', ' ', '#',
        '#', 'V', '#', 'D', 'P', '#', '#', 'E', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
};
level LEVEL_6 = {
        9, 9,
        LEVEL_6_DATA
};

char LEVEL_7_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '#', '{', 'B', ' ', 'B', 'B', '*', '#',
        '#', '#', ' ', '#', 'p', '#', '#', ' ', '#',
        '#', '#', ' ', '#', '#', '#', '#', ' ', '#',
        '#', '#', ' ', '#', '#', '#', '#', ' ', '#',
        '#', 'V', ' ', '#', '#', 'A', '$', ' ', '#',
        '#', '#', ' ', '#', '#', '#', '#', 'E', '#',
        '#', '#', ' ', '#', '#', 'A', '#', '*', '#',
        '#', '#', ' ', 'T', ' ', ' ', '*', ' ', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#'
};
level LEVEL_7 = {
        10, 9,
        LEVEL_7_DATA
};

char LEVEL_8_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#',
        '#', '{', 'F', ' ', 'A', 'E', '#',
        '#', '*', '#', '#', '#', '#', '#',
        '#', 'S', '#', '#', '#', '#', '#',
        '#', '*', '#', 'P', 'D', '#', '#',
        '#','*', '#', 'g', '#', '#', '#',
        '#', ' ', ' ', ' ', '*', '#', '#',
        '#', ' ', '#', 'B', '#', '#', '#',
        '#', 'V', '#', 'p', '#', '#', '#',
        '#', '#', '#', '#', '#', '#', '#',
};
level LEVEL_8 = {
        10, 7,
        LEVEL_8_DATA
};

char LEVEL_9_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', 'V', ' ', ' ', ' ', ' ', ' ', '*', '#', '#',
        '#', '#', '#', 'T', '#', '#', '#', ' ', '#', '#',
        '#', '#', 'g', '*', 'g', '#', '#', ' ', '#', '#',
        '#', '#', 'D', 'g', 'D', '#', '#', ' ', '#', '#',
        '#', '#', '?', 'G', 'D', '#', '#', 'L', 'A', '#',
        '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#',
        '#', 'E', '*', ' ', ' ', ' ', ' ', ' ', '#', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
};
level LEVEL_9 = {
        9, 10,
        LEVEL_9_DATA
};

char LEVEL_10_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', 'T', 'P', 'g', '?', '#', 'E', '#', '?', 'g', 'g', 'T', '#',
        '#', ' ', 'A', 'P', 'g', '#', 'L', '#', 'D', 'g', 'g', ' ', '#',
        '#', '{', '#', '#', '#', '#', 'L', '#', '#', '#', '#', '~', '#',
        '#', 'G', ' ', 'B', 'B', 'B', ' ', 'F', 'F', 'F', 'P', 'G', '#',
        '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', '#',
        '#', 'D', '#', '#', '#', '#', ' ', '#', ' ', 'D', 'P', 'P', '#',
        '#', 'P', '#', '#', '#', '#', ' ', '#', 'L', '#', '#', '#', '#',
        '#', '$', ' ', 'g', 'g', ' ', ' ', ' ', '*', '*', '*', 'D', '#',
        '#', '#', '#', '#', '#', '#', 'V', '#', '#', 'A', '#', 'D', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
};

level LEVEL_10 = {
        11, 13,
        LEVEL_10_DATA
};

const size_t LEVEL_COUNT = 10;
level LEVELS[LEVEL_COUNT] = {
        LEVEL_1,
        LEVEL_2,
        LEVEL_3,
        LEVEL_4,
        LEVEL_5,
        LEVEL_6,
        LEVEL_7,
        LEVEL_8,
        LEVEL_9,
        LEVEL_10,
};

char Empty[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
};


char LEVEL_NG_1_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', 'E', '#', '/', 'P', 'G', '#', 'V', '#',
        '#', 'P', '#', '#', '#', ' ', '#', ' ', '#',
        '#', 'B', '#', '#', '#', 'A', '#', '*', '#',
        '#', 'T', ' ', 'T', ' ', 'A', '#', ' ', '#',
        '#', '#', '#', ' ', '#', '#', '#', '*', '#',
        '#', 'P', '#', ' ', '#', 'A', '#', ' ', '#',
        '#', 'P', 'l', ' ', 'S', ' ', 'S', '$', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
};

level LEVEL_NG_1 = {
        9, 9,
        LEVEL_NG_1_DATA
};

char LEVEL_NG_2_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '*', 'F', 'F', '?', 'F', 'F', 'V', '#',
        '#', 'P', 'E', '#', '#', '#', '#', ' ', '#',
        '#', '*', '#', '#', '#', '#', '#', '$', '#',
        '#', '*', '#', 'A', '#', 'D', '#', ' ', '#',
        '#', 'G', 'T', '*', 'F', '{', ' ', 'p', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#'
};

level LEVEL_NG_2 = {
        7, 9,
        LEVEL_NG_2_DATA
};


char LEVEL_NG_3_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', '#', '#', '#', 'V', '#', 'P', 'D', '#',
        '#', 'D', 'P', '#', ' ', '#', 'P', 'g', '#',
        '#', ' ', 'S', 'G', ' ', '#', '#', 'T', '#',
        '#', 'S', 'P', '#', '*', ' ', ' ', ' ', '#',
        '#', ' ', 'A', '#', '{', '#', '#', '#', '#',
        '#', 'S', '#', '#', 'A', ' ', 'B', 'p', '#',
        '#', 'A', '#', '#', '#', '#', '#', '#', '#',
        '#', 'T' , 'g', ' ', 'B', 'B', 'P', 'E', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#'
};

level LEVEL_NG_3 = {
        10, 9,
        LEVEL_NG_3_DATA
};

char LEVEL_NG_4_DATA[] = {
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
        '#', 'D', 'D', 'P', 'P', 'E', 'l', 'V', '#',
        '#', 'l', '#', '#', '#', '#', '#', 'L', '#',
        '#', 'S', 'F', '#', 'A', 'D', '#', 'p', '#',
        '#', ' ', 'S', 'F', 'G', 'P', '#', 'p', '#',
        '#', 'S', 'F', 'D', '{', ' ', '#', '*', '#',
        '#', '~', 'T', 'A', '~', 'S', '#', '*', '#',
        '#', '/', 'A', '~', 'S', ' ', '~', '*', '#',
        '#', '#', '#', '#', '#', '#', '#', '#', '#',
};

level LEVEL_NG_4 = {
        9, 9,
        LEVEL_NG_4_DATA
};

const size_t NG_LEVEL_COUNT = 12;
level NG_LEVELS[NG_LEVEL_COUNT] = {
        LEVEL_1,
        LEVEL_NG_1,
        LEVEL_3,
        LEVEL_NG_2,
        LEVEL_4,
        LEVEL_NG_3,
        LEVEL_5,
        LEVEL_NG_4,
        LEVEL_7,
        LEVEL_8,
        LEVEL_9,
        LEVEL_10,
};

level lvl;
std::vector<level> levels;
size_t level_index = -1;
int usage_save_last = 0;

struct NGItem {
    int lvl;
    int row;
    int column;
    char item;
};


std::vector<NGItem> new_items;

void init_ng() {
    new_items.push_back(NGItem{0,1,2,'P'});
    new_items.push_back(NGItem{0,1,3,'P'});

    new_items.push_back(NGItem{2,4,3,'*'});
    new_items.push_back(NGItem{2,3,2,'#'});
    new_items.push_back(NGItem{2,3,1,'D'});
    new_items.push_back(NGItem{2,4,1,'/'});


    new_items.push_back(NGItem{4,5,3,'D'});

    new_items.push_back(NGItem{6,1,7,'A'});
    new_items.push_back(NGItem{6,1,5,'p'});


    new_items.push_back(NGItem{8,1,7,'E'});
    new_items.push_back(NGItem{8,2,7,'l'});
    new_items.push_back(NGItem{8,6,7,'P'});
    new_items.push_back(NGItem{8,4,2,'#'});
    new_items.push_back(NGItem{8,1,1,'/'});
    new_items.push_back(NGItem{8,2,1,'S'});
    new_items.push_back(NGItem{8,3,1,'A'});
    new_items.push_back(NGItem{8,3,3,'D'});
    new_items.push_back(NGItem{8,3,4,'#'});
    new_items.push_back(NGItem{8,3,5,' '});
    new_items.push_back(NGItem{8,3,2,'T'});
    new_items.push_back(NGItem{8,2,3,' '});
    new_items.push_back(NGItem{8,4,5,' '});
    new_items.push_back(NGItem{8,5,5,'*'});
    new_items.push_back(NGItem{8,1,6,'#'});
    new_items.push_back(NGItem{8,1,5,'D'});
    new_items.push_back(NGItem{8,1,3,'g'});
    new_items.push_back(NGItem{8,1,2,'#'});
    new_items.push_back(NGItem{8,2,4,'#'});
    new_items.push_back(NGItem{8,2,5,'F'});


    new_items.push_back(NGItem{9,6,4,'l'});
    new_items.push_back(NGItem{9,6,5,'?'});
    new_items.push_back(NGItem{9,1,4,'P'});
    new_items.push_back(NGItem{9,1,3,'P'});

    new_items.push_back(NGItem{10,5,4,'/'});
    new_items.push_back(NGItem{10,7,3,'P'});
    new_items.push_back(NGItem{10,7,4,'P'});
    new_items.push_back(NGItem{10,7,5,'P'});
    new_items.push_back(NGItem{10,1,4,'P'});
    new_items.push_back(NGItem{10,1,3,'P'});

    new_items.push_back(NGItem{11,1,3,'T'});
    new_items.push_back(NGItem{11,2,4,'T'});
    new_items.push_back(NGItem{11,2,11,'p'});
    new_items.push_back(NGItem{11,2,10,'{'});
    new_items.push_back(NGItem{11,6,8,'P'});
    new_items.push_back(NGItem{11,6,8,'P'});
    new_items.push_back(NGItem{11,8,8,'P'});
    new_items.push_back(NGItem{11,8,9,'P'});
    new_items.push_back(NGItem{11,8,10,'P'});
    new_items.push_back(NGItem{11,9,9,'P'});
}

#endif //LEVEL_DESCRIPTION_H
