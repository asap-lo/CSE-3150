//
//  ECSimTask2.cpp
//
//
//

#include "ECSimTask2.h"

ECMultiIntervalsTask::ECMultiIntervalsTask(const std::string &tid) : ECSimTask(tid)
{
}

void ECMultiIntervalsTask::AddInterval(int tmStart, int tmEnd)
{
    intervals.push_back(std::make_pair(tmStart, tmEnd));
}

bool ECMultiIntervalsTask::IsReadyToRun(int tick) const
{
    for(int i = 0; i < intervals.size(); i++)
    {
        if(tick >= intervals[i].first && tick <= intervals[i].second)
        {
            return true;
        }
    }
    return false;
}

bool ECMultiIntervalsTask::IsFinished(int tick) const
{
    bool b = false;
    for(int i = 0; i < intervals.size(); i++)
    {
        if(tick > intervals[i].second)
        {
            b = true;
        }
        else
        {
            b = false;
        }
    }
    return b;
}

ECHardIntervalTask::ECHardIntervalTask(const std::string &tid, int tmStartIn, int tmEndIn) : ECSimTask(tid), tmStart(tmStartIn), tmEnd(tmEndIn)
{
}

bool ECHardIntervalTask::IsReadyToRun(int tick) const
{
    return tick == tmStart;
}

bool ECHardIntervalTask::IsFinished(int tick) const
{
    return (tick > tmStart && this->GetTotRunTime() == 0) || tick > tmEnd;
}

ECConsecutiveIntervalTask::ECConsecutiveIntervalTask(const std::string &tid, int tmStart, int tmEnd) : ECSimTask(tid), tmStart(tmStart), tmEnd(tmEnd)
{
}

void ECConsecutiveIntervalTask::Run(int tick, int duration)
{
    ECSimTask::Run(tick, duration);
    tickPrev = tick;
}

void ECConsecutiveIntervalTask::Wait(int tick, int duration)
{
    ECSimTask::Wait(tick, duration);
    tickPrev = tick;
}

bool ECConsecutiveIntervalTask::IsReadyToRun(int tick) const
{
    return tick >= tmStart && tick <= tmEnd;
}

bool ECConsecutiveIntervalTask::IsFinished(int tick) const
{
    return tick >= tmEnd-1;
    if(waited && tick > tickPrev)
    {
        return true;
    }
    return tick > tmEnd;
}

ECPeriodicTask::ECPeriodicTask(const std::string &tid, int tmStart, int runLen, int sleepLen) : ECSimTask(tid), tmStart(tmStart), runLen(runLen), sleepLen(sleepLen)
{
}   

bool ECPeriodicTask::IsReadyToRun(int tick) const
{
    return tick >= tmStart && (tick - tmStart) % (runLen + sleepLen) < runLen;
}

bool ECPeriodicTask::IsFinished(int tick) const
{
    return false;
}