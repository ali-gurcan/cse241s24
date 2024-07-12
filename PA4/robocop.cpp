#include "robocop.h"
#include <iostream>

 int robocop:: robocopCounter=0;

robocop::robocop(){
    setType(1);
	setStrength(30);
	setHit(40);
	setName();
}
int robocop::robocopcounter(){
    return robocopCounter++;
};

std::string robocop::getType()  {
    return "robocop";
}

int robocop::getDamage() {
    return humanic::getDamage(); // RoboCop uses humanic's getDamage implementation
}
void robocop::setName(){
    name="robocop_"+to_string(robocopcounter());
}
