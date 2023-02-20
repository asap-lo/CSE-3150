// Merge overlapping intervals and return an array of the non-overlapping intervals that cover all the intervals in the input
// Your code must run no slower than O(nlogn) where n is the number of intervals

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void ECMergeIntervals(const std::vector<std::pair<int,int> > &listIntervals, std::vector<std::pair<int,int> > &listNonOverlapIntervals)
{   
    if (listIntervals.size() == 0) {
        return;
    }
    listNonOverlapIntervals.push_back(listIntervals[0]);
    for (int i = 1; i < listIntervals.size(); i++) {
        if (listIntervals[i].first <= listNonOverlapIntervals.back().second) {
            listNonOverlapIntervals.back().second = max(listIntervals[i].second, listNonOverlapIntervals.back().second);
        } else {
            listNonOverlapIntervals.push_back(listIntervals[i]);
        }
    }
}
