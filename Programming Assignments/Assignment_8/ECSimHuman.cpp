//
//  ECSimHuman.cpp
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECSimHuman.h"
#include <string>
#include "ECSimOrganization.h"
// Your code goes here


//ECSimEmployee constructor
ECSimEmployee::ECSimEmployee(int idEmployee) : ECSimEntity(idEmployee)
{
    payrate = 0;
}
//ECSimEmployee set payrate
void ECSimEmployee::SetPayrate(int rate)
{
    payrate = rate;
}
//ECSimEmployee get payrate
int ECSimEmployee::Getpayrate() const
{
    return payrate;
}
//ECSimEmployee event for employee to HR
void ECSimEmployee::Event(ECSimHR &receiver)
{
    receiver.Charged(payrate);
    Paid(payrate);
}
//ECSimEmployee event for employee to DiningHall
void ECSimEmployee::Event(ECSimDiningHall &receiver)
{
    Charged(receiver.Paid(10));
}
//ECSimEmployee event for employee to RecCenter
void ECSimEmployee::Event(ECSimRecCenter &receiver)
{
    Charged(receiver.Paid(20));
}

//ECSimStudent constructor
ECSimStudent::ECSimStudent(int idStudent) : ECSimEntity(idStudent)
{}
//ECSimStudent event for student to Bursar (pay tuition)
void ECSimStudent::Event(ECSimBursar &receiver)
{
    Charged(receiver.Paid(receiver.GetTuition()));
}
//ECSimStudent event for student to DiningHall
void ECSimStudent::Event(ECSimDiningHall &receiver)
{
    Charged(receiver.Paid(5));
}
//ECSimStudent event for student to RecCenter
void ECSimStudent::Event(ECSimRecCenter &receiver)
{
    Charged(receiver.Paid(10));
}
