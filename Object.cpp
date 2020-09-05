//
// Created by PCMGeek on 2020/9/5.
//
#include "Object.h"
#include_next <cstdlib>
#include <iostream>

using namespace std;

namespace DTLib
{

void* Object::operator new(unsigned long long size) throw()
{
    cout << "operator new(unsigned long long size)  " << size << endl;
    return malloc(size);
}

void Object::operator delete(void* p)
{
    cout << " operator delete(void* p)" << endl;
    free(p);
}

void* Object::operator new[](unsigned long long  size) throw()
{
    return malloc(size);
}

void Object::operator delete[](void* p)
{
    free(p);
}

Object::~Object()
{

}

}