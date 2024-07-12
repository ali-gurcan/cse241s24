#include <iostream>
#include "world.h"
#include "robots.h"
#include "humanic.h"
#include "optimusprime.h" 
#include "robocop.h" 
#include "roomba.h" 
#include "bulldozer.h" 
#include "kamikaze.h" 

using namespace std;
int main(){
srand(time(0));

World w;
w.initializeRobots();
w.runSimulation();

return 0;
}