//
//  ECCampusSimulator.cpp
//  
//
//  Created by Yufeng Wu on 2/21/23.
//

#include "ECCampusSimulator.h"
#include "ECSimOrganization.h"
#include "ECSimHuman.h"

// Your code here

ECCampusSimScript::ECCampusSimScript(){}

void ECCampusSimScript::EndofDay()
{
    // Do things at the end of the day
    

}

void ECCampusSimScript::AddSimEvt(int idSender, int idReceiver)
{
    // Add a simulation event
    // An event is from a sender (with type and id) to a receiver (with type and id)
    // Also evtCode is the code of the type of event between these two kinds of entities
    // For example, a student (sender) enrolls (event code 0) in univerisity (receiver)
    
    for(auto i : simEnts)
    {
        if(i->GetId() == idSender)
        {
            for(auto j : simEnts)
            {
                if(j->GetId() == idReceiver)
                {
                    i->Event(j);
                }
            }
        }
    }
}