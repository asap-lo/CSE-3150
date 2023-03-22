//
//  ECSimHuman.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//  Human related definitions in campus simulation

#ifndef ECSimHuman_h
#define ECSimHuman_h
// Including the base class entity
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
    int GetPayrate() const;  
    
    // Your code goes here... 
    
private:
    ECSimEntity *human;
    int payrate;

};

// ***********************************************************
// Student

class ECSimStudent : public ECSimEntity
{
public:
    // each student must have a distinct id
    ECSimStudent(int idStudent);
    
    // Your code goes here...

private:
    ECSimEntity *human;

};

#endif /* ECSimHuman_h */
