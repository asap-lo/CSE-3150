// Created by Y. Wu, Jan 28, 2023
// Enumerate all subsets of a vector of characters which may contain duplicates
// First, a function for counting the number of subsets
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

// (1): counting the number of subsets
int ECSubsetEnumCount(const std::vector<char> &vecChars)
{
  // return the number of subsets (without duplicates) of the vector of chars
  // for example, for [a, b, b], return 6: (), (a), (b), (a,b), (b,b), (a,b,b) 
  // your code here ...
  int length = vecChars.size();
  //get amount of duplicates
  int duplicates = 0;
  for(int i = 0; i < length; i++)
  {
    for(int j = i + 1; j < length; j++)
    {
      if(vecChars[i] == vecChars[j])
      {
        duplicates++;
      }
    }
  }
  //get amount of subsets
  if(duplicates == 0)
  {
    return pow(2, length);
  }
  return pow(2, length) - pow(2, duplicates);

}

// // (2): enumerating the subsets, and store the found subsets in setSubsets
// // Note: the found subsets can be of any order (but cannot contain duplicates)
// // Also note: you should try to make your code as efficient as you can (avoid excessive data copying)
// void ECSubsetEnum(const std::vector<char> &vecChars, std::vector<vector<char> > &listSubsets)
// {
//   // your code here
//   // int length = vecChars.size();
//   // int amountSets = ECSubsetEnumCount(vecChars);
//   // int i = 0;
//   // while(i < amountSets)
//   // {
//   //   vector<char> temp;
//   //   for(int j = 0; j <= length; j++)
//   //   {
//   //     if(i & (1 << j))
//   //     {
//   //       temp.push_back(vecChars[j]);
//   //     }
//   //   }
//   //   listSubsets.push_back(temp);
//   //   i++;
//   // }
  
//   // while(i < amountSets)
//   // {
//   //   vector<char> temp;
//   //   string strTemp = "";
//   //   for (int j = 0; j <= length; j++)
//   //   {
//   //     if(i & (1 << j))
//   //     {
//   //       // cout << vecChars[j] << " ";
//   //       temp.push_back(vecChars[j]);
//   //       strTemp += vecChars[j];
//   //     }
//   //   }

//   int length = vecChars.size();
//   string stringSubSets = "$";
//   int amountSets = ECSubsetEnumCount(vecChars);
//   // store subsets in listSubsets
//   for(int i = 0; i < amountSets; i++)
//   {
//     vector<char> subset;
//     int temp = i;
//     string strTemp = "";
//     for(int j = 0; j < length; j++)
//     {
//       if(i & (1 << j))
//       {
//         subset.push_back(vecChars[j]);
//         strTemp += vecChars[j];
//       }
      
    
//   // }

//     // cout << endl;
//     if(!(stringSubSets.find(strTemp) != string::npos) || strTemp == "")
//     {
//       listSubsets.push_back(subset);
//       stringSubSets.append(strTemp);
//       stringSubSets.append("$");

//       i++;
//       // cout << "added" << endl;
//     }
//     else
//     {
//       // cout << "duplicate found" << endl;
//       i++;
//     }
//     }
    
//   }
  






//}
void ECSubsetEnum(const std::vector<char> &vecChars, std::vector<vector<char> > &listSubsets)
{
  // your code here
  int length = vecChars.size();
  int amountSets = ECSubsetEnumCount(vecChars);
  // store subsets in listSubsets
  for(int i = 0; i < amountSets; i++)
  {
    vector<char> subset;
    int temp = i;
    for(int j = 0; j < length; j++)
    {
      if(temp % 2 == 1)
      {
        subset.push_back(vecChars[j]);
      }
      temp /= 2;
    }
    listSubsets.push_back(subset);
  }
}