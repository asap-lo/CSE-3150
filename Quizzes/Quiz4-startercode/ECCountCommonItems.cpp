// Created by Y. Wu, Feb 11, 2023
// You are to implement a functionc alled ECCountCommonItems, which takes two parameters: (i) a container X, and (ii) a container Y; this function would count (and return) the number of items that are in BOTH X and Y. 
// For example, X=[1,3,5,8] and Y=[2,3,8,9], then return 2: common items [3,8]
// Note: X and Y can be of different types of containers; but the data types in the two containers are the same and this data type allows equality check (if a==b)
// For this assignment, we will focus on flexibility: supporting different kinds of containers; I will not examine the run-time...


template<class Container1, class Container2>
int ECCountCommonItems(Container1 X, Container2 Y) {
    int count = 0;
    for (auto x : X) {
        for (auto y : Y) {
            if (x == y) {
                count++;
                break;
            }
        }
    }
    return count;
}