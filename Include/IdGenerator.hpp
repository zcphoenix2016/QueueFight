#pragma once

#include <map>

class IdGenerator
{
public:
    static unsigned int allocate();

private:
    static std::map<unsigned int, bool> m_ids;
};
