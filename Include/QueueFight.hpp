#pragma once

#include <list>
#include "../Include/Person.hpp"

const unsigned int MAX_SIZE = 20;

class QueueFight
{
public:
    void push(const Person p_person);
    std::list<Person> m_queue = {};

private:
    void sort();
    void moveTwoOrMoreBlondGirlsAheadKarate();
    void moveTenHipisesToFront();
};
