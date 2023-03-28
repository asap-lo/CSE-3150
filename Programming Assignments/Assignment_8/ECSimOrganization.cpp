//
//  ECSimOrganization.cpp
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECSimOrganization.h"

// Your code goes here

//ECSimEntity constructor
ECSimEntity::ECSimEntity(int eid)
{
    id = eid;
    balance = 0;
}

//ECSimOrganization constructor
ECSimOrganization::ECSimOrganization(int oid) : ECSimEntity(oid)
{
    budget = 0;
}
void ECSimOrganization::SetBudgetForDay(int budgetIn)
{
    budget = budgetIn;
}
void ECSimOrganization::Event(ECSimBursar &receiver)
{
    budget += receiver.budget;
}

//ECSimBursar constructor'
ECSimBursar::ECSimBursar(int bid) : ECSimOrganization(bid)
{
    tuition = 0;
}
//ECSimBursar event
void ECSimBursar::Event(ECSimStudent &receiver)
{
    Charged(receiver.Paid(1000));
}
//ECSimBursar event for all ent
void ECSimBursar::Event(ECSimEntity &receiver)
{
    receiver.Charged(Paid(receiver.GetBalance()));
}

//ECSimHR constructor
ECSimHR::ECSimHR(int hid) : ECSimOrganization(hid) {}
//ECSimHR event from HR to Employee
void ECSimHR::Event(ECSimEmployee &receiver)
{
    Charged(receiver.Paid(1000));
}

//ECSimDiningHall constructor
ECSimDiningHall::ECSimDiningHall(int did) : ECSimOrganization(did) {}

//ECSimRecCenter constructor
ECSimRecCenter::ECSimRecCenter(int rid) : ECSimOrganization(rid) {}

//ECSimLibrary constructor
ECSimLibrary::ECSimLibrary(int lid) : ECSimOrganization(lid) {}
