#ifndef KAMIKAZE_H
#define KAMIKAZE_H

#include "robots.h"

class kamikaze : public Robot {
    static int kamikazeCounter;

public:
    kamikaze();

    std::string getType()  override;
    int kamikazecounter();

    int getDamage() override;
    void setName()override;
    ~kamikaze();

};

#endif  
