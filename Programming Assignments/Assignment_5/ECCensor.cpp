// Created by Y. Wu, Jan 31, 2023
// You are given an input containter (of any STL set/vec/etc) of certain type (e.g., int, string, etc), a container of forbidden items (which may be any STL container type, and so may not be sorted), and a new censored value (of the same type). You are to output (STL container of the same type) the sorted list of items from the input such that this list contains all the items from the input, and any value appearing in the forbidden list is converted to the censored value.  
// For example, suppose the input: [1 -1 2, 5, 2], forbidden list [-1], censored value = 0, then the output is: [0, 1, 2, 2, 5]

// Now define the function ECCensor ...
template <typename C1, typename C2, typename T>
void ECCensor(const C1& c1, const C2& c2, const T& censoredValue, C1& outputList)
{
    for(auto i : c1)
        for(auto j : i)
            if(find(c2.begin(), c2.end(), j) != c2.end())
                outputList.push_back(censoredValue);
            else
                outputList.push_back(j);
    outputList.sort();
}