#include "kamikaze.h"
#include "robots.h"

#include <iostream>
#include<string>

int kamikaze:: kamikazeCounter=0;

kamikaze::kamikaze()
{
	setType(4);
	setHit(10);
	setStrength(10);
    setName();
}

int kamikaze::kamikazecounter(){return kamikazeCounter++;}

std::string kamikaze::getType()  {
    return "Kamikaze";
}

int kamikaze::getDamage() {
    int damage;
    damage=hitpoints;
    hitpoints=0;
    return damage;
}
void kamikaze::setName(){
	name="kamikaze_"+to_string(kamikazecounter());
}