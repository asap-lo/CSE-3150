#include <iostream>
#include <string>
using namespace std;
void foo(int n)
{
    if (n < 0)
        throw string("NEGATIVE");
    if (n == 0)
        throw string("ZERO");
}

string bar(int n)
{
    try
    {
        foo(n);
    }
    catch (string s)
    {
        return s;
    }
    return "OK";
}