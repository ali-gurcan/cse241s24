#include<iostream>
#include "humanic.h"
#include "optimusprime.h"
#include<cstdlib>
using namespace std;

int optimusprime ::optimusprimeCounter=0;

optimusprime::optimusprime()
{
	setType(0);
	setStrength(100);
	setHit(100);
	setName();
}
int optimusprime::optimusprimecounter(){
	return optimusprimeCounter++;
}

string optimusprime:: getType(){
    return "optimusprime";
};
void optimusprime::setName(){
	name="optimusprime_"+to_string(optimusprimecounter());
}

int optimusprime::getDamage() {
    int damage = humanic::getDamage();
    if (rand() % 100 < 15) {
        damage *= 2; // 15% chance of doubling the damage
    }
    return damage;
}
 