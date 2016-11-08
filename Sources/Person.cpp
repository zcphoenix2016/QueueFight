#include "../Include/Person.hpp"


bool operator==(const Person& p_lhs, const Person& p_rhs)
{
    return (p_lhs.id() == p_rhs.id()) and (p_lhs.type() == p_rhs.type());
}

bool operator>(const Person& p_lhs, const Person& p_rhs)
{
    return (p_lhs.type() == PERSON_TYPE::KARATE && p_rhs.type() == PERSON_TYPE::HIPIS)
           || (p_lhs.type() == PERSON_TYPE::BARBARIAN && p_rhs.type() == PERSON_TYPE::KARATE)
           || (p_lhs.type() == PERSON_TYPE::SCIENCEGIRL && p_rhs.type() == PERSON_TYPE::BLONDGIRL);
}
