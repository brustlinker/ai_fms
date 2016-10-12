#include <iostream>
#include "Miner.h"
#include "MinersWife.h"
#include "EntityNames.h"
#include "unistd.h"

int main() {
    Miner Bob(ent_Miner_Bob);
    MinersWife Elsa(ent_Elsa);

    for(int i=0;i<20;i++)
    {
        //Bob.Update();
        Elsa.Update();
        sleep(8);
    }
    //PressAnyKeyToContinue();
    return 0;
}