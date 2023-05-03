#include "ECTextViewImp.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace  std;

#ifndef ECModel_h
#define ECModel_h

class ECModel
{
public:
    ECModel(ECview *view, string filename)
    {
        this->view = view;
        this->file(filename);
    }
    void MoveCursor(int dx, int dy);
    void AddChar(string c, int x, int y);
    void Backspace(int x, int y);
    void Return(int x, int y);

    int GetFileX() { return fileX; };
    int GetFileY() { return fileY; };

private:
    ECView *view;
    ofstream file;
    int fileX;
    int fileY;
};




#endif