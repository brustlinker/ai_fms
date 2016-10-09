//
// Created by sun on 16/10/8.
//

#ifndef FSM_BASEGAMEENTITY_H
#define FSM_BASEGAMEENTITY_H

#include <cassert>

class BaseGameEntity {
private:
    //每个实体具有一个唯一的识别数字
    int m_ID;

    static int m_iNextValidID;


    void SetID(int val);

public:
    BaseGameEntity(int id)
    {
        SetID(id);
    }
    virtual ~BaseGameEntity();

    virtual void Update()=0;
    int     ID() const { return m_ID; }
};


#endif //FSM_BASEGAMEENTITY_H
