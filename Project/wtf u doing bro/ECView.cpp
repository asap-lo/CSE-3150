#include "ECView.h"

void ECView::UpdateView(vector<string> &listRows, int x, int y)
{
    viewImp->SetCursorY(y);
    if(x > viewImp->GetColNumInView())
    {
        viewImp->SetCursorY(y + x / viewImp->GetColNumInView());
    }
}