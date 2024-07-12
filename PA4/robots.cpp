#include<iostream>
#include <string>
#include"robots.h"

using namespace std;

int Robot::nameCounter = 0;
Robot::Robot(){};

string Robot::getType()
{
	switch (type)
		{
			case 0: return "optimusprime";
			case 1: return "robocop";
			case 2: return "roomba";
			case 3: return "bulldozer";
		}
	return "unknown";
}
int Robot::getHit(){return hitpoints;}

int Robot::getStrength(){return strength;}

int Robot::getNameCounter(){return nameCounter;}


string Robot::getName(){return name;}

void Robot::setHit(int newHit){hitpoints = newHit;}

void Robot::setType(int newType){type = newType;}

void Robot::setStrength(int newStrength){strength = newStrength;}
void Robot::setNameCounter(){ nameCounter++;}

void Robot::setName(){name = name;}
