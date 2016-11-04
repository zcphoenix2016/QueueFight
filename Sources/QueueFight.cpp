#include "../Include/QueueFight.hpp"
#include <iterator>

void QueueFight::push(const Person p_person)
{
    m_queue.push_back(p_person);

    std::vector<Person>::reverse_iterator iterNew = m_queue.rbegin();
    while(iterNew != m_queue.rend() - 1)
    {
        if(*iterNew > *(iterNew + 1))
        {
            std::swap(*iterNew, *(iterNew + 1));
        }
        iterNew ++;
    }
}
