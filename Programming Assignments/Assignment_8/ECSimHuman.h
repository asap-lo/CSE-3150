//
//  ECSimHuman.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//  Human related definitions in campus simulation

#ifndef ECSimHuman_h
#define ECSimHuman_h

//  Place all human related definitions here: ECSimStudent, ECSimEmployee, etc


// ***********************************************************
// Employee

class ECSimEmployee 
{
public:
    ECSimEmployee(int idEmployee);
    
    // payrate: amount paid per day. If not set, not getting paid
    void SetPayrate(int rate);  
    int Getpayrate() const;  
    
    // Your code goes here... 
    
};

// ***********************************************************
// Student

class ECSimStudent 
{
public:
    // each student must have a distinct id
    ECSimStudent(int idStudent);
    
    // Your code goes here...

private:
    int idStudent;
    int balance;
};

#endif /* ECSimHuman_h */
