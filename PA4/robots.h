#ifndef _ROBOTS_H
#define _ROBOTS_H

#include <iostream>
#include "world.h"

using namespace std;

class World;
class humanic; 
class Robot
{
friend class World;
friend class humanic;


protected:
	int type;
	int strength;
	int hitpoints;
	string name;
	static int nameCounter;
public:
	Robot();
	
	virtual int getDamage() = 0;
	//getters
	int getHit();
	int getStrength();
	virtual string getType();
	int getNameCounter();
	string getName();
	//setters
	void setType(int newType);
	void setHit(int newHit);
	void setStrength(int newStrength);
	void setNameCounter();
	virtual void setName();

};

#endif