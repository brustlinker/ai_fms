//
// Created by sun on 16/10/8.
//

#include "BaseGameEntity.h"


int BaseGameEntity::m_iNextValidID = 0 ;

BaseGameEntity::~BaseGameEntity()
{
    //dtor
}


void BaseGameEntity::SetID(int val)
{
    assert((val >= m_iNextValidID) && "<BaseGameEntity::SetID>:不可用ID" );
    m_ID = val;

    m_iNextValidID = m_ID + 1;
}
