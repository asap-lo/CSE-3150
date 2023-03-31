//
//  ECCommand.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include "ECCommand.h"
#include "ECTextDocument.h"
#include <vector>
#include <string>
#include <iostream>
// ******************************************************
// Implement command history

ECCommandHistory :: ECCommandHistory() 
{
  curCmdIdx = -1;
}

ECCommandHistory :: ~ECCommandHistory()
{
  //destruct all the commands in the list
  for(auto cmd : listCmds)
  {
    delete cmd;
  }

}

bool ECCommandHistory :: Undo()
{
  if(curCmdIdx < 0)
  {
    return false;
  }
  else
  {
    listCmds[curCmdIdx]->UnExecute();
    curCmdIdx--;
    return true;
  }
}


bool ECCommandHistory :: Redo()
{
  
  if(curCmdIdx >= int(listCmds.size()) - 1)
  {
    return false;
  }
  else
  {
    
    curCmdIdx++;
    //print current command index
    listCmds[curCmdIdx]->Execute();
    return true;
  }
}

void ECCommandHistory :: ExecuteCmd( ECCommand *pCmd )
{
  
  //delete all the commands after the current command
  for(int i = curCmdIdx + 1; i < int(listCmds.size()); i++)
  {
    delete listCmds[i];
  }
  //add the command to the list
  listCmds.push_back(pCmd);
  //print the list
  
  //print the current command index
  curCmdIdx++;

}

void ECCommandLower :: Execute()
{
  //lowercase the text
  int tempPos = pos;
  for(int i = 0; i < len; i++)
  {
    doc.LowerCharAt(tempPos);
    
    tempPos++;
  }
}

void ECCommandLower :: UnExecute()
{
  //uppercase the text
  int tempPos = pos;
  for(int i = 0; i < len; i++)
  {
    doc.CapCharAt(tempPos);
    //priont pos
    tempPos++;
  }
  
}


void ECCommandUpper::Execute()
{
  //uppercase the text
  int tempPos = pos;
  for(int i = 0; i < len; i++)
  {
    doc.CapCharAt(tempPos);
    tempPos++;
  }
}

void ECCommandUpper :: UnExecute()
{
  //lowercase the text
  int tempPos = pos;
  for(int i = 0; i < len; i++)
  {    
    doc.LowerCharAt(tempPos);
    tempPos++;
  }
}

void ECCommandInsert :: Execute()
{
  //insert the text
  int tempPos = pos;
  for(auto c : listCharsToIns)
  {
    doc.InsertCharAt(tempPos, c);
    tempPos++;
  }
}

void ECCommandInsert :: UnExecute()
{
  //delete the text
  int tempPos = pos;
  for(int i = 0; i < int(listCharsToIns.size()); i++)
  {
    doc.RemoveCharAt(tempPos);
  }
}

void ECCommandRemove :: Execute()
{
  //delete the text
  for(int i = 0; i < lenToRemove; i++)
  {
    doc.RemoveCharAt(pos);
  }
}

void ECCommandRemove :: UnExecute()
{
  //insert the text
  int tempPos = pos;
  for(auto c : listCharsRemoved)
  {
    doc.InsertCharAt(tempPos, c);
    tempPos++;
  }

}