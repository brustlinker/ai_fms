//
// Created by sun on 16/10/11.
//

#ifndef FSMWOMAN_MINERSWIFE_H
#define FSMWOMAN_MINERSWIFE_H


#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Locations.h"
#include "MinersWifeOwnedStates.h"

class MinersWife : public BaseGameEntity{
private:
    StateMachine<MinersWife>* m_pStateMachine;
    location_type             m_Location;

public:
    MinersWife(int id):BaseGameEntity(id),m_Location(shack)
    {
        m_pStateMachine = new StateMachine<MinersWife>(this);

        m_pStateMachine ->SetCurrentState(DoHouseWork::Instance());

        m_pStateMachine ->SetGlobalState(WifesGlobalState::Instance());
    }

    //new 与delte成对出现
    ~MinersWife(){delete m_pStateMachine;}

    void Update();

    StateMachine<MinersWife>* GetFSM() const
    {
        return m_pStateMachine;
    }

    location_type Location() const
    {
        return m_Location;
    }

    void ChangeLocation(const location_type loc)
    {
        m_Location = loc;
    }

};


#endif //FSMWOMAN_MINERSWIFE_H
