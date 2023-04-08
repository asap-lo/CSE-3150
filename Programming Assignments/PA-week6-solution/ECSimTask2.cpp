//
//  ECSimTask2.cpp
//  
//
//  Created by Yufeng Wu on 2/11/23.
//

#include "ECSimTask2.h"

//***********************************************************
// Multiple intervasl task: a task spans multiple intervals of time; otherwise it behaves just like single interval

ECMultiIntervalsTask :: ECMultiIntervalsTask(const std::string &tid) : ECSimTask(tid)
{
}

// Is task ready to run at certain time? tick: the current clock time (in simulation unit)
bool ECMultiIntervalsTask :: IsReadyToRun(int tick) const
{
    bool res = false;
    std::for_each( listIVs.begin(), listIVs.end(), [&res, tick](const std::pair<int,int> &pp) { if( pp.first <= tick && pp.second >= tick) res = true;  }  );
    return res;
}

// Is task complete at certain time? If so, scheduler may remove it from the list. tick the current clock time (in simulation unit)
bool ECMultiIntervalsTask :: IsFinished(int tick) const
{
    bool res = true;
    std::for_each( listIVs.begin(), listIVs.end(), [&res, tick](const std::pair<int,int> &pp) { if( pp.second >= tick) res = false;  }  );
    return res;
}

// Add an interval as one part
void ECMultiIntervalsTask :: AddInterval(int tmStart, int tmEnd)
{
    std::pair<int,int> pp(tmStart, tmEnd);
    listIVs.push_back(pp);
}

//***********************************************************
// One-shot task: a task spans a single interval [a,b] of time; this task has hard requirement: it must start at a and end at b. If this condition is not met, it just won't run at all!

ECHardIntervalTask :: ECHardIntervalTask(const std::string &tid, int tmStartIn, int tmEndIn) : ECSimTask(tid), tmStart(tmStartIn), tmEnd(tmEndIn), fMissed(false)
{
}

// Is task ready to run at certain time? tick: the current clock time (in simulation unit)
bool ECHardIntervalTask :: IsReadyToRun(int tick) const
{
    return fMissed == false && tick >=tmStart && tick <= tmEnd;
}

// Is task complete at certain time? If so, scheduler may remove it from the list. tick the current clock time (in simulation unit)
bool ECHardIntervalTask :: IsFinished(int tick) const
{
    // finished if it didn't start at the desired start time
    return fMissed || tick > tmEnd;
}

// Override Wait function s.t. if the wait period span the desired start time, then this task missed (cannot run any more)
void ECHardIntervalTask :: Wait(int tick, int duration)
{
    ECSimTask :: Wait(tick, duration);
    
    // Set miss if the wait duration spans the desired start time
    int wtEnd = tick + duration - 1;
    if( this->tmStart >= tick && this->tmStart <= wtEnd )
    {
        this->fMissed = true;
    }
}

//***********************************************************
// Consecutive interval task: a task spans a single interval [a,b] of time; this task, once start (can be anytime after time a, must run consecutively; if interrupted, it can no longer run

ECConsecutiveIntervalTask :: ECConsecutiveIntervalTask(const std::string &tid, int tmStartIn, int tmEndIn) : ECSimTask(tid), tmStart(tmStartIn), tmEnd(tmEndIn), tmFirstRun(-1), fMissed(false)
{
}

// Is task ready to run at certain time? tick: the current clock time (in simulation unit)
bool ECConsecutiveIntervalTask :: IsReadyToRun(int tick) const
{
    return fMissed == false && tick >=tmStart && tick <= tmEnd;
}

// Is task complete at certain time? If so, scheduler may remove it from the list. tick the current clock time (in simulation unit)
bool ECConsecutiveIntervalTask :: IsFinished(int tick) const
{
    return fMissed || tick > tmEnd;
}

// Run the task for some duration (usually 1, but can be more) starting from time tick
void ECConsecutiveIntervalTask :: Run(int tick, int duration)
{
    ECSimTask :: Run(tick, duration);
    
    if( tmFirstRun < 0 )
    {
        // remember the first run
        tmFirstRun = tick;
    }
}

// Override Wait function s.t. if the wait period span the desired start time, then this task missed (cannot run any more)
void ECConsecutiveIntervalTask :: Wait(int tick, int duration)
{
    ECSimTask :: Wait(tick, duration);
    
    if( tmFirstRun >= 0 )
    {
        fMissed = true;
    }
}
    
//***********************************************************
// Periodic task: a recurrent task that runs periodically of certain length

// tickStart: when to start this periodic task; runLen: how long to run this task each time; sleepLen: after it finishes one run, hong long it will sleep
ECPeriodicTask :: ECPeriodicTask(const std::string &tid, int tmStartIn, int runLenIn, int sleepLenIn) : ECSimTask(tid), tmStart(tmStartIn), runLen(runLenIn), sleepLen(sleepLenIn)
{
}

// Is task ready to run at certain time? tick: the current clock time (in simulation unit)
bool ECPeriodicTask :: IsReadyToRun(int tick) const
{
    // check if tick is within the intervals; use modulo to find out
    if( tick < tmStart )
    {
        return false;
    }
    int period = this->runLen + this->sleepLen;
    int tmMod = (tick - tmStart ) % period;
    return  tmMod < this->runLen;
}

// Is task complete at certain time? If so, scheduler may remove it from the list. tick the current clock time (in simulation unit)
bool ECPeriodicTask :: IsFinished(int tick) const
{
    // periodic task runs forever!
    return false;
}
