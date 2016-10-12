//
// Created by sun on 16/10/11.
//

#ifndef FSMWOMAN_MINERSWIFEOWNEDSTATES_H
#define FSMWOMAN_MINERSWIFEOWNEDSTATES_H

#include "State.h"
#include "EntityNames.h"
#include <iostream>

using namespace std;

class MinersWife;



class WifesGlobalState:public State<MinersWife> {
private:
    WifesGlobalState(){}

    WifesGlobalState(const WifesGlobalState&);

    WifesGlobalState& operator=(const WifesGlobalState&);

public:

    static WifesGlobalState* Instance();

    virtual void Enter(MinersWife* wife){}

    virtual void Execute(MinersWife* wife);

    virtual void Exit(MinersWife* wife){}
};


class DoHouseWork:public State<MinersWife>
{
private:
    DoHouseWork(){}

    DoHouseWork(const DoHouseWork&);

    DoHouseWork&operator=(const DoHouseWork&);

public:
    static DoHouseWork* Instance();

    virtual void Enter(MinersWife* wife);

    virtual void Execute(MinersWife* wife);

    virtual void Exit(MinersWife* wife);
};

class VisitBathroom : public State<MinersWife>
{
private:

    VisitBathroom(){}

    //copy ctor and assignment should be private
    VisitBathroom(const VisitBathroom&);
    VisitBathroom& operator=(const VisitBathroom&);

public:

    static VisitBathroom* Instance();

    virtual void Enter(MinersWife* wife);

    virtual void Execute(MinersWife* wife);

    virtual void Exit(MinersWife* wife);

};


#endif //FSMWOMAN_MINERSWIFEOWNEDSTATES_H
