// Test code for editor
#include "ECTextViewImp.h"
#include <iostream>

using namespace  std;

int myCounter = 0;

class ECTextObserver : public ECObserver
{
public:
    ECTextObserver( ECTextViewImp *pObsSubj )
    {
        this->pObsSubj = pObsSubj;
        pObsSubj->Attach(this);
    };

    virtual ~ECTextObserver()
    {
        pObsSubj->Detach(this);
        delete pObsSubj;
    };

    virtual void Update()
    {
        if( pObsSubj->GetPressedKey() == ESC )
        {
            pObsSubj->InitRows();
            pObsSubj->ClearColor();
            pObsSubj->AddRow("John Lombardo");
        }
    };
    
private :
    ECTextViewImp *pObsSubj;
};

int main(int argc, char *argv[])
{
    //
    ECTextViewImp wndTest;
    wndTest.AddRow("CSE 3150");
    wndTest.SetColor(0, 0, 0, TEXT_COLOR_RED);
    wndTest.SetColor(0, 1, 1, TEXT_COLOR_GREEN);
    wndTest.SetColor(0, 2, 2, TEXT_COLOR_BLUE);
    wndTest.SetColor(0, 4, 4, TEXT_COLOR_RED);
    wndTest.SetColor(0, 5, 5, TEXT_COLOR_GREEN);
    wndTest.SetColor(0, 6, 6, TEXT_COLOR_BLUE);
    wndTest.SetColor(0, 7, 7, TEXT_COLOR_MAGENTA);
    wndTest.AddRow("This is a very simple demo of the ECTextViewImp functionalities.");
    wndTest.SetColor(1, 10, 13, TEXT_COLOR_GREEN);
    wndTest.AddRow("Press ctrl-q to quit");
    wndTest.SetColor(2, 0, 1, TEXT_COLOR_GREEN);
    wndTest.SetColor(2, 0, 1, TEXT_COLOR_DEF);

    // add a status bar
    wndTest.AddStatusRow("Editor", "For demo only", true);



    ECTextObserver myObserver(&wndTest);

    wndTest.Show();

    // if( keyLastPressed == ESC )
    // {
    //         InitRows();
    //         AddRow("John Lombardo");
    // }
    // use observer pattern to check when escape key is pressed


    


    return 0;
}
