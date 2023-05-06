#include "ECTextViewImp.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace  std;


class ECCommandHistory;
class ECTextCommand;

class ECView
{
public:
    ECView(ECTextViewImp *viewImp) 
    { 
        this->viewImp = viewImp; 
        try
        {
            keywordFile.open("keywords.txt");
            string line;
            while(getline(keywordFile, line))
            {
                keywords.push_back(line);
            }
            keywordFile.close();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        
    };
    void UpdateView(vector<string> &listRows, int x, int y);
    void SetCursorPos(int line, int pos);
    int GetCursorX() { return viewImp->GetCursorX(); };
    int GetCursorY() { return viewImp->GetCursorY(); };
    int GetColNumInView() { return viewImp->GetColNumInView(); };
    int GetRowNumInView() { return viewImp->GetRowNumInView(); };
private:
    ECTextViewImp *viewImp;
    ifstream keywordFile;
    vector<string> keywords;
};

class ECModel
{
public:
    ECModel(ECView *view, string filename) 
    { 
        this->view = view; 
        this->filename = filename;
        ofstream newFile(filename, ios::app);
        newFile << "";
        listRows.push_back("");
        try
        {
            file.open(filename);
            string line;
            while(getline(file, line))
            {
                listRows.push_back(line);
            }
            file.close();
        }
        catch(const std::exception e)
        {
            cout << e.what() << endl;
            
        }
        //outfile.open(filename);
        //add every line of file to listrows
        newFile.close();
        file.close();
        view->UpdateView(listRows, 0, 0);
        x = 0;
        y = 0;
    };
    void LoadFile();
    void MoveCursor(int dx, int dy);
    void AddChar(string c);
    void Return();
    void Backspace();
    int GetCursorX() { return x; };
    int GetCursorY() { return y; };
    void WriteToFile();
    vector<string> GetListRows() { return listRows; };
    void SetListRows(vector<string> temp) 
    {
        listRows = temp;
        view->UpdateView(listRows, 0, y);
    };
private:
    vector<string> listRows;
    ifstream file;
    ofstream outfile;
    string filename;
    ECView *view;
    int x;
    int y;
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
    bool command = true;
    ECTextViewImp *inputObserver;
    ECCommandHistory *commandHistory;
};


// ECCommand basic interface
class ECTextCommand
{
public:
    ECTextCommand(string key, ECModel *model) 
    { 
        this->key = key; 
        this->model = model;
    };
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
    string GetKey() { return key; };
    ECModel *GetModel() { return model; };

private:
    ECModel *model;
    string key;
};
class ECAddCommand : public ECTextCommand
{
public:
    ECAddCommand(string key, ECModel *model) : ECTextCommand(key, model) { };
    virtual void Execute();
    virtual void UnExecute();
};
class ECRemoveCommand : public ECTextCommand
{
public:
    ECRemoveCommand(string key, ECModel *model, bool lineDeleted) : ECTextCommand(key, model), lineDeleted(lineDeleted) { };
    virtual void Execute();
    virtual void UnExecute();
private:
    bool lineDeleted;
};
class ECReturnCommand : public ECTextCommand
{
public:
    ECReturnCommand(string key, ECModel *model) : ECTextCommand(key, model) { };
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
    void UndoAll(ECModel *model);
    void RedoAll(ECModel *model);
    void ClearCommands() { commands.clear(); };
    void SetTemp(vector<string> temp) { this->temp = temp; };
private:
    vector<ECTextCommand *> commands;
    int index;
    vector<string> temp;
};
