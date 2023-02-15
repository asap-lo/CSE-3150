//implement functions of ECNumbers.h
#include "ECCalculator.h"
using namespace ECNUMBERS_H;

int ECFourTimesN(int n)
{
    return ECDoubleN(ECDoubleN(n));
}