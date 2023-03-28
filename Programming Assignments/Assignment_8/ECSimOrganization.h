//
//  ECSimOrganization.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#ifndef ECSimOrganization_h
#define ECSimOrganization_h
#include <string>
//  Place simulation organization related code here...
//  Consider adding base class here...
class ECSimEntity;
class ECSimOrganization;
class ECSimBursar;
class ECSimHR;
class ECSimDiningHall;
class ECSimRecCenter;
class ECSimLibrary;
// ***********************************************************
// University bursar office: handling enrollment related matters

//base class entity
class ECSimEntity
{
public:
    // each entity has an unique ID
    ECSimEntity(int eid);
    int Paid(int amount)
    {
        balance += amount;
        return balance;
    };
    void Charged(int amount)
    {
        balance -= amount;
        if(balance < 0)
        {
            throw std::string("BANKRUPT");
        }
    };
    int GetBalance() { return balance; };
    int GetID() { return id; };
    virtual void Event(ECSimEntity &receiver);

private:
    int id;
    int balance;
};

#include "ECSimHuman.h"
class ECSimStudent;
class ECSimEmployee;
// organization class subclass of entity
class ECSimOrganization : public ECSimEntity
{
public:
    // each organization has an unique ID
    ECSimOrganization(int oid);
    // has budget
    void SetBudgetForDay(int budgetIn);
    int GetBudgetForDay() const {return budget;};
    // Any event from other organizations to bursar will be handled here
    virtual void Event(ECSimBursar &receiver);

private:
    int budget;

};
class ECSimBursar : public ECSimOrganization
{
public:
    // each organization has an unique ID
    ECSimBursar(int bid);
    
    // set tuition rate; same tuition for everyone; tuition is form the entire simulation period (say semester)
    void SetTuition(int tuitionIn);
    int GetTuition() const { return tuition; };
    // your code goes here
    // for bursar to Student, gve them 1000 money
    virtual void Event(ECSimStudent &receiver);
    // for bursar to Employee, throw string exception BAD REQUEST
    virtual void Event(ECSimEmployee &receiver) { throw std::string("BAD REQUEST"); };
    // for all other events, take all their money
    virtual void Event(ECSimEntity &receiver);
private:
    int tuition;

};

// ***********************************************************
// Human resource (HR)

class ECSimHR : public ECSimOrganization
{
public:
    // each organization has an unique ID
    ECSimHR( int tid );

    // Event from HR to Employee, give them 2000 money
    virtual void Event(ECSimEmployee &receiver);
    // Event from HR to Student, throw string exception BAD REQUEST
    virtual void Event(ECSimStudent &receiver) { throw std::string("BAD REQUEST"); };
    // Event from HR to Rec Center, throw string exception BAD REQUEST
    virtual void Event(ECSimRecCenter &receiver) { throw std::string("BAD REQUEST"); };
    // Event from HR to Dining Hall, throw string exception BAD REQUEST
    virtual void Event(ECSimDiningHall &receiver) { throw std::string("BAD REQUEST"); };
    // Event from HR to HR, throw string exception BAD REQUEST
    virtual void Event(ECSimHR &receiver) { throw std::string("BAD REQUEST"); };
    //otherwise do nothing
    virtual void Event(ECSimEntity &receiver) { };
};

// ***********************************************************
// Dining hall

class ECSimDiningHall : public ECSimOrganization
{
public:
    // each organization has an unique ID
    ECSimDiningHall( int did );

    // Do nothing for all events
    virtual void Event(ECSimEntity &receiver) { };    
};

// ***********************************************************
// Rec center

class ECSimRecCenter : public ECSimOrganization
{
public:
    // each organization has an unique ID
    ECSimRecCenter( int rid );

    // Do nothing for all events
    virtual void Event(ECSimEntity &receiver) { };    

};

// ***********************************************************
// Library

class ECSimLibrary : public ECSimOrganization
{
public:
    // each organization has an unique ID
    ECSimLibrary(int lid);
    
    // do nothing for all events
    virtual void Event(ECSimEntity &receiver) { };

};

#endif /* ECSimOrganization_h */
