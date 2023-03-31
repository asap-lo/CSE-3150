//
//  ECTextDocumentTest.cpp
//  
//
//  Created by Yufeng Wu on 2/26/20.
//
//

#include <iostream>
#include "ECTextDocument.h"

using namespace  std;

static void Test1()
{
    //
    ECTextDocument doc;
    ECTextDocumentCtrl &docCtrl = doc.GetCtrl();
    vector<char> listText1;
    listText1.push_back('a');
    listText1.push_back('b');
    listText1.push_back('c');
    listText1.push_back('d');
    listText1.push_back('e');
    docCtrl.InsertTextAt(0, listText1);
    vector<char> listText2;
    listText2.push_back('f');
    listText2.push_back('g');
    listText2.push_back('h');
    int posIns = 2;
    docCtrl.InsertTextAt(posIns, listText2);
    //int lenDel = 2;
    //docCtrl.RemoveTextAt( posIns, lenDel );
    cout << "Text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    int posCap = 2;
    int lenCap = 5;
    docCtrl.CapTextAt( posCap, lenCap );
    cout << "Text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    int posLow = 3;
    int lenLow = 2;
    docCtrl.LowerTextAt( posLow, lenLow );
    
    cout << "Text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    
    // try undo/redo
    docCtrl.Undo();
    cout << "After undo, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    docCtrl.Undo();
    cout << "After undo, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    
    docCtrl.Redo();
    cout << "After redo, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    docCtrl.Redo();
    cout << "After redo, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;

    // insert "xyz" at pos 2
    vector<char> listText3;
    listText3.push_back('x');
    listText3.push_back('y');
    listText3.push_back('z');
    docCtrl.InsertTextAt(2, listText3);
    cout << "After insert xyz, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    //undo
    docCtrl.Undo();
    cout << "After undo, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    //redo
    docCtrl.Redo();
    cout << "After redo, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    //remove the 3 char at pos 2
    docCtrl.RemoveTextAt(2, 3);
    cout << "After remove 3 char at pos 2, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    //undo
    docCtrl.Undo();
    cout << "After undo, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
    //redo
    docCtrl.Redo();
    cout << "After redo, text: ";
    for(int i=0; i<doc.GetDocLen(); ++i)
    {
        cout << doc.GetCharAt(i);
    }
    cout << endl;
}

int main()
{
    // test code
    Test1();
    
    return 0;
}

