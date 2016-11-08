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
    int x = 10, y = 10;
    int z = y + (x --);
    std::cout << "z = " << z << ", x = " << x << std::endl;
    Person p0(0, PERSON_TYPE::KARATE), p1(1, PERSON_TYPE::BARBARIAN);
    std::list<Person> list;
    list.push_front(p0);
    list.push_front(p1);

    std::for_each(list.begin(), list.end(), [](const Person& p_person)
                                            {std::cout << "id = " << p_person.id() << ", type = " << (int)p_person.type() << std::endl;});

    auto front = list.begin();
    auto next = std::next(front);
    std::swap(*front, *next);

    std::for_each(list.begin(), list.end(), [](const Person& p_person)
                                            {std::cout << "id = " << p_person.id() << ", type = " << (int)p_person.type() << std::endl;});

    return 0;
}
