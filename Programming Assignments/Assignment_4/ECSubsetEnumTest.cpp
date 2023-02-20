#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

extern int ECSubsetEnumCount(const std::vector<char> &vecChars);
extern void ECSubsetEnum(const std::vector<char> &vecChars, std::vector<vector<char> > &listSubsets);

template<class T>
void ASSERT_EQ(T x, T y)
{
  if( x == y )
  {
    cout << "Test passed: equal: " << x << "  " << y << endl;
  }
  else
  {
    cout << "Test FAILED: equal: " << x << "  " << y << endl;
  }
}

template<class T>
void ASSERT_EQ_NODUMP(T x, T y)
{
  if( x == y )
  {
    cout << "Test passed: " << endl;
  }
  else
  {
    cout << "Test FAILED: " << endl;
  }
}

static void Test()
{
  vector<char> vec1;
  vec1.push_back('a');
  vec1.push_back('b');
  vec1.push_back('b');
  ASSERT_EQ( ECSubsetEnumCount(vec1), 6 );

  vector<vector<char> > listSubsets;
  ECSubsetEnum(vec1, listSubsets);
  ASSERT_EQ( (int)listSubsets.size(), 6 );
  // sort the subsets
  std::sort( listSubsets.begin(), listSubsets.end() );
  vector<char> vecs0, vecs1, vecs2, vecs3, vecs4, vecs5;
  vecs1.push_back('a');
  vecs2.push_back('a');
  vecs2.push_back('b');
  vecs3 = vec1;
  vecs4.push_back('b');
  vecs5.push_back('b');
  vecs5.push_back('b');
  
  ASSERT_EQ_NODUMP( listSubsets[0], vecs0 );
  ASSERT_EQ_NODUMP( listSubsets[1], vecs1 );
  ASSERT_EQ_NODUMP( listSubsets[2], vecs2 );
  ASSERT_EQ_NODUMP( listSubsets[3], vecs3 );
  ASSERT_EQ_NODUMP( listSubsets[4], vecs4 );
  ASSERT_EQ_NODUMP( listSubsets[5], vecs5 );

  //print out the subsets and vecs0 to vecs5
  for(int i = 0; i < 6; i++)
  {
    cout << "listSubsets[" << i << "]: ";
    for(int j = 0; j < listSubsets[i].size(); j++)
    {
      cout << listSubsets[i][j] << " ";
    }
    cout << endl;
  }
  //print out vecs0 to vecs5
  cout << "vecs0: ";
  for(int i = 0; i < vecs0.size(); i++)
  {
    cout << vecs0[i] << " ";
  }
  cout << endl;
  cout << "vecs1: ";
  for(int i = 0; i < vecs1.size(); i++)
  {
    cout << vecs1[i] << " ";
  }
  cout << endl;
  cout << "vecs2: ";
  for(int i = 0; i < vecs2.size(); i++)
  {
    cout << vecs2[i] << " ";
  }
  cout << endl;
  cout << "vecs3: ";
  for(int i = 0; i < vecs3.size(); i++)
  {
    cout << vecs3[i] << " ";
  }
  cout << endl;
  cout << "vecs4: ";
  for(int i = 0; i < vecs4.size(); i++)
  {
    cout << vecs4[i] << " ";
  }
  cout << endl;
  cout << "vecs5: ";
  for(int i = 0; i < vecs5.size(); i++)
  {
    cout << vecs5[i] << " ";
  }
  cout << endl;

  
}

int main()
{
  Test();
}

