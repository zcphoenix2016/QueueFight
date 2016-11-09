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
        if(PERSON_TYPE::BARBARIAN == iter->type()
            && PERSON_TYPE::BARBARIAN == next->type())
        {
            m_queue.erase(iter);
            break;
        }
        if(*iter > *next)
        {
            std::swap(*iter, *next);
        }
        iter ++;
        next = std::next(iter);
    }

    moveTwoOrMoreBlondGirlsAheadKarate();
}

void QueueFight::moveTwoOrMoreBlondGirlsAheadKarate()
{
    auto isBlondGirl = [](const Person& p){return PERSON_TYPE::BLONDGIRL == p.type();};
    auto iterFirstBlondGirl = std::find_if(m_queue.begin(), m_queue.end(), isBlondGirl);
    auto iterFirstNonBlondGirl = std::find_if_not(iterFirstBlondGirl, m_queue.end(), isBlondGirl);
    while(iterFirstNonBlondGirl != m_queue.end()
            && PERSON_TYPE::KARATE == iterFirstNonBlondGirl->type()
            && 2 <= std::distance(iterFirstBlondGirl, iterFirstNonBlondGirl))
    {
        auto isKarateMan = [](const Person& p){return PERSON_TYPE::KARATE == p.type();};
        auto iterFirstNonKarate = std::find_if_not(iterFirstNonBlondGirl, m_queue.end(), isKarateMan);
        m_queue.insert(iterFirstBlondGirl, iterFirstNonBlondGirl, iterFirstNonKarate);
        m_queue.erase(iterFirstNonBlondGirl, iterFirstNonKarate);

        iterFirstNonBlondGirl = std::find_if_not(iterFirstBlondGirl, m_queue.end(), isBlondGirl);
    }
}
