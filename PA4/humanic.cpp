#include <iostream>
#include <cstdlib>

#include "robots.h"

#include "humanic.h"

using namespace std;

humanic::humanic(){}
std::string humanic::getType(){
    return "Humanic";
}

int humanic::getDamage(){
    int damage = (rand() % strength) + 1;
    if (rand() % 10 == 0) {
        damage += 50; // 10% chance of tactical nuke attack
    }
    return damage;
}