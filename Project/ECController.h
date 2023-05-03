#include "ECTextViewImp.h"
#include "ECCommand.h"
#include "ECModel.h"
#include "ECObserver.h"
#include <iostream>
#include <vector>
#include <string>

#ifndef ECController_h
#define ECController_h

using namespace  std;

class ECController : public ECObserver
{
public:
    ECController(ECModel *model, ECTextViewImp *inputObserver, ECCommandHistory *commandHistory)
    {
        this->model = model;
        this->inputObserver = inputObserver;
        this->commandHistory = commandHistory;
        this->inputObserver->Attach(this);
    }
    virtual void Update();

private:
    ECModel *model;
    ECTextViewImp *inputObserverl
    ECCommandHistory *commandHistory;

};

#endif