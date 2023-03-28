//
//  ECCampusSimulator.h
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#ifndef ECCampusSimulator_h
#define ECCampusSimulator_h
#include <vector>
#include "ECSimOrganization.h"
/*
The following is a list of all events which should result in "BAD REQUEST" being thrown:

Sender:            Receiver:
Bursar              Employee
HR                   Dining Hall
HR                   HR
HR                   Rec Center
HR                   Student
Rec Center      Dining Hall
Rec Center      HR
Rec Center      Rec Center
Rec Center      Student
Rec Center      Employee
Dining Hall      Student
Dining Hall      Employee
Dining Hall      Dining Hall
Dining Hall      HR
Dining Hall      Rec Center
*/

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
    
    void AddSim(ECSimEntity *pe);
    //ECSimEntity GetEnt(int i) { return simEnts[i]; };
    
    // Your code here.../
private:
    std::vector<ECSimEntity> simEnts;
};

// ***********************************************************
// Simulator

class ECCampusSimulator : public ECCampusSimScript
{
public:
    ECCampusSimulator();
    ~ECCampusSimulator();
    void Simulate(const ECCampusSimScript &script);
    
    // Add a new sim item
    void AddSimItem(ECSimEntity *pe);
    //uhhhh

};

#endif /* ECCampusSimulator_h */
