#pragma once

#include <list>
#include "../Include/Person.hpp"

class QueueFight
{
public:
    QueueFight() = default;
    void push(const Person p_person);
    std::list<Person> m_queue = {};

private:
    void sort();
    void moveTwoOrMoreBlondGirlsAheadKarate();
    void moveTenHipisesToFront();
};
