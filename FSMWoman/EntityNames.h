//
// Created by sun on 16/10/8.
//

#ifndef FSM_ENTITYNAMES_H
#define FSM_ENTITYNAMES_H

#include<iostream>

enum
{
    ent_Miner_Bob,
    ent_Elsa
};

inline std::string GetNameOfEntity(int n)
{
    switch (n) {
        case ent_Miner_Bob:
            return "Miner Bob";
        case ent_Elsa:
            return "Elsa";
        default:
            return "UNKNOW!";
    }
}


#endif //FSM_ENTITYNAMES_H
