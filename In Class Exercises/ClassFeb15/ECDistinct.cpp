#include <vector>
#include <map>
#include <iostream>
using namespace std;

void ECCountDistinct(const vector<int> &listNums, map<int,int> &mapDistinct)
{
  for(auto x : listNums)
  {
    mapDistinct[x]++;
  }
}

