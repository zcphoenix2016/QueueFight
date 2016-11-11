#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "../Include/QueueFight.hpp"
#include "../Include/Person.hpp"

#ifndef UNIT_TEST
int main(int argc, char** argv)
#else
int ut_main(int argc, char** argv)
#endif
{
    Person l_p0(0, PERSON_TYPE::KARATE), l_p1(1, PERSON_TYPE::BARBARIAN);
    std::list<Person> l_list;
    l_list.push_front(l_p0);
    l_list.push_front(l_p1);

    std::for_each(l_list.begin(), l_list.end(), [](const Person& p_person)
                                            {std::cout << "id = " << p_person.id() << ", type = " << (int)p_person.type() << std::endl;});

    auto l_front = l_list.begin();
    auto l_next = std::next(l_front);
    std::swap(*l_front, *l_next);

    std::for_each(l_list.begin(), l_list.end(), [](const Person& p_person)
                                            {std::cout << "id = " << p_person.id() << ", type = " << (int)p_person.type() << std::endl;});

    return 0;
}
