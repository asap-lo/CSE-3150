//
//  ECConsecutiveInts.cpp
//  
//
//  Created by Yufeng Wu on 1/15/23.
//
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// Test whether strInput is a string composed of consecutive and increasing integers (in decimal formats)
// Return true if yes and false otherwise (return false if there are unexpected characters)
// For example, 1234578 would return false, while 1213141516 would return true (12 13 14 15 16)
// You may assume the integers is at most 999999 and there is no any seperators between numbers
// You may also assume integers are all non-negatives

// Tip: try to use library functions instead of writing a lot of code yourself
// functions in C++ string you may find useful:
// substr: extract a substring from a string
// stoi:  convert string to integer (be careful about how to handle exception)
// and so on..

bool ECConsecutiveInts(const string &strInput)
{
  // your code  here
  int index = 0;
  int num;
  int next;
  int digits = 1;

  while (1)
  {
    // check to see if the strInput has enough digits left to support next, if not, and digits >= 6, return false
    // try/catch?
    // Having issue with 9->10 case, when should I get number of digits?
    //910111213
    try
    {
      num = stoi(strInput.substr(index, digits));
      next = num + 1;
      int nextDigits = int(log10(next) + 1);
      if (next == stoi(strInput.substr(index + digits, nextDigits)))
      {
        cout << num << endl;
        cout << next << endl;
        index = index + digits;
        if (index + digits == strInput.length())
        {
          return true;
        }
        digits = nextDigits;
      }
      else
      {
        index = 0;
        digits += 1;
        continue;
      }
    }
    catch (const std::exception &e)
    {
      // std::cerr << e.what() << '\n';
      if (digits >= 6)
      {
        return false;
      }
      index = 0;
      digits += 1;
    }

    
  }
  return true;
}