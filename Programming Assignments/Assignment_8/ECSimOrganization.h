//
//  ECSimOrganization.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#ifndef ECSimOrganization_h
#define ECSimOrganization_h

//  Place simulation organization related code here...
//  Consider adding base class here...
class ECSimEntity
{
public:
    ECSimEntity(int id);
    virtual ~ECSimEntity();
    virtual void Paid(int amount);
    virtual void Charged(int amount);
    virtual void GetBalance() const;

private:
    int id;
    int balance;
};

class ECSimOrganization : public ECSimEntity
{
public:
    ECSimOrganization(int id);
    virtual ~ECSimOrganization();
    virtual void Paid(int amount);
    virtual void Charged(int amount);
    virtual void GetBalance() const;
    void SetBudgetForDay(int budget);
private:
    int id;
    int balance;
    int studentCost;
    int employeeCost;
    int budget;


};

// ***********************************************************
// University bursar office: handling enrollment related matters

class ECSimBursar 
{
public:
    // each organization has an unique ID
    ECSimBursar(int bid);
    
    // set tuition rate; same tuition for everyone; tuition is form the entire simulation period (say semester)
    void SetTuition(int tuitionIn);

    // your code goes here
    
};

// ***********************************************************
// Human resource (HR)

class ECSimHR 
{
public:
    // each organization has an unique ID
    ECSimHR( int tid );
    
    // your code goes here
};

// ***********************************************************
// Dining hall

class ECSimDiningHall 
{
public:
    // each organization has an unique ID
    ECSimDiningHall( int tid );
    
    // your code goes here
};

// ***********************************************************
// Rec center

class ECSimRecCenter  
{
public:
    // each organization has an unique ID
    ECSimRecCenter( int tid );
    
    // your code goes here
};

// ***********************************************************
// Library

class ECSimLibrary 
{
public:
    // each organization has an unique ID
    ECSimLibrary(int bid);
    
    // your code goes here
};

#endif /* ECSimOrganization_h */
