//
// Created by PCMGeek on 2020/9/4.
//

#ifndef CPP_EXCEPTION_H
#define CPP_EXCEPTION_H

namespace DTLib {

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))

    class Exception {
    protected:
        char *m_message;
        char *m_location;

        void init(const char *meassage, const char *file, int line);

    public:
        Exception(const char *message);
        Exception(const char *file, int line);
        Exception(const char *message, const char *file, int line);

        Exception(const Exception &e);

        Exception &operator=(const Exception &e);

        virtual const char *message() const;
        virtual const char *location() const;

        virtual ~Exception(); //jizhu
    };


    class ArithmeticException : public Exception {
    public:
        //调用相应的父类构造函数
        ArithmeticException() : Exception(0) {}
        ArithmeticException(const char *message) : Exception(message) {}
        ArithmeticException(const char *file, int line) : Exception(file, line) {}
        ArithmeticException(const char *message, const char *file, int line) : Exception(message, file, line) {}

        ArithmeticException(const ArithmeticException &e) : Exception(e) {}

        ArithmeticException &operator=(const ArithmeticException &e) {
            Exception::operator=(e);

            return *this;
        }
    };


    class NullPointerException : public Exception
    {
    public:
        NullPointerException() : Exception(0) {}
        NullPointerException(const char *message) : Exception(message) {}
        NullPointerException(const char *file, int line) : Exception(file, line) {}
        NullPointerException(const char *message, const char *file, int line) : Exception(message, file, line) {}

        NullPointerException(const NullPointerException & e) : Exception(e) {}

        NullPointerException & operator= (const NullPointerException & e)
        {
            Exception::operator=(e);

            return *this;
        }
    };


    class IndexOutOfBoundsException : public Exception
    {
    public:
        IndexOutOfBoundsException() : Exception(0) {}
        IndexOutOfBoundsException(const char * message) : Exception(message) {}
        IndexOutOfBoundsException(const char * file, int line) : Exception(file, line) {}
        IndexOutOfBoundsException(const char * message, const char * file, int line) : Exception(message, file, line) {}

        IndexOutOfBoundsException(const IndexOutOfBoundsException & e) : Exception(e) {}

        IndexOutOfBoundsException & operator= (const IndexOutOfBoundsException & e)
        {
            Exception::operator=(e);

            return *this;
        }

    };


    class NoEnoughMemoryException : public Exception
    {
    public:
        NoEnoughMemoryException() : Exception(0) {}
        NoEnoughMemoryException(const char * message) : Exception(message) {}
        NoEnoughMemoryException(const char * message, const char * file, int line) : Exception(message, file, line) {}
        NoEnoughMemoryException(const char * file, int line) : Exception(file, line) {}

        NoEnoughMemoryException(const NoEnoughMemoryException & e) : Exception(e) {}

        NoEnoughMemoryException & operator= (const NoEnoughMemoryException & e)
        {
            Exception::operator= (e);

            return *this;
        }
    };


    class InvalidParameterException : public Exception
    {
    public:
        InvalidParameterException() : Exception(0) {}
        InvalidParameterException(const char * message) : Exception(message) {}
        InvalidParameterException(const char * file, int line) : Exception(file, line) {}
        InvalidParameterException(const char * message, const char * file, int line) : Exception(message, file, line) {}

        InvalidParameterException(const InvalidParameterException & e) : Exception(e) {}

        InvalidParameterException & operator= (const InvalidParameterException & e)
        {
            Exception::operator= (e);

            return *this;
        }

    };
}

#endif //CPP_EXCEPTION_H
