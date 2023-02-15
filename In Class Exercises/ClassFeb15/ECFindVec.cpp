#include <vector>
using namespace std;

bool ECFind(const vector<int> &listVecs, int x)
{
  for( auto y : listVecs )
  {
    if( x == y )
    {
      return true;
    }
  }
  return false;
}

