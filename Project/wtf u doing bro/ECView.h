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

    void UpdateView(vector<string> &listRows, int x, int y);
    int GetWindowSize() { return viewImp->GetColNumInView(); };

private:
    ECTextViewImp *viewImp;
};

#endif