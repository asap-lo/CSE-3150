//
//  ECCampusSimulator.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#ifndef ECCampusSimulator_h
#define ECCampusSimulator_h
#include <vector>

// ***********************************************************
// Simulation script: a sequence of events to simulate

class ECCampusSimScript
{
public:
    ECCampusSimScript();
    // Mark the end of a day; unitl calling it again, any events before are the current day
    void EndofDay();
    // Add a simulation event. An event is from a sender (with type and id) to a receiver (with type and id). Also evtCode is the code of the type of event between these two kinds of entities. For example, a student (sender) enrolls (event code 0) in univerisity (receiver)
    void AddSimEvt(int idSender, int idReceiver);
    void AddToList(ECSimEntity *pe);
    // Your code here...
private:
    std::vector<ECSimEntity *> list;
};

// ***********************************************************
// Simulator

class ECCampusSimulator
{
public:
    ECCampusSimulator();
    ~ECCampusSimulator();
    void Simulate(const ECCampusSimScript &script);
    
    // Add a new sim item
    void AddSimItem(ECSimEntity *pe);

    // Your code goes here..

};

#endif /* ECCampusSimulator_h */
