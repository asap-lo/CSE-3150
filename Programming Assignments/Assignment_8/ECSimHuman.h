//
//  ECSimHuman.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//  Human related definitions in campus simulation

#ifndef ECSimHuman_h
#define ECSimHuman_h
#include <string>
#include "ECSimOrganization.h"

//  Place all human related definitions here: ECSimStudent, ECSimEmployee, etc


// ***********************************************************
// Employee

class ECSimEmployee : public ECSimEntity
{
public:
    ECSimEmployee(int idEmployee);
    
    // payrate: amount paid per day. If not set, not getting paid
    void SetPayrate(int rate);  
    int Getpayrate() const;  
    //Event for employee to HR
    virtual void Event(ECSimHR &receiver);
    //Event for employee to DiningHall
    virtual void Event(ECSimDiningHall &receiver);
    //Event for employee to RecCenter
    virtual void Event(ECSimRecCenter &receiver);
    //Do nothing for employee to remaining entities
    virtual void Event(ECSimEntity &receiver) {};
    
private:
    int payrate;
};

// ***********************************************************
// Student

class ECSimStudent : public ECSimEntity
{
public:
    // each student must have a distinct id
    ECSimStudent(int idStudent);
    
    // Event for student to Bursar
    virtual void Event(ECSimBursar &receiver);
    // Event for student to DiningHall
    virtual void Event(ECSimDiningHall &receiver);
    // Event for student to RecCenter
    virtual void Event(ECSimRecCenter &receiver);
    // Event for student to everything else (do nothing)
    virtual void Event(ECSimEntity &receiver) {};
    // Your code goes here...
 
};

#endif /* ECSimHuman_h */
