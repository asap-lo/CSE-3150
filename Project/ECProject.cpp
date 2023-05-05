#include "ECProject.h"
#include <string>

/****************************************************

ECModel --
    Contains a list of rows and a ECView object
    Has method AddCharacter(char c, int line, int pos)
    this method adds a character in the proper place
    and updates the view.
    Has method Return(int line, int pos) which creates
    a return in the document, splitting a line when
    not at the end and creating a new line when at the
    end.

*****************************************************/

// AddChar function adds a character at a given x, y coordinate
void ECModel::AddChar(string c)
{
    //if(listRows.size() < view->GetRowNumInView())
    //listRows[y].insert(x, to_string(y));
    listRows[y].insert(x, c);
    x += 1;
    view->UpdateView(listRows, x, y);
    
}

// Return function adds a new line or breaks a line in two given a x, y coordinate
void ECModel::Return()
{
    string rv = "";
    rv = listRows[y].substr(x, string::npos);
    listRows[y] = listRows[y].substr(0, x);
    listRows.insert(listRows.begin() + y + 1, rv);

    // Update view accordingly
    x = 0;
    y += 1;
    
    
    view->UpdateView(listRows, x, y);
    
}

// Backspace function removes a character to the left of the cursor given an x, y coordinate
void ECModel::Backspace()
{
    // If cursor is on the left side of the screen, delete line and append trailing characters to the previous line
    if(x == 0)
    {
        if(y != 0)
        {
            string rv = listRows[y];
            listRows.erase(listRows.begin() + y);
            y -= 1;
            x = listRows[y].size();
            listRows[y] += rv;
            view->UpdateView(listRows, x, y);
        }
    }
    else
    {
        listRows[y].erase(x - 1, 1);
        // listRows[y].erase(0, 1);
        x -= 1;
        view->UpdateView(listRows, x, y);
    }
}

// Given delta x and delta y, move cursor to desired position in the view
void ECModel::MoveCursor(int dx, int dy)
{
    //positive dy is down positive dx is right
    if(dx == -1)
    {
        x--;
        if(x < 0)
            if(y == 0)
                x = 0;
            else
            {
                y--;
                x = listRows[y].size();
            }
    }
    if(dx == 1)
    {
        x++;
        if(x > listRows[y].size())
            if(y == listRows.size() - 1)
                x = listRows[y].size();
            else
            {
                y++;
                x = 0;
            }
    }
    if(dy == -1)
    {
        if(x < view->GetColNumInView())
        {
            y--;
            if(y < 0)
            {
                y = 0;
                x = 0;
            }
            if(x > listRows[y].size())
                x = listRows[y].size();
        }
        else
        {
            x -= view->GetColNumInView();
            if(x < 0)
            {
                x = 0;
                y--;
            }
            if(y < 0)
                y = 0;
        }
    }
    if(dy == 1)
    {
        if(listRows[y].size() < view->GetColNumInView())
        {
            y++;
            if(y > listRows.size() - 1)
            {
                y = listRows.size() - 1;
                x = listRows[y].size();
            }
            if(x > listRows[y].size())
                x = listRows[y].size();
        }
        else
        {
            x += view->GetColNumInView();
            if(x > listRows[y].size() - 1)
            {
                y++;
                if(y > listRows.size() - 1)
                {
                    y = listRows.size() - 1;
                    x = listRows[y].size();
                }
                else
                {
                    x = x / view->GetColNumInView();
                    if(x > listRows[y].size())
                        x = listRows[y].size();
                }
            }
            // else
            // {
            //     x / view->GetColNumInView();
            // }
        }

    }
    
    view->UpdateView(listRows, x, y);
}

void ECModel::LoadFile()
{
    listRows.clear();
    file.open(filename);
    string line;
    while(getline(file, line))
    {
        listRows.push_back(line);
    }
    file.close();
    view->UpdateView(listRows, x, y);
}

void ECModel::WriteToFile()
{
    
    outfile.open(filename, ofstream::out | ofstream::trunc);
    for(auto s : listRows)
    {
        outfile << s << endl;
    }
    outfile.close();
    view->UpdateView(listRows, x, y);
}


/****************************************************

ECController --
    Contains reference to model and an inputObserver.
    Controller handles input using the Update() method
    inherited from the ECObserver class, which is called
    every time a key is pressed.

*****************************************************/

void ECController::Update()
{
    int cx = model->GetCursorX();
    int cy = model->GetCursorY();
    int key = inputObserver->GetPressedKey();
    char ckey = inputObserver->GetPressedKey();
    if(key == CTRL_Q)
    {
        model->WriteToFile();
    }
    if(command)
    {
        if(ckey == 'i')
        {
            command = false;
            inputObserver->ClearStatusRows();
            inputObserver->AddStatusRow("****INSERT MODE****", "Press ESC for command mode", true);
            model->WriteToFile();
        }
        else if(key == CTRL_Z)
        {
            commandHistory->SetTemp(model->GetListRows());
            commandHistory->UndoAll();
            
        }
        else if(key == CTRL_Y)
        {
            commandHistory->RedoAll();
        }
    }
    else
    {
        if(key == ENTER)
        {
            model->Return();
        }
        else if(key == BACKSPACE)
        {
            if(cy != 0 && cx == 0)
            {
                string s = "";
                ECRemoveCommand rem(s, model, true);
                commandHistory->AddCommand(&rem);
                rem.Execute();
            }
            else if(cx != 0)
            {
                string removed = model->GetListRows()[cy].substr(cx - 1, 1);
                ECRemoveCommand rem(removed, model, false);
                commandHistory->AddCommand(&rem);
                rem.Execute();
            }
        }
        else if(key == CTRL_A || key == ESC)
        {
            command = true;
            inputObserver->ClearStatusRows();
            inputObserver->AddStatusRow("****COMMAND MODE****", "Press i for insert mode", true);
        }
        else if(key == ARROW_LEFT)
        {   
            model->MoveCursor(-1, 0);
        }
        else if(key == ARROW_RIGHT)
        {
            model->MoveCursor(1, 0);
        }
        else if(key == ARROW_UP)
        {
            model->MoveCursor(0, -1);
        }
        else if(key == ARROW_DOWN)
        {
            model->MoveCursor(0, 1);
        }
        else if(!command)
        {
            ECAddCommand add(string(1, ckey), model);
            commandHistory->AddCommand(&add);
            add.Execute();
        }
    }
    
    
    
    
}

/****************************************************

ECView --
    Contains reference to viewImp. View updates 
    according to listRows passed in by the model.
    Updates by clearing all lines from ECTextViewImp
    and adding all lines from the input listRows.

*****************************************************/

void ECView::UpdateView(vector<string> &listRows, int x, int y)
{
    viewImp->InitRows();
    int originalY = y;
    int rowsAdded = 0;
    bool flag = true;
    
    vector<string> temp = listRows;
    for(int i = 0; i < (int) temp.size(); i++)
    {
        if(temp[i].size() > viewImp->GetColNumInView())
        {
            for(int j = 0; j < (int) temp[i].size(); j += viewImp->GetColNumInView())
            {
                viewImp->AddRow(temp[i].substr(j, viewImp->GetColNumInView()));
                
                if(temp[i].substr(j, viewImp->GetColNumInView()).size() < viewImp->GetColNumInView() && i == originalY)
                    flag = false;
                else if(flag)
                    rowsAdded++;
                
                
            }
            
        }
        else
        {
            if(i >= originalY)
                flag = false;
            viewImp->AddRow(temp[i]);
        }
    }

    y += rowsAdded;
    if(x > viewImp->GetColNumInView())
    {
        x = x % (viewImp->GetColNumInView());
    }
    if(temp[y].size() < viewImp->GetColNumInView() && rowsAdded > 0)
    {
        y--;
    }
    
    //handle case where x == 0
    

    // try
    // {
    //     SetCursorPos(y, x);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    
    SetCursorPos(y, x);
    
}

void ECView::SetCursorPos(int line, int pos)
{
    viewImp->SetCursorY(line);
    viewImp->SetCursorX(pos);
}

// Command pattern
void ECAddCommand::Execute()
{
    //update model with key pressed
    GetModel()->AddChar(GetKey());
}
void ECAddCommand::UnExecute()
{
    GetModel()->Backspace();
}


void ECRemoveCommand::Execute()
{
    GetModel()->Backspace();
    //if(lineDeleted)
    //    SetCoordinates(GetModel()->GetCursorY(), GetModel()->GetCursorX());
}
void ECRemoveCommand::UnExecute()
{
    if(lineDeleted)
        GetModel()->Return();
    else
        GetModel()->AddChar(GetKey());
}

void ECReturnCommand::Execute()
{
    GetModel()->Return();
}
void ECReturnCommand::UnExecute()
{
    GetModel()->Backspace();
}


/*
Command History
*/
void ECCommandHistory::AddCommand(ECTextCommand *command)
{
    //remove trailing commands at index
    commands.erase(commands.begin() + index, commands.end());
    //add command to end of list
    commands.push_back(command);
    index++;
}

void ECCommandHistory::UndoAll()
{

}

void ECCommandHistory::RedoAll()
{
    for(index; index < commands.size(); index++)
    {
        commands[index]->Execute();
    }
}