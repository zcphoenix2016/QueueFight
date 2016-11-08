#include "../Include/QueueFight.hpp"
#include <iterator>
#include <algorithm>

void QueueFight::push(const Person p_person)
{
    m_queue.push_front(p_person);

    auto iter = m_queue.begin();
    auto next = std::next(iter);
    while(next != m_queue.end())
    {
        next = std::next(iter);
        if(*iter > *next)
        {
            std::swap(*iter, *next);
        }
        iter ++;
        next = std::next(iter);
    }
}
