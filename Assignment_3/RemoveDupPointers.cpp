//
//  RemoveDupPointers.cpp
//
//
//  Created by Yufeng Wu on 1/18/21.
//
//
#include <iostream>

#include <string>
#include <vector>
using namespace std;

//
void RemoveDupPointers(vector<string *> &arrayPtrs)
{
    // arrayPtrs: STL vector of pointers to strings
    // remove pointers that are pointed to identical strings in the array
    // Your code goes here...

    for (int i = 0; i < arrayPtrs.size(); i++)
    {
        for (int j = i + 1; j < arrayPtrs.size(); j++)
        {
            if (*arrayPtrs[i] == *arrayPtrs[j])
            {
                arrayPtrs.erase(arrayPtrs.begin() + j);
                j--;
            }
        }
    }
    
}

// int main()
// {
//     // write test cases for the above function
//     vector<string *> arrayPtrs;
//     string *s1 = new string("hello");
//     string *s2 = new string("world");
//     string *s3 = new string("hello");
//     string *s4 = new string("ofudojovainovbcovin");
//     string *s5 = new string("hello");
//     string *s6 = new string("world");
//     string *s7 = new string("'fuocnslk'");

//     arrayPtrs.push_back(s1);
//     arrayPtrs.push_back(s2);
//     arrayPtrs.push_back(s3);
//     arrayPtrs.push_back(s4);
//     arrayPtrs.push_back(s5);
//     arrayPtrs.push_back(s6);
//     arrayPtrs.push_back(s7);

//     RemoveDupPointers(arrayPtrs);
//     for (int i = 0; i < arrayPtrs.size(); i++)
//     {
//         cout << *arrayPtrs[i] << endl;
//     }
// }
