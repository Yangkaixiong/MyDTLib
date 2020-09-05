//
// Created by PCMGeek on 2020/9/3.
//

#ifndef CPP_SMARTPOINTER_H
#define CPP_SMARTPOINTER_H

namespace DTLib {
    template<typename T>
    class SmartPointer {
    protected:
        T *m_pointer;
    public:
        SmartPointer(T *p = 0) {
            m_pointer = p;
        }

        SmartPointer(const SmartPointer<T> &obj) {
            m_pointer = obj.m_pointer;

            const_cast<SmartPointer<T> &>(obj).m_pointer = 0;
        }

        SmartPointer & operator= (const SmartPointer<T> &obj) {
            if (this != obj) {
                delete m_pointer;

                m_pointer = obj.m_pointer;

                const_cast<SmartPointer<T> &>(obj).m_pointer = 0;
            }

            return *this;
        }

        T *operator->() {
            return m_pointer;
        }

        T &operator*() {
            return *m_pointer;
        }

        bool isNull() {
            return (m_pointer = 0);
        }

        T *get() {
            return m_pointer;
        }

        ~SmartPointer() {
            delete m_pointer;
        }

    };
}
#endif //CPP_SMARTPOINTER_H
