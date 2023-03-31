//
//  ECCommand.h
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#ifndef ECCommand_h
#define ECCommand_h

#include <vector>
#include <string>

class ECTextDocument;
// ******************************************************
// Implement command design pattern

class ECCommand
{
public:
    virtual ~ECCommand() {}
    virtual void Execute() = 0;
    virtual void UnExecute() = 0;
};

// ******************************************************
// Implement command history

class ECCommandHistory
{
public:
    ECCommandHistory();
    virtual ~ECCommandHistory();
    bool Undo();
    bool Redo();
    void ExecuteCmd( ECCommand *pCmd );
    
private:
    // your code goes here
    std::vector<ECCommand *> listCmds;
    int curCmdIdx;

};


#include "ECTextDocument.h"
// Class ECCommandLower extends ECCommand
// class has pointer to the document
// class has the position and length of the text to be lowercased

class ECCommandLower : public ECCommand
{
public:
    ECCommandLower(ECTextDocument &docIn, int posIn, int lenIn) : doc(docIn), pos(posIn), len(lenIn) {}
    virtual ~ECCommandLower() {}
    virtual void Execute();
    virtual void UnExecute();

private:
    ECTextDocument &doc;
    int pos;
    int len;
};

class ECCommandUpper : public ECCommand
{
public:
    ECCommandUpper(ECTextDocument &docIn, int posIn, int lenIn) : doc(docIn), pos(posIn), len(lenIn) {}
    virtual ~ECCommandUpper() {}
    virtual void Execute();
    virtual void UnExecute();

private:
    ECTextDocument &doc;
    int pos;
    int len;
};

class ECCommandInsert : public ECCommand
{
public:
    ECCommandInsert(ECTextDocument &docIn, int posIn, const std::vector<char> &listCharsToInsIn) : doc(docIn), pos(posIn), listCharsToIns(listCharsToInsIn) {}
    virtual ~ECCommandInsert() {}
    virtual void Execute();
    virtual void UnExecute();

private:
    ECTextDocument &doc;
    int pos;
    std::vector<char> listCharsToIns;
};

class ECCommandRemove : public ECCommand
{
public:
    ECCommandRemove(ECTextDocument &docIn, int posIn, int lenToRemoveIn, std::vector<char> removed) : doc(docIn), pos(posIn), lenToRemove(lenToRemoveIn), listCharsRemoved(removed) {}
    virtual ~ECCommandRemove() {}
    virtual void Execute();
    virtual void UnExecute();

private:
    ECTextDocument &doc;
    int pos;
    int lenToRemove;
    std::vector<char> listCharsRemoved;
};

#endif /* ECCommand_h */