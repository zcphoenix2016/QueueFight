#include "../Include/IdGenerator.hpp"

std::map<unsigned int, bool> IdGenerator::m_ids = {};

unsigned int IdGenerator::allocate()
{
    unsigned int l_id = 0;
    auto l_iter = m_ids.find(l_id);

    while(l_iter != m_ids.end())
    {
        if(false == l_iter->second)
        {
            l_iter->second = true;
            break;
        }
        else
        {
            l_id ++;
            l_iter = m_ids.find(l_id);
        }
    }

    if(l_iter == m_ids.end())
    {
        m_ids[l_id] = true;
    }

    return l_id;
}

void IdGenerator::release(unsigned int p_id)
{
    m_ids[p_id] = false;
}
