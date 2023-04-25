#include "ECTextViewImp.h"
#include <iostream>
#include <vector>
#include <string>

using namespace  std;


class ECCommandHistory;
class ECTextCommand;

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
    vector<string> GetListRows() { return listRows; };
private:
    vector<string> listRows;
    ECView *view;
};


class ECController : public ECObserver
{
public:
    ECController(ECModel *model, ECTextViewImp *inputObserver, ECCommandHistory *commandHistory) 
    { 
        this->model = model;
        this->inputObserver = inputObserver;
        this->commandHistory = commandHistory;
        inputObserver->Attach(this);
    };
    virtual void Update();

private:
    ECModel *model;
    ECTextViewImp *inputObserver;
    ECCommandHistory *commandHistory;
};


// ECCommand basic interface
class ECTextCommand
{
public:
    ECTextCommand(string key, int line, int pos, ECModel *model) 
    { 
        this->key = key; 
        this->line = line;
        this->pos = pos;
        this->model = model;
    };
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
    string GetKey() { return key; };
    int GetLine() { return line; };
    int GetPos() { return pos; };
    ECModel *GetModel() { return model; };

private:
    ECModel *model;
    string key;
    int line;
    int pos;
};
class ECAddCommand : public ECTextCommand
{
public:
    ECAddCommand(string key, int line, int pos, ECModel *model) : ECTextCommand(key, line, pos, model) { };
    virtual void Execute();
    virtual void UnExecute();
};
class ECRemoveCommand : public ECTextCommand
{
public:
    ECRemoveCommand(string key, int line, int pos, ECModel *model, bool lineDeleted) : ECTextCommand(key, line, pos, model), lineDeleted(lineDeleted) { };
    virtual void Execute();
    virtual void UnExecute();
private:
    bool lineDeleted;
};
class ECReturnCommand : public ECTextCommand
{
public:
    ECReturnCommand(string key, int line, int pos, ECModel *model) : ECTextCommand(key, line, pos, model) { };
    virtual void Execute();
    virtual void UnExecute();
};

class ECCommandHistory
{
public:
    ECCommandHistory() { index = 0; };
    int GetIndex() { return index; };
    //  ECTextCommand *GetCommand(int index) { return commands[index]; };
    void AddCommand(ECTextCommand *command);
private:
    vector<ECTextCommand *> commands;
    int index;
};
