#include <iostream>
#include <algorithm>
using namespace std;

static bool IsSmaller(int x, int y)
{
  return x < y;
}
static bool IsLarger(int x, int y)
{
  return x > y;
}
static bool IsOdd(int x, int y)
{
  return x % 2 == 1 && y % 2 == 0;
}
// complete the definition of the sorting function ...
void ECSortFP(int *listNumbers, int size, bool (*pf)(int, int))
{
  // your code here
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (pf(listNumbers[j], listNumbers[i]))
      {
        std::swap(listNumbers[i], listNumbers[j]);
      }
    }
  }
}

int main()
{
  int arr[] = {3, 2, 1, 4};
  ECSortFP(arr, 4, IsOdd);

  // print it out
  for (int i = 0; i < 4; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
