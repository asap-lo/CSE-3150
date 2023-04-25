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
void ECModel::AddChar(string c, int line, int pos)
{
    listRows[line].insert(pos, c);
    view->UpdateView(listRows);
    MoveCursor(1, 0);
}

// Return function adds a new line or breaks a line in two given a x, y coordinate
void ECModel::Return(int line, int pos)
{
    string rv = "";
    rv = listRows[line].substr(pos, string::npos);
    listRows[line] = listRows[line].substr(0, pos);
    listRows.push_back(rv);

    // Update view accordingly
    view->UpdateView(listRows);
    view->SetCursorPos(line + 1, 0);
}

// Backspace function removes a character to the left of the cursor given an x, y coordinate
void ECModel::Backspace(int line, int pos)
{
    // If cursor is on the left side of the screen, delete line and append trailing characters to the previous line
    if(pos == 0 && line > 0)
    {
        string rem = listRows[line];
        listRows.pop_back();
        int i = (int) listRows.back().size();
        listRows.back() += rem;
        view->UpdateView(listRows);
        view->SetCursorPos(line - 1, i);
    }
    else if(pos > 0)
    {
        listRows[line].replace(pos - 1, 1, "");
        view->UpdateView(listRows);
        MoveCursor(-1, 0);
    }
}

// Given delta x and delta y, move cursor to desired position in the view
void ECModel::MoveCursor(int dx, int dy)
{
    int x = view->GetCursorX() + dx;
    int y = view->GetCursorY() + dy;
    
    if(dx == 0)
    {
        if(y >= 0 && y < listRows.size())
        {
            if(x > (int) listRows[y].size())
                x = (int) listRows[y].size();
            view->SetCursorPos(y, x);
        }
    }
    else
    {
        if(x >= 0 && x <= listRows[y].size())
        {
            view->SetCursorPos(y, x);
        }
        else if(x < 0 && y - 1 >= 0)
        {
            view->SetCursorPos(y-1, (int) listRows[y-1].size());
        }
        else if(x > 0 && y + 1 < (int) listRows.size())
        {
            view->SetCursorPos(y+1, 0);
        }
    }
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
    int cx = inputObserver->GetCursorX();
    int cy = inputObserver->GetCursorY();
    int key = inputObserver->GetPressedKey();
    char ckey = inputObserver->GetPressedKey();
    if(key == ENTER)
    {
        model->Return(cy, cx);
    }
    else if(key == BACKSPACE)
    {
        if(cy != 0 && cx == 0)
        {
            string s = model->GetListRows()[cy];
            ECRemoveCommand rem(s, cy, cx, model, true);
            commandHistory->AddCommand(&rem);
            //*****MAY NEED TO STORE NEW CURsOR POSITION, ignore for now ****
            rem.Execute();
        }
        else if(cx != 0)
        {
            string removed = model->GetListRows()[cy].substr(cx - 1, 1);
            ECRemoveCommand rem(removed, cy, cx, model, false);
            commandHistory->AddCommand(&rem);
            rem.Execute();
        }
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
    else
    {
        ECAddCommand add(string(1, ckey), cy, cx, model);
        commandHistory->AddCommand(&add);
        add.Execute();
    }
    
}

/****************************************************

ECView --
    Contains reference to viewImp. View updates 
    according to listRows passed in by the model.
    Updates by clearing all lines from ECTextViewImp
    and adding all lines from the input listRows.

*****************************************************/

void ECView::UpdateView(vector<string> &listRows)
{
    viewImp->InitRows();
    for(auto s : listRows)
    {
        viewImp->AddRow(s);
    }
}

// Command pattern
void ECAddCommand::Execute()
{
    //update model with key pressed
    GetModel()->AddChar(GetKey(), GetLine(), GetPos());
}
void ECAddCommand::UnExecute()
{
    GetModel()->Backspace(GetLine(), GetPos() + 1);
}


void ECRemoveCommand::Execute()
{
    GetModel()->Backspace(GetLine(), GetPos());
}
void ECRemoveCommand::UnExecute()
{
    if(lineDeleted)
        GetModel()->Return(GetLine(), GetPos());
    else
        GetModel()->AddChar(GetKey(), GetLine(), GetPos());
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