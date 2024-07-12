#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include "robots.h"

const int WORLDSIZE = 10;

class Robot;
class humanic; 
class optimusprime; 
class robocop; 
class roomba; 
class bulldozer; 
class kamikaze; 

class World {
    friend class Robot;
    friend class humanic; 
    friend class optimusprime; 
    friend class robocop; 
    friend class roomba; 
    friend class bulldozer; 
    friend class kamikaze; 
 private:
    Robot * grid[WORLDSIZE][WORLDSIZE];// Grid of robots
    int robotCounter;
public:
    World();
    ~World();

    int getRobotCounter();
    Robot * getAt(int x, int y);

    void setAt(int x, int y, Robot * r);
    bool isValidCell(int x, int y);
    void moveRobot(int x, int y, int newX, int newY);
    void initializeRobots();
    void fight(Robot * attacker, Robot * victim); 
    void SimulateOneStep();
    void runSimulation();
   
};
#endif // world_h
