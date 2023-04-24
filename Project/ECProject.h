#include "ECTextViewImp.h"
#include <iostream>
#include <vector>
#include <string>

using namespace  std;

//ECCommand basic interface
// class ECCommand
// {
// public:
//     virtual ~ECCommand() = 0;
//     virtual void Execute();
//     virtual void UnExecute();
// };
// class ECTextCommand : ECCommand
// {
// public:
//     ECTextCommand(string key, int line, int pos) 
//     { 
//         this->key = key; 
//         this->line = line;
//         this->pos = pos;
//     };
//     virtual void Execute();
//     virtual void UnExecute();
//     string GetKey() { return key; };
//     int GetLine() { return line; };
//     int GetPos() { return pos; };

// private:
//     string key;
//     int line;
//     int pos;
// };
// class ECAddCommand : public ECTextCommand
// {
// public:
//     virtual void Execute();
//     virtual void Unexecute();
// };

class ECView
{
public:
    ECView(ECTextViewImp *viewImp) { this->viewImp = viewImp; };
    void UpdateView(vector<string> &listRows);
    void SetCursorPos(int line, int pos) 
    { 
        viewImp->SetCursorY(line);
        viewImp->SetCursorX(pos);    
    };
    int GetCursorX() { return viewImp->GetCursorX(); };
    int GetCursorY() { return viewImp->GetCursorY(); };

private:
    ECTextViewImp *viewImp;
};

class ECModel
{
public:
    ECModel(ECView *view) 
    { 
        this->view = view; 
        listRows.push_back(""); 
    };
    void MoveCursor(int dx, int dy);
    void AddChar(string c, int line, int pos);
    void Return(int line, int pos);
    void Backspace(int line, int pos);
private:
    vector<string> listRows;
    ECView *view;
};


class ECController : public ECObserver
{
public:
    ECController(ECModel *model, ECTextViewImp *inputObserver) 
    { 
        this->model = model;
        this->inputObserver = inputObserver;
        inputObserver->Attach(this);
    };
    virtual void Update();

private:
    ECModel *model;
    ECTextViewImp *inputObserver;
};