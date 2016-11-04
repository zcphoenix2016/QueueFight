#pragma once

#include <vector>
#include "../Include/Person.hpp"

class QueueFight
{
public:
    QueueFight() = default;
    void push(const Person p_person);
    std::vector<Person> m_queue;
};
