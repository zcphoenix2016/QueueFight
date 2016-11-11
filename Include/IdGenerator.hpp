#pragma once

#include <map>

class IdGenerator
{
public:
    static unsigned int allocate();
    static void release(unsigned int);

private:
    static std::map<unsigned int, bool> m_ids;
};
