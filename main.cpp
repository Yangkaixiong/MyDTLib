#include <iostream>
#include "Object.h"

using namespace std;
using namespace DTLib;

class Test : public Object
{
public:
    int i;
    int j;
};

class Child : public Test
{
public:
    int k;
};

int main()
{
    Object* obj1 = new Test();
    Object* obj2 = new Child();

    delete obj1;
    delete obj2;












}