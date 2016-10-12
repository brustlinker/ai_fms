//
// Created by sun on 16/10/11.
//

#include "MinersWifeOwnedStates.h"
#include "MinersWife.h"

WifesGlobalState* WifesGlobalState::Instance()
{
    static WifesGlobalState instance;

    return &instance;
}

void WifesGlobalState::Execute(MinersWife *wife)
{
    float ran = 1.0 * rand() /RAND_MAX;
    if(ran<0.1)
    {

        wife->GetFSM()->ChangeState(VisitBathroom::Instance());

    }
}

DoHouseWork* DoHouseWork::Instance()
{
    static DoHouseWork instance;

    return &instance;
}


void DoHouseWork::Enter(MinersWife* wife)
{

}


void DoHouseWork::Execute(MinersWife* wife)
{
    //反正都是干家务
    //int num = RandInt(0,2);
    int num = 0;
    switch(num)
    {
        case 0:

            cout << "\n" << GetNameOfEntity(wife->ID()) << ": Moppin' the floor";

            break;

        case 1:

            cout << "\n" << GetNameOfEntity(wife->ID()) << ": Washin' the dishes";

            break;

        case 2:

            cout << "\n" << GetNameOfEntity(wife->ID()) << ": Makin' the bed";

            break;
    }
}


void DoHouseWork::Exit(MinersWife* wife)
{

}


VisitBathroom* VisitBathroom::Instance()
{
    static VisitBathroom instance;

    return &instance;
}

void VisitBathroom::Enter(MinersWife* wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Walkin' to the can. Need to powda mah pretty li'lle nose";
}


void VisitBathroom::Execute(MinersWife* wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Ahhhhhh! Sweet relief!";

    wife->GetFSM()->RevertToPrevisouState();
}



void VisitBathroom::Exit(MinersWife* wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Leavin' the Tiolet";
}