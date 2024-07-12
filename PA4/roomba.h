#ifndef ROOMBA_H
#define ROOMBA_H

#include<iostream>
#include "robots.h"
using namespace std;

class roomba : public Robot {
    static int roombaCounter;

public:
    roomba();
    int roombacounter();

    string getType() override;

    int getDamage() override;

    void setName()override;

};

#endif // ROOMBA_H
