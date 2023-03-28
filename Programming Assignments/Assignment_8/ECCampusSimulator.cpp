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
//script constructor
ECCampusSimScript::ECCampusSimScript()
{}

void ECCampusSimScript::AddSimEvt(int idSender, int idReceiver)
{
    for(auto i : list)
    {
        if(i->GetID() == idSender)
        {
            for(auto j : list)
            {
                if(j->GetID() == idReceiver)
                {
                    i->Event(*j);
                }
            }
        }
    }
}