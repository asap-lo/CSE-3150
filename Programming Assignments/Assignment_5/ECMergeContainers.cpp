// Created by Y. Wu, Jan 31, 2023
// Merge lists (of any STL container type) into a single sorted list (of any STL container type)
// Duplicates allowed unless the output doesn't take duplicates (e.g., a map)
// Note: you should make your code as flexible as possible: you should allow all kinds of outputs: vector, set, etc 
// Make your code short: at most 10 lines of code (LOC) 

// now defiine ECMergeContainers ...
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;
template <typename C1>
void ECMergeContainers(const C1& c1, const C1& c2)
{
    for(auto i : c1)
        for(auto j : i)
            c2.insert(j);
    c2.sort();
}