#include <iostream>
#include "Miner.h"
#include "EntityNames.h"
#include "unistd.h"

int main() {
    Miner miner(ent_Miner_Bob);

    for(int i=0;i<20;i++)
    {
        miner.Update();
        sleep(8);
    }
    //PressAnyKeyToContinue();
    return 0;
}