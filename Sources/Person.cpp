#include "../Include/Person.hpp"


bool operator==(const Person& p_lhs, const Person& p_rhs)
{
    return (p_lhs.getId() == p_rhs.getId()) and (p_lhs.getType() == p_rhs.getType());
}

bool operator>(const Person& p_lhs, const Person& p_rhs)
{
    return (p_lhs.getType() == PERSON_TYPE::KARATE && p_rhs.getType() == PERSON_TYPE::HIPIS)
           || (p_lhs.getType() == PERSON_TYPE::BARBARIAN && p_rhs.getType() == PERSON_TYPE::KARATE);
}
