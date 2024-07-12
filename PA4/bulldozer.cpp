#include <iostream>
#include <string>

#include "robots.h"
#include "bulldozer.h"

int bulldozer:: bulldozerCounter=0;

bulldozer::bulldozer(){
    setType(3);
	setStrength(50);
	setHit(200);
	setName();
}

std::string bulldozer::getType() {
    return "Bulldozer";
}
int bulldozer ::bulldozercounter(){
    return bulldozerCounter++;
}

int bulldozer::getDamage() {
    int damage = (rand() % strength) + 1;
    return damage;
}
void bulldozer::setName(){
    name="bulldozer_"+to_string(bulldozercounter());
}