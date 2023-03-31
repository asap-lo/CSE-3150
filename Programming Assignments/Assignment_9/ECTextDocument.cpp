//
//  ECTextDocument.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECTextDocument.h"
#include <iostream>
#include <cctype>
using namespace std;

// **********************************************************
// Commands

// your code goes here 



// **********************************************************
// Controller for text document

ECTextDocumentCtrl :: ECTextDocumentCtrl(ECTextDocument &docIn) : doc(docIn), cmdHistory()
{
}

ECTextDocumentCtrl :: ~ECTextDocumentCtrl()
{
}

void ECTextDocumentCtrl :: InsertTextAt(int pos, const std::vector<char> &listCharsToIns)
{
  ECCommand *pCmd = new ECCommandInsert(doc, pos, listCharsToIns);
  
  cmdHistory.ExecuteCmd(pCmd);
  for(auto ch : listCharsToIns)
  {
    doc.InsertCharAt(pos, ch);
    pos++;
  }
}

void ECTextDocumentCtrl :: RemoveTextAt(int pos, int lenToRemove)
{
  
  vector<char> removedChars = {};
  for(int i = 0; i < lenToRemove; i++)
  {
    
    removedChars.push_back(doc.GetCharAt(pos));
    doc.RemoveCharAt(pos);
  }
  //print removedChars
  
  ECCommand *pCmd = new ECCommandRemove(doc, pos, lenToRemove, removedChars);
  cmdHistory.ExecuteCmd(pCmd);

}

void ECTextDocumentCtrl :: CapTextAt(int pos, int lenToCap)
{
  ECCommand *pCmd = new ECCommandUpper(doc, pos, lenToCap);
  cmdHistory.ExecuteCmd(pCmd);
  for(int i = 0; i < lenToCap; i++)
  {
    doc.CapCharAt(pos);
    pos++;
  }
}

void ECTextDocumentCtrl :: LowerTextAt(int pos, int lenToLower)
{
  ECCommand *pCmd = new ECCommandLower(doc, pos, lenToLower);
  cmdHistory.ExecuteCmd(pCmd);
  for(int i = 0; i < lenToLower; i++)
  {
    doc.LowerCharAt(pos);
    pos++;
  }
}

bool ECTextDocumentCtrl :: Undo()
{
  return cmdHistory.Undo();
}

bool ECTextDocumentCtrl :: Redo()
{
  return cmdHistory.Redo();
}

// **********************************************************
// Document for text document

// Constructor
ECTextDocument :: ECTextDocument() : docCtrl(*this)
{
}

ECTextDocument :: ~ECTextDocument()
{
}

ECTextDocumentCtrl & ECTextDocument :: GetCtrl()
{
    return docCtrl;
}

char ECTextDocument :: GetCharAt(int pos) const
{
    return listChars[pos];
}

void ECTextDocument :: InsertCharAt(int pos, char ch)
{
  // guard against invalid position
  if (pos < 0 || pos > listChars.size())
  {
    cout << "Invalid position to insert character" << endl;
    return;
  }
  listChars.insert(listChars.begin() + pos, ch);
}

void ECTextDocument :: RemoveCharAt(int pos)
{
  // guard against invalid position
  if (pos < 0 || pos >= listChars.size())
  {
    cout << "Invalid position to remove character" << endl;
    return;
  }
  listChars.erase(listChars.begin() + pos);
}

void ECTextDocument :: CapCharAt(int pos)
{
  // guard against invalid position
  if (pos < 0 || pos >= listChars.size())
  {
    cout << "Invalid position to capitalize character" << endl;
    return;
  }
  listChars[pos] = toupper(listChars[pos]);

}

void ECTextDocument :: LowerCharAt(int pos)
{
  // guard against invalid position
  if (pos < 0 || pos >= listChars.size())
  {
    cout << "Invalid position to lowercase character" << endl;
    return;
  }
  listChars[pos] = tolower(listChars[pos]);
}