// humanic.h
#ifndef _HUMANIC_H
#define _HUMANIC_H

#include "robots.h"

class humanic : public Robot {
friend class world;
friend class optimusprime;
friend class robocop;

public:
    humanic(); 
    virtual string getType() override;
    virtual int getDamage() override;
};

#endif
