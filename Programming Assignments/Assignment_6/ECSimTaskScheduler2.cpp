//
//  ECSimTaskScheduler2.cpp
//  
//
//

#include <vector>
#include <iostream>
using namespace std;

#include "ECSimTaskScheduler2.h"
#include "ECSimTask.h"

ECSimLWTFTaskScheduler :: ECSimLWTFTaskScheduler()
{
}

ECSimTask *ECSimLWTFTaskScheduler :: ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const
{
    // your code here
    if (listReadyTasks.size() > 0)
    {
        int maxWait = 0;
        int maxWaitIndex = 0;
        for (int i = 0; i < listReadyTasks.size(); i++)
        {
            if (listReadyTasks[i]->GetTotWaitTime() > maxWait)
            {
                maxWait = listReadyTasks[i]->GetTotWaitTime();
                maxWaitIndex = i;
            }
        }
        return listReadyTasks[maxWaitIndex];
    }
    else
    {
        return NULL;
    }
}

ECSimPriorityScheduler :: ECSimPriorityScheduler()
{
}

ECSimTask *ECSimPriorityScheduler :: ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const
{
    // your code here
    if (listReadyTasks.size() > 0)
    {
        int minPriority = 0;
        int minPriorityIndex = 0;
        for (int i = 0; i < listReadyTasks.size(); i++)
        {
            if (listReadyTasks[i]->GetPriority() < minPriority)
            {
                minPriority = listReadyTasks[i]->GetPriority();
                minPriorityIndex = i;
            }
        }
        return listReadyTasks[minPriorityIndex];
    }
    else
    {
        return NULL;
    }
}

ECSimRoundRobinTaskScheduler :: ECSimRoundRobinTaskScheduler()
{
}

ECSimTask *ECSimRoundRobinTaskScheduler :: ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const
{
    // your code here
    if (listReadyTasks.size() > 0)
    {
        int minSchedule = 1000;
        int minScheduleIndex = 0;
        for (int i = 0; i < listReadyTasks.size(); i++)
        {
            if (listReadyTasks[i]->GetTotRunTime() < minSchedule)
            {
                minSchedule = listReadyTasks[i]->GetTotRunTime();
                minScheduleIndex = i;
            }
        }
        return listReadyTasks[minScheduleIndex];
    }
    else
    {
        return NULL;
    }
}