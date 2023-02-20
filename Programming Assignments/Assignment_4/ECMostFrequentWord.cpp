// Created by Y. Wu, Jan 28, 2023
// Given a string, find the most frequent word; if there is a tie, choose alphabetically smallest
// Word: consecutive alphanumerical symbols; that is, treat all non-alphanumerical symbols as separators
// for example, for "I have bad dreams that have bad feelings", return "bad"
#include <iostream>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

string ECMostFrequentWord(const string &strText)
{
  // Initial code (i did not read the prompt :) )
  // if (int(strText.length()) < 2)
  // {
  //   return strText;
  // }
  
  // // your code here
  // vector<string> strList;
  // string temp = "";
  // // build a vector of individual strings for easier processing
  // int length = int(strText.length());
  // for(int i = 0; i < length; i++)
  // {
  //   if(!isalnum(strText[i]) || (i == length - 1 && isalnum(strText[i])))
  //   {
  //     strList.push_back(temp);
  //     temp = "";
  //   }
  //   else
  //   {
  //     temp.push_back(strText[i]);
  //   }
  // }

  // // sort vector of strings
  // sort(strList.begin(), strList.end());
  // int max = 0;
  // temp = "";
  // for(string str : strList)
  // {
  //   int c = count(strList.begin(), strList.end(), str);
  //   if(c > max)
  //   {
  //     temp = str;
  //     max = c;
  //   }
  // }
  // return temp;

  //turn all non alphanumeric characters into space
  string str = strText;
  for (int i = 0; i < str.length(); i++)
  {
    if(!isalnum(str[i]))
    {
      str[i] = ' ';
    }
  }
  //use stringstream to find most common word
  stringstream ss (str); //convert string to stringstream
  string word;
  vector<string> words;
  while (ss >> word)
  {
    words.push_back(word);
  }
  //use a map to count the frequency of each word
  map<string, int> wordCount;
  for (int i = 0; i < words.size(); i++)
  {
    wordCount[words[i]]++;
  }
  //find the most frequent word using a map iterator
  string mostFrequentWord;
  int maxCount = 0;
  for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); it++)
  {
    if (it->second > maxCount)
    {
      maxCount = it->second;
      mostFrequentWord = it->first;
    }
    else if (it->second == maxCount)
    {
      if (it->first < mostFrequentWord)
      {
        mostFrequentWord = it->first;
      }
    }
  }
  return mostFrequentWord;
  
}

