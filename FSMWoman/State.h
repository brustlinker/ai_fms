//
// Created by sun on 16/10/8.
//

#ifndef FSM_STATE_H
#define FSM_STATE_H

class Miner;

class State
{
public:
    //virtual ~State();
    virtual void Enter( Miner* )=0;
    //每一个更新步骤这个被矿工更新函数调用
    virtual void Execute( Miner* )=0;
    //当状态推出时执行这个
    virtual void Exit( Miner* )=0;

};

#endif //FSM_STATE_H
