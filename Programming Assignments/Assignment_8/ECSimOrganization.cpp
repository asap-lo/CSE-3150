//
//  ECSimOrganization.cpp
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECSimOrganization.h"

// Your code goes here

ECSimEntity::ECSimEntity(int id)
{
    id = id;
    balance = 0;
}
ECSimEntity::~ECSimEntity(){}

void ECSimEntity::Paid(int amount)
{
    balance += amount;
}
void ECSimEntity::Charged(int amount)
{
    balance -= amount;
}
int ECSimEntity::GetBalance() const
{
    return balance;
}
int ECSimEntity::GetId() const
{
    return id;
}

//Organization Constructor
ECSimOrganization::ECSimOrganization(int id) : ECSimEntity(id)
{
    organization = new ECSimEntity(id);
    budgetForDay = 0;
    employeeCost = 0;
    studentCost = 0;
}
//Organization destructor
ECSimOrganization::~ECSimOrganization()
{
    delete organization;
}