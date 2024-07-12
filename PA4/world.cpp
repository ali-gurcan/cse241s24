#include "world.h"
#include "robots.h"
#include "humanic.h"
#include "optimusprime.h" 
#include "robocop.h" 
#include "roomba.h" 
#include "bulldozer.h" 
#include "kamikaze.h" 
#include <iostream>
#include <cstdlib>
#include <ctime>

const int countType = 5;

World::World() {
  int i, j;
  for (i = 0; i < WORLDSIZE; i++) {
    for (j = 0; j < WORLDSIZE; j++) {
      grid[i][j] = NULL;
    }
  }
}
World::~World() {
  int i, j;
  for (i = 0; i < WORLDSIZE; i++) {
    for (j = 0; j < WORLDSIZE; j++) {
      if (grid[i][j] != NULL) delete(grid[i][j]);
    }
  }
}
int World::getRobotCounter(){
  return robotCounter;
}
Robot * World::getAt(int x, int y) {
  if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE))
    return grid[x][y];
  return NULL;
}
void World::setAt(int x, int y, Robot * r) {
  if ((x >= 0) && (x < WORLDSIZE) && (y >= 0) && (y < WORLDSIZE)) {
    grid[x][y] = r;
  }
}
// Function to move a robot to a new position in the grid
void World::moveRobot(int x, int y, int newX, int newY) {
    Robot* temp = grid[x][y];
    grid[x][y] = nullptr; // Clear the current cell
    grid[newX][newY] = temp; // Move the robot to the new cell
}
void World::initializeRobots() {
    srand(time(0));
    int i = 0;
    for (int j = 0; j < countType; j++)
    {
      i = 0;
        while ( i < countType)
        {
            int x = rand() % WORLDSIZE;
            int y = rand() % WORLDSIZE;
            if (this->getAt(x, y) == NULL)
            {
                Robot* robot;
                switch (j)
                {
                case 0:
                    robot = new optimusprime();
                    setAt(x, y, robot);
                    break;
                case 1:
                    robot = new robocop();
                    setAt(x, y, robot);
                    break;
                case 2:
                    robot = new roomba();
                    setAt(x, y, robot);
                    break;
                case 3:
                    robot = new bulldozer();
                    setAt(x, y, robot);
                    break;
                case 4:
                    robot = new kamikaze();
                    setAt(x, y, robot);
                    break;
                default:
                    continue; // Skip if j is out of range
                }
                i++;
            }
        }
    }
}

bool World::isValidCell(int x, int y  ) {
  return x >= 0 && x < WORLDSIZE && y >= 0 && y < WORLDSIZE;
}

// Function to simulate a fight between two robots
void World:: fight(Robot * attacker, Robot * victim) {
    int damageAttacker = attacker -> getDamage();
    victim -> setHit(victim -> getHit() - damageAttacker);

    cout << attacker -> getName() << "(" << attacker -> getHit() << ") hits " <<
    victim -> getName() << "(" << victim -> getHit() + damageAttacker << ") with " <<
    damageAttacker << endl;

    
    // the robot is announced as dead
    if (attacker->getType()=="Kamikaze")
    {
        cout << attacker -> getName() << " is dead!" << endl;
    }
    
    if (victim -> getHit() <= 0) {
      cout << victim -> getName() << " is dead!" << endl;
      return;
    }
    //Victim hp anoounce
    if (victim -> getHit() > 0) {
      cout <<"The new hitpoints of " <<victim -> getName() << " is "<<victim-> getHit()<< endl;
    }

}

void  World::SimulateOneStep() {
  bool allMoved = true; // Flag to track if all robots have moved in this step
  for (int i = 0; i < WORLDSIZE; ++i) {
    for (int j = 0; j < WORLDSIZE; ++j) {
      Robot * robot = grid[i][j];
      if (robot) {
        if (robot -> getHit() <= 0) {
          delete robot; // Remove dead robots from memory
          grid[i][j] = nullptr;
          continue;
        }
          int dir = rand() % 4;
          int newX = i, newY = j;
          if (dir == 0) newX++; // Move right
          else if (dir == 1) newX--; // Move left
          else if (dir == 2) newY++; // Move down
          else newY--; // Move up
          if (isValidCell(newX, newY) && grid[newX][newY]) {
            fight(robot, grid[newX][newY]);
            allMoved = false;
            break; // Only fight once per step
          }
          else if (isValidCell(newX, newY) && !grid[newX][newY]) {
            moveRobot(i, j, newX, newY);
            allMoved = false;
          }
      }
    }
  }
  if (allMoved) return; // If all robots have moved, end the simulation
}
// Function to run the simulation until only one robot remains
void  World::runSimulation() {
  
  while (true) {
    SimulateOneStep(); // Perform one simulation step
    int aliveRobots = 0;
    for (int i = 0; i < WORLDSIZE; ++i) {
      for (int j = 0; j < WORLDSIZE; ++j) {
        if (grid[i][j] && grid[i][j] -> getHit() > 0) {
          aliveRobots++;
        }
      }
    }
    if (aliveRobots <= 1) break; // If only one or zero robots remain, end the simulation
  }
}