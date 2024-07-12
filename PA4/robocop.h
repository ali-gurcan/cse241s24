#ifndef ROBOCOP_H
#define ROBOCOP_H

#include "humanic.h"

class robocop : public humanic {
static int robocopCounter;
public:
    robocop();
    
    int robocopcounter();

    std::string getType()  override;
    int getDamage() override;
    void setName() override;

};

#endif // ROBOCOP_H