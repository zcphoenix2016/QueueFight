#pragma once

#include <map>

class IdGenerator
{
public:
    static unsigned int allocate();
    static void release(unsigned int);
    static void clear();
    static unsigned int size();

private:
    static std::map<unsigned int, bool> m_ids;
};
