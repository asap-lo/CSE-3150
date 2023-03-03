#include <iostream>
using namespace std;

// Class A
class A 
{
public:
  virtual ~A() {}

  virtual void foo(int x) 
  {
    cout << "A\n";
  }
};

// Class B: subclass of A
class B : public A
{
public:
  void foo(int y) override
  {
    cout << "B\n";
  }
};

void Test(A &a)
{
  a.foo(1);
}

int main()
{
  B b;
  Test(b);
  // A *pa = new B;
  // Test(*pa);
  // delete pa;
}
