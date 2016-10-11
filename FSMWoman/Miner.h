//
// Created by sun on 16/10/8.
//

#ifndef FSM_MINER_H
#define FSM_MINER_H

#include "BaseGameEntity.h"
#include "Locations.h"
#include "MinerOwnedState.h"


const int ComfortLevel  = 5;
const int MaxNuggets    = 3;
const int ThirstLevel   = 5;
const int TirednessThreshold = 5;




class State;

class Miner : public BaseGameEntity {
private:
    //状态指针
    State *m_pCurrentState;

    //矿工当前所处的位置
    location_type m_Location;

    //矿工的包中包含了多少块金块
    int m_iGoldCarried;

    //矿工在银行存了多少钱
    int m_iMoneyInBank;

    //价值越高，矿工越口渴
    int m_iThirst;

    //价值越高，矿工越累
    int m_iFatigue;

public:


    ~Miner();

    Miner(int ID);

    void Update();

    void ChangeState(State *pNewState);


    //下面都是一些get set 方法
    location_type Location() { return m_Location; };

    void ChangeLocation(const location_type loc) {
        m_Location = loc;
    }

    int GoldCarried() const { return m_iGoldCarried; }

    void SetGoldCarried(const int val) {
        m_iGoldCarried = val;
    }

    void AddToGoldCarried(const int val);

    bool PocketsFull() const {
        return m_iGoldCarried >= MaxNuggets;
    }

    bool Fatigued() const;

    void DecreaseFatigue() {
        m_iFatigue -= 1;
    }

    void IncreaseFatigue() {
        m_iFatigue += 1;
    }

    int Wealth() const { return m_iMoneyInBank; }
    void SetWealth(const int val) {
        m_iMoneyInBank = val;
    }
    void AddToWealth(const int val);

    bool Thirsty() const;
    void BuyAndDrinkAWhiskey()
    {
        m_iThirst = 0;
            m_iMoneyInBank -= 2;
    }
};




#endif //FSM_MINER_H
