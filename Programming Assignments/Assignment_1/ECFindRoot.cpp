// This function returns the smallest non-negative integral root of a polynomial (as specified by a list of coefficients and degree) that is no larger than xmax. Return -1 if there is no roots within the range.
//To be specific: for each integer 0 <=i <= degree, listCoeffs[d] = the coefficient of the degree d term. For example, 
#include <iostream>
using namespace std;

int pow(int base, int exp)
{
  //power function
  int result = 1;
  for(int i = 0; i < exp; i++)
  {
    result *= base;
  }
  return result;
}



int ECFindRoot(int *listCoeffs, int degree, int xmax)
{
  // listCoeffs: pointer to the array of integers as the coefficients of a polynomial; listCoeffs[0] is the constant term and so on
  // degree: highest degree term. That is, the number of coefficients in the array = degree+1
  // xmax: the largest value of root to search
  // your code here
 

  for(int i = 0; i < xmax; i++)
  {
    int rem = 0;
    for(int j = 0; j <= degree; j++)
    {
      rem += listCoeffs[j] * pow(i,j);
    }
    if(rem == 0)
    {
      return i;
    }
  }
  return -1;
}



  // for(int i = 2; i < xmax + 1; i++)
  // {
  //   if(listCoeffs[0] % i == 0)
  //   {
  //     for(int j = 1; i < xmax + 1; i++)
  //     {
  //       if(listCoeffs[degree] % j == 0) 
  //       {
  //         return listCoeffs[0] / listCoeffs[degree];
  //       }
  //     }
  //   }
  // }
  // return -1;