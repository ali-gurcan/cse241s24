#ifndef OPTIMUSPRIME_H
#define OPTIMUSPRIME_H

#include<iostream>
#include<string>
#include"humanic.h"

class optimusprime:public humanic
{
private:
   static int optimusprimeCounter;
public:
    optimusprime();
    int optimusprimecounter();
    string getType() override;
    int getDamage() override;
    void setName() override;
    ~optimusprime();
};


#endif