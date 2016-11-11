#include "../Include/QueueFight.hpp"
#include <iterator>
#include <algorithm>

void QueueFight::push(const Person p_person)
{
    if(MAX_SIZE <= m_queue.size())
    {
        return;
    }
    
    m_queue.push_front(p_person);

    sort();
    moveTwoOrMoreBlondGirlsAheadKarate();
    moveTenHipisesToFront();
}

void QueueFight::sort()
{
    auto l_iter = m_queue.begin();
    auto l_next = std::next(l_iter);
    while(l_next != m_queue.end())
    {
        if(not (*l_iter > *l_next))
        {
            if(PERSON_TYPE::BARBARIAN == l_iter->type()
                && PERSON_TYPE::BARBARIAN == l_next->type())
            {
                m_queue.erase(l_iter);
            }
            break;
        }
        else
        {
            std::swap(*l_iter, *l_next);
            l_iter ++;
            l_next = std::next(l_iter);
        }
    }
}

void QueueFight::moveTwoOrMoreBlondGirlsAheadKarate()
{
    auto l_isBlondGirl = [](const Person& p){return PERSON_TYPE::BLONDGIRL == p.type();};
    auto l_iterFirstBlondGirl = std::find_if(m_queue.begin(), m_queue.end(), l_isBlondGirl);
    auto l_iterFirstNonBlondGirl = std::find_if_not(l_iterFirstBlondGirl, m_queue.end(), l_isBlondGirl);
    while(l_iterFirstNonBlondGirl != m_queue.end()
            && PERSON_TYPE::KARATE == l_iterFirstNonBlondGirl->type()
            && 2 <= std::distance(l_iterFirstBlondGirl, l_iterFirstNonBlondGirl))
    {
        auto l_isKarateMan = [](const Person& p){return PERSON_TYPE::KARATE == p.type();};
        auto l_iterFirstNonKarate = std::find_if_not(l_iterFirstNonBlondGirl, m_queue.end(), l_isKarateMan);
        m_queue.insert(l_iterFirstBlondGirl, l_iterFirstNonBlondGirl, l_iterFirstNonKarate);
        m_queue.erase(l_iterFirstNonBlondGirl, l_iterFirstNonKarate);

        l_iterFirstNonBlondGirl = std::find_if_not(l_iterFirstBlondGirl, m_queue.end(), l_isBlondGirl);
    }
}

void QueueFight::moveTenHipisesToFront()
{
    auto l_isHipis = [](const Person& p){return PERSON_TYPE::HIPIS == p.type();};
    auto l_iterFirstHipis = std::find_if(m_queue.begin(), m_queue.end(), l_isHipis);
    auto l_iterFirstNonHipis = std::find_if_not(m_queue.begin(), m_queue.end(), l_isHipis);
    if(l_iterFirstNonHipis != m_queue.end()
        && 10 <= std::distance(l_iterFirstHipis, l_iterFirstNonHipis))
    {
        m_queue.insert(m_queue.end(), l_iterFirstHipis, l_iterFirstNonHipis);
        m_queue.erase(l_iterFirstHipis, l_iterFirstNonHipis);
    }
}
