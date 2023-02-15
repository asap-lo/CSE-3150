#include <set>
#include <vector>
#include <iostream>
using namespace std;

int ECSumList(const set<int> &listNums)
{
  // your code goes here ...
  int sum = 0;
  //for (auto it = listNums.begin(); it != listNums.end(); it++)
  for (auto x : listNums)
  {
    sum += x;
  }
  return sum;
  
}

