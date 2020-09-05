//
// Created by PCMGeek on 2020/9/4.
//

#include "Exception.h"
#include <cstring>
#include <cstdlib>

using namespace std;

namespace DTLib
{
    void Exception::init(const char * message, const char * file, int line)
    {
        m_message = strdup(message);

        if (file != NULL) {
            char sl[16] = {0};

            itoa(line, sl, 10);

            m_location = static_cast<char *>(malloc(strlen(file) + strlen(sl) + 2));
            m_location = strcpy(m_location, file);
            m_location = strcat(m_location, ":");
            m_location = strcat(m_location, sl);
        } else {
            m_location = NULL;
        }
    }

    Exception::Exception(const char *message)
    {
        init(message, NULL, 0);
    }

    Exception::Exception(const char *file, int line)
    {
        init(NULL, file, line);
    }

    Exception::Exception(const char *message, const char *file, int line)
    {
        init(message, file, line);
    }

    Exception::Exception(const Exception & e)
    {
        m_location = strdup(e.m_location); // 每个类对象的两个指针指向的内容都是独立的一段堆空间。
        m_location = strdup(e.m_message);

        const_cast<Exception &>(e).m_location = NULL;
        const_cast<Exception &>(e).m_message = NULL;
    }

    Exception & Exception::operator= (const Exception & e)
    {
        if (this != &e) {
            free(m_message);
            free(m_location);

            m_message = strdup(e.m_message);
            m_location = strdup(e.m_location);

            const_cast<Exception &>(e).m_message = NULL;
            const_cast<Exception &>(e).m_location = NULL;
        }

        return *this;

    }

    const char * Exception::message() const
    {
        return m_message;
    }

    const char * Exception::location() const
    {
        return m_location;
    }

    Exception::~Exception()
    {
        free(m_message);
        free(m_location);
    }
}