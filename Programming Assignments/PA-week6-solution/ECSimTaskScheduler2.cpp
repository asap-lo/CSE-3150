//
//  ECSimTaskScheduler2.cpp
//  
//
//  Created by Yufeng Wu on 2/11/23.
//

#include <vector>
#include <algorithm>
#include <iterator>
#include <climits>
#include <iostream>
using namespace std;

#include "ECSimTaskScheduler2.h"
#include "ECSimTask.h"

//***********************************************************
// Longest wait-time first scheduler: choose the task that has waited the longest so far

ECSimLWTFTaskScheduler :: ECSimLWTFTaskScheduler()
{
}


// Choose from a list of tasks that are ready to run. Again, we use Lambda to shortern the code
ECSimTask * ECSimLWTFTaskScheduler :: ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const
{
    //
    ECSimTask *pres = NULL;
    int maxWait = -1;
    std::for_each( listReadyTasks.begin(), listReadyTasks.end(), [&](ECSimTask *px) { int wt = px->GetTotWaitTime(); if( wt > maxWait ) { maxWait = wt; pres = px;  }   }  );
    return pres;
}

//***********************************************************
// Priority-based scheduler. By default, each task has the same priority 0; this priorty can be set (the smaller the higher priority, as in Unix/Linux).

ECSimPriorityScheduler :: ECSimPriorityScheduler()
{
}

// Choose from a list of tasks that are ready to run
ECSimTask * ECSimPriorityScheduler :: ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const
{
    // Again use Lambda to shorten the code
    ECSimTask *pres = NULL;
    int priHigh = INT_MAX;
    std::for_each( listReadyTasks.begin(), listReadyTasks.end(), [&](ECSimTask *px) { int pri = px->GetPriority(); if( pri < priHigh ) { priHigh = pri; pres = px;  }   }  );
    return pres;
}

//***********************************************************
// Round-robin scheduler: the task having run the fewest in the past, get the highest priority

ECSimRoundRobinTaskScheduler :: ECSimRoundRobinTaskScheduler()
{
}


// Choose from a list of tasks that are ready to run
ECSimTask * ECSimRoundRobinTaskScheduler :: ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const
{
    ECSimTask *pres = NULL;
    int minNS = INT_MAX;
    std::for_each( listReadyTasks.begin(), listReadyTasks.end(), [&](ECSimTask *px) { int ns = GetScheduledTimeFor(px); if( ns < minNS ) { minNS = ns; pres = px;  }   }  );
    if( pres != NULL )
    {
        ECSimRoundRobinTaskScheduler *pthis = const_cast<ECSimRoundRobinTaskScheduler *>(this);
        pthis->IncTaskScheduledTime(pres);
    }
    return pres;
}

// get the number of a task has been scheduled before
int ECSimRoundRobinTaskScheduler :: GetScheduledTimeFor(ECSimTask *pTask) const
{
    auto it = mapTaskSchNums.find(pTask);
    if( it == mapTaskSchNums.end() )
    {
        return 0;
    }
    else
    {
        return it->second;
    }
}

// inc the number a task has been scheduled
void ECSimRoundRobinTaskScheduler :: IncTaskScheduledTime(ECSimTask *pTask)
{
    if( mapTaskSchNums.find(pTask) == mapTaskSchNums.end() )
    {
        mapTaskSchNums[pTask] = 0;
    }
    ++mapTaskSchNums[pTask];
}

