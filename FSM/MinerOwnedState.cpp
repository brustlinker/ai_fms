//
// Created by sun on 16/10/8.
//

#include "MinerOwnedState.h"
#include "Locations.h"
#include "Miner.h"
#include "EntityNames.h"
#include <iostream>
using namespace std;


EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
    static EnterMineAndDigForNugget instance;
    return &instance;
}


void EnterMineAndDigForNugget::Enter(Miner* pMiner)
{
    //如果不再金矿中
    if(pMiner->Location()!=goldmine)
    {
        cout<<"********"<<endl;
        cout<<"\n"<<GetNameOfEntity(pMiner->ID())<<":Walkin' to the goldmine";

        //移动到金矿中
        pMiner->ChangeLocation(goldmine);
    }
}

void EnterMineAndDigForNugget::Execute(Miner *pMiner)
{
    //采集一个金子
    pMiner->AddToGoldCarried(1);
    //增加疲劳
    pMiner->IncreaseFatigue();

    cout<<"********"<<endl;
    cout<<"\n"<<GetNameOfEntity(pMiner->ID())<<":Pickin' up a nugget";

    //采购了，就去银行存
    if(pMiner->PocketsFull())
    {
        pMiner->ChangeState(VisitBankAndDepositGold::Instance());
    }

    //渴了就来
    if(pMiner->Thirsty())
    {
        pMiner->ChangeState(QuenchThirst::Instance());
    }
}

void EnterMineAndDigForNugget::Exit(Miner *pMiner)
{
    cout<<"********"<<endl;
    cout<<"\n"<<GetNameOfEntity(pMiner->ID())<<":Ah'm leavin' the goldmine with mah pockets full o' sweet gold";

}



VisitBankAndDepositGold* VisitBankAndDepositGold::Instance()
{
    static VisitBankAndDepositGold instance;

    return &instance;
}


void VisitBankAndDepositGold::Enter(Miner* pMiner)
{

    if(pMiner->Location()!=bank)
    {
        cout<<"********"<<endl;
        cout<<"\n"<<GetNameOfEntity(pMiner->ID())<<":Goin' to the bank. Yes siree";
    }
}


void VisitBankAndDepositGold::Execute(Miner* pMiner)
{
    //把身上的钱都存在银行里
    pMiner->AddToWealth(pMiner->GoldCarried());
    pMiner->SetGoldCarried(0);

    cout<<"********"<<endl;
    cout<<"\n"<<GetNameOfEntity(pMiner->ID())<<":Depositing gold. Total savings now:"<<pMiner->Wealth() ;


    //条件转换

    //挣够了钱
    if(pMiner->Wealth() >= ComfortLevel) {
        cout << "********" << endl;
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << "WooHoo! Rich enough for now. Back home to mah li'lle lady";

        pMiner->ChangeState(GoHomeAndSleepTilRested::Instance());
    }
    //没挣够钱继续挖矿
    else
    {
        pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
    }
}

void VisitBankAndDepositGold::Exit(Miner* pMiner)
{

    if(pMiner->Location()!=bank)
    {
        cout<<"********"<<endl;
        cout<<"\n"<<GetNameOfEntity(pMiner->ID())<<":Leavin' the bank";
    }
}


GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
    static GoHomeAndSleepTilRested instance;

    return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner* pMiner)
{
    //不再自己的小棚子里
    if(pMiner->Location()!=shack)
    {
        cout<<"********"<<endl;
        cout<<"\n"<<GetNameOfEntity(pMiner->ID())<<":Walkin' home";
    }
}

void GoHomeAndSleepTilRested::Execute(Miner* pMiner)
{
    //如果不累，那么继续去挖矿
    if(!pMiner->Fatigued())
    {
        cout<<"********"<<endl;
        cout<<"\n"<<GetNameOfEntity(pMiner->ID())<<":What a God darn fantastic nap! Time to find more gold";

        pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
    }

    else
    {
        pMiner->DecreaseFatigue();
        cout<<"\n"<<GetNameOfEntity(pMiner->ID())<<":ZZZZ...";

    }
}

void GoHomeAndSleepTilRested::Exit(Miner* pMiner)
{
    cout<<"********"<<endl;
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the house";
}



QuenchThirst* QuenchThirst::Instance()
{
    static QuenchThirst instance;

    return &instance;
}

void QuenchThirst::Enter(Miner* pMiner)
{
    //如果不再酒店里，就走到酒店
    if (pMiner->Location() != saloon)
    {
        pMiner->ChangeLocation(saloon);

        cout<<"********"<<endl;
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Boy, ah sure is thusty! Walking to the saloon";
    }
}

void QuenchThirst::Execute(Miner* pMiner)
{
    //如果渴了就买一杯威士忌，然后去挖掘
    if (pMiner->Thirsty())
    {
        pMiner->BuyAndDrinkAWhiskey();

        cout<<"********"<<endl;
        cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "That's mighty fine sippin liquer";

        pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
    }

    else
    {
        cout<<"********"<<endl;
        cout << "\nERROR!\nERROR!\nERROR!";
    }
}

void QuenchThirst::Exit(Miner* pMiner)
{
    cout<<"********"<<endl;
    cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Leaving the saloon, feelin' good";
}