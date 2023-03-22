//
//  ECSimHuman.cpp
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECSimHuman.h"

// Your code goes here


//Student Constructor
ECSimStudent::ECSimStudent(int idStudent) : ECSimEntity(idStudent)
{
    human = new ECSimEntity(idStudent);
}
//Student destructor
ECSimStudent::~ECSimStudent()
{
    delete human;
}

//Employee Constructor
ECSimEmployee::ECSimEmployee(int idEmployee) : ECSimEntity(idEmployee)
{
    human = new ECSimEntity(idEmployee);
}
//Employee destructor
ECSimEmployee::~ECSimEmployee()
{
    delete human;
}
void ECSimEmployee::SetPayrate(int rate)
{
    payrate = rate;
}
int ECSimEmployee::GetPayrate() const
{
    return payrate;
}