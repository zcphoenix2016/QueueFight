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
    auto l_iter = m_ids.find(p_id);
    if(l_iter == m_ids.end()
        || false == l_iter->second)
    {
        throw std::invalid_argument("Try to release unallocated Id.");
    }

    m_ids[p_id] = false;
}

void IdGenerator::clear()
{
    m_ids.clear();
}

unsigned int IdGenerator::size()
{
    return m_ids.size();
}