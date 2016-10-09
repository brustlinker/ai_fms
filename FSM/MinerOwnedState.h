//
// Created by sun on 16/10/8.
//

#ifndef FSM_MINEROWNEDSTATE_H
#define FSM_MINEROWNEDSTATE_H

#include "State.h"

class Miner;

class EnterMineAndDigForNugget:public State
{
private:
    EnterMineAndDigForNugget(){}

    EnterMineAndDigForNugget(const EnterMineAndDigForNugget&);

    EnterMineAndDigForNugget&operator = (const EnterMineAndDigForNugget&);

public:
    static EnterMineAndDigForNugget* Instance();

    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);

};


class VisitBankAndDepositGold: public State
{
private:
    VisitBankAndDepositGold(){}

    VisitBankAndDepositGold(const VisitBankAndDepositGold&);

    VisitBankAndDepositGold& operator=(const VisitBankAndDepositGold&);

public:
    static VisitBankAndDepositGold* Instance();
    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);
};


class GoHomeAndSleepTilRested:public State
{
private:
    GoHomeAndSleepTilRested(){}
    GoHomeAndSleepTilRested(const GoHomeAndSleepTilRested&);
    GoHomeAndSleepTilRested&operator=(const GoHomeAndSleepTilRested&);

public:
    static GoHomeAndSleepTilRested* Instance();
    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);
};


class QuenchThirst:public State
{
private:
    QuenchThirst(){}

    QuenchThirst(const QuenchThirst&);
    QuenchThirst&operator=(const QuenchThirst&);

public:
    static QuenchThirst* Instance();
    virtual void Enter(Miner* miner);
    virtual void Execute(Miner* miner);
    virtual void Exit(Miner* miner);

};


#endif //FSM_MINEROWNEDSTATE_H