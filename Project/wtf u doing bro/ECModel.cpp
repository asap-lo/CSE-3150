#include "ECModel.h"

using namespace std;

ECModel::ECModel(ECView *view, string filename)
{
    this->view = view;
    file.open(filename);
    fileX = 0;
    fileY = 0;
}

void ECModel::MoveCursor(int dx, int dy)
{
    if(dy != 0)
    {
        fileX += dy * view->GetWindowSize();
        if(fileX < 0)
        {
            fileX = 0;
        }
    }
}