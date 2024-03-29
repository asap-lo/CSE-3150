//
//  ECSimTask3.cpp
//  
//

#include "ECSimTask3.h"
#include <iostream>
using namespace std;

//***********************************************************
// Basic task
//***********************************************************

//***********************************************************
// Interval task: a single interval.
// YW: you shouldn't need to change this class!

ECSimIntervalTask :: ECSimIntervalTask(const std::string &tidIn, int tmStartIn, int tmEndIn) : tid(tidIn), tmStart(tmStartIn), tmEnd(tmEndIn), tmTotWait(0), tmTotRun(0)
{
}

// Is task ready to run at certain time? tick: the current clock time (in simulation unit)
bool ECSimIntervalTask :: IsReadyToRun(int tick) const
{
    return tick >= tmStart && tick <= tmEnd;
}

// Is task complete at certain time? If so, scheduler may remove it from the list. tick the current clock time (in simulation unit)
bool ECSimIntervalTask :: IsFinished(int tick) const
{
    return tick > tmEnd;
}


//***********************************************************
// Consecutive task: a task that can early abort

ECSimConsecutiveTask :: ECSimConsecutiveTask(ECSimTask *pTask) 
{
    this->pTask = pTask;
    tmFirstRun = -1;
    abort = false;
}

// your code here

void ECSimConsecutiveTask :: Run(int tick, int duration)
{
    pTask->Run(tick, duration);
    if ( tmFirstRun < 0 )
    {
        tmFirstRun = tick;
    }
}

void ECSimConsecutiveTask :: Wait(int tick, int duration)
{
    pTask->Wait(tick, duration);

    if(tmFirstRun >= 0)
    {
        abort = true;
    }
}

bool ECSimConsecutiveTask :: IsAborted(int tick) const
{
    return abort;
}

bool ECSimConsecutiveTask :: IsFinished(int tick) const
{
    return pTask->IsFinished(tick) || abort;
}


//***********************************************************
// Periodic task: a task that can early abort

ECSimPeriodicTask :: ECSimPeriodicTask(ECSimTask *pTask, int lenSleep) 
{
    this->pTask = pTask;
    this->lenSleep = lenSleep;

}

// your code here



//***********************************************************
// Task with a deadline to start: a task that must start by some time; otherwise terminate

ECSimStartDeadlineTask :: ECSimStartDeadlineTask(ECSimTask *pTask, int tmStartDeadlineIn) 
{
    this->pTask = pTask;
    deadline = tmStartDeadlineIn;
    start = -1;
    abort = false;

}

bool ECSimStartDeadlineTask :: IsReadyToRun(int tick) const
{
    return pTask->IsReadyToRun(tick) && tick < deadline;
}

void ECSimStartDeadlineTask :: Run(int tick, int duration)
{
    if ( tick > deadline && start == -1)
    {
        abort = true;
    }
    else 
    {
        start = tick;
        pTask->Run(tick, duration);
    }
}

void ECSimStartDeadlineTask :: Wait(int tick, int duration)
{
    if ( tick > deadline && start == -1)
    {
        abort = true;
    }
    else 
    {
        pTask->Wait(tick, duration);
    }
}


// your code here

//***********************************************************
// Task must end by some fixed time click: this is useful e.g. when a task is periodic

ECSimEndDeadlineTask :: ECSimEndDeadlineTask(ECSimTask *pTask, int tmEndDeadlineIn) 
{
}

void ECSimEndDeadlineTask :: Run(int tick, int duration)
{
    if ( tick + duration > deadline )
    {
        abort = true;
    }
    else 
    {
        pTask->Run(tick, duration);
    }
}

// your code here

//***********************************************************
// Composite task: contain multiple sub-tasks

ECSimCompositeTask :: ECSimCompositeTask(const std::string &tidIn) 
{
    tid = tidIn;
}

std::string ECSimCompositeTask :: GetId() const
{
    return tid;
}

void ECSimCompositeTask :: AddSubtask(ECSimTask *pTask)
{
    subtasks.push_back(pTask);
}

bool ECSimCompositeTask :: IsReadyToRun(int tick) const
{
    for ( int i = 0; i < subtasks.size(); i++ )
    {
        if ( subtasks[i]->IsReadyToRun(tick) )
        {
            return true;
        }
    }
    return false;
}

bool ECSimCompositeTask :: IsFinished(int tick) const
{
    for ( int i = 0; i < subtasks.size(); i++ )
    {
        if ( subtasks[i]->IsFinished(tick) )
        {
            return true;
        }
    }
    return false;
}

// your code here
