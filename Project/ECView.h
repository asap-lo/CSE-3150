#include "ECTextViewImp.h"
#include <iostream>
#include <vector>
#include <string>

using namespace  std;

#ifndef ECView_h
#define ECView_h

class ECView
{
public:
    ECView(ECTextViewImp *viewImp) { this->viewImp = viewImp; };

    UpdateView(vector<string> &listRows);

};

