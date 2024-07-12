#include <iostream>
#include<string>
#include<cstdlib>
#include<ctime>

#include "roomba.h"

int roomba:: roombaCounter;

roomba::roomba(){
    setType(2);
	setStrength(3);
	setHit(10);
	setName();
}
int roomba::roombacounter(){
    return roombaCounter++;
}

std::string roomba::getType() {
    return "Roomba";
}

int roomba::getDamage() {
    srand(time(0));
    int damage = (rand() % strength) + 1;
    return damage;
}

void roomba::setName(){
	name="roomba_"+to_string(roombacounter());
	
}
