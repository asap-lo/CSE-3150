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
    tmStarts.push_back(tmStart);
    tmEnds.push_back(tmEnd);
}

bool ECMultiIntervalsTask::IsReadyToRun(int tick)
{
    for (int i = 0; i < tmStarts.size(); i++)
    {
        if (tick >= tmStarts[i] && tick <= tmEnds[i])
        {
            return true;
        }
    }
    return false;
}

bool ECMultiIntervalsTask::IsFinished(int tick)
{
    for (int i = 0; i < tmStarts.size(); i++)
    {
        if (tick >= tmStarts[i] && tick <= tmEnds[i])
        {
            return false;
        }
    }
    return true;
}