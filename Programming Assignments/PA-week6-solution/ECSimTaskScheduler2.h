//
//  ECSimTaskScheduler2.h
//  
//
//  Created by Yufeng Wu on 2/11/23.
//

#ifndef ECSimTaskScheduler2_h
#define ECSimTaskScheduler2_h

#include <map>
#include <vector>

#include "ECSimTaskScheduler.h"

// Now define your new schedulers here...

//***********************************************************
// Longest wait-time first scheduler: choose the task that has waited the longest so far; break ties by the order of requests receiving
class ECSimLWTFTaskScheduler : public ECSimTaskScheduler
{
public:
    ECSimLWTFTaskScheduler();
    
protected:
    // Choose from a list of tasks that are ready to run
    virtual ECSimTask *ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const;
};

//***********************************************************
// Priority-based scheduler. By default, each task has the same priority 0; this priorty can be set (the smaller the higher priority, as in Unix/Linux).
class ECSimPriorityScheduler : public ECSimTaskScheduler
{
public:
    ECSimPriorityScheduler();
    
protected:
    // Choose from a list of tasks that are ready to run
    virtual ECSimTask *ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const;
};

//***********************************************************
// Round-robin scheduler: the task having run the fewest in the past, get the highest priority
class ECSimRoundRobinTaskScheduler : public ECSimTaskScheduler
{
public:
    ECSimRoundRobinTaskScheduler();
    
protected:
    // Choose from a list of tasks that are ready to run
    virtual ECSimTask *ChooseTaskToSchedule(const std::vector<ECSimTask *> &listReadyTasks) const;
    
private:
    // get the number of a task has been scheduled before
    int GetScheduledTimeFor(ECSimTask *pTask) const;
    // inc the number a task has been scheduled
    void IncTaskScheduledTime(ECSimTask *pTask);
    
    // keep track which task has been picked for schedluing
    std::map<ECSimTask *, int> mapTaskSchNums;
};


#endif /* ECSimTaskScheduler2_h */
