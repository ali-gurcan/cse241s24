#ifndef BULLDOZER_H
#define BULLDOZER_H

#include "robots.h"

class bulldozer : public Robot {
    static int bulldozerCounter;

public:
    bulldozer();
    std::string getType()  override;
    int bulldozercounter();
    int getDamage() override;
    void setName()override;
};

#endif 
