#ifndef ENEMY_DATA_H
#define ENEMY_DATA_H

#include <iostream>
#include <vector>
#include "globals.h"

enum DamageType {
    Fire, Cold, Physical
};

struct Ability {
    std::string Name;
    int damage;
    DamageType damage_type;
    int chance;
};

struct Enemy {
    std::string Name;
    int health;
    int damage;
    std::vector<Ability> abilities;
    int gives_health;
    int gives_score;
    int takes_score;
    int ability_use_chance;
    int row;
    int column;
};

Enemy CreateGoblin(int row, int column) {
    Enemy e{
            "Goblin", 40, 20, std::vector<Ability>(), 0, 100, 0, 0, row, column
    };

    e.health *= ng_plus;
    e.gives_health *= ng_plus;
    e.gives_score = e.gives_score * ng_plus * 3 / 2;
    e.takes_score *= ng_plus;
    e.damage *= ng_plus;
    return e;
}

Enemy CreateGreatGoblin(int row, int column) {
    Enemy e{
            "GreatGoblin", 100, 30, std::vector<Ability>(), 0, 250, 0, 0, row, column
    };

    e.health *= ng_plus * 0.7;
    e.gives_health *= (15 * ng_plus) - 15;
    e.gives_score = e.gives_score * ng_plus * 3 / 2;
    e.takes_score *= ng_plus;
    e.damage *= ng_plus;
    return e;
};

Enemy CreateGnome(int row, int column) {
    Enemy e{
            "Gnome", 50, 0, std::vector<Ability>(), 40, 150, 40, 0, row, column
    };

    e.health *= ng_plus;
    e.gives_health = e.gives_health * ng_plus + 10;
    e.gives_score = e.gives_score * ng_plus * 3 / 2;
    e.takes_score *= ng_plus;
    e.damage *= ng_plus;
    return e;
};

Enemy CreateSpider(int row, int column) {
    Enemy e{
            "Spider", 65, 25, std::vector<Ability>(), 40, 175, 0, 0, row, column
    };

    e.health *= ng_plus;
    e.gives_health *= ng_plus*2;
    e.gives_score = e.gives_score * ng_plus * 3 / 2;
    e.takes_score *= ng_plus;
    e.damage *= ng_plus*0.6;
    return e;
}

Enemy CreateTroll(int row, int column) {
    Enemy e{
            "Troll", 80, 15, std::vector<Ability>(), 70, 200, 0, 0, row, column
    };

    e.health *= ng_plus;
    e.gives_health *= ng_plus;
    e.gives_score = e.gives_score * ng_plus * 3 / 2;
    e.takes_score *= ng_plus;
    e.damage *= ng_plus;
    return e;
}


#endif //ENEMY_DATA_H
