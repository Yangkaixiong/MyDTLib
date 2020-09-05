//
// Created by PCMGeek on 2020/9/5.
//
#ifndef CPP_OBJECT_H
#define CPP_OBJECT_H
namespace DTLib
{
    class Object
    {
    public:
        void* operator new(unsigned long long size) throw();
        void operator delete(void* p);
        void* operator new[](unsigned long long  size) throw();
        void operator delete[](void* p);
        virtual ~Object() = 0;
    };
}




















#endif //CPP_OBJECT_H
