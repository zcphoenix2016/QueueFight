#include "../Include/Person.hpp"

bool Person::operator==(const Person& p_rhs) const
{
    return (m_id == p_rhs.id()) and (m_type == p_rhs.type());
}

bool Person::operator>(const Person& p_rhs) const
{
    return (p_rhs.type() == PERSON_TYPE::HIPIS)
            || (m_type == PERSON_TYPE::BARBARIAN && p_rhs.type() == PERSON_TYPE::KARATE)
            || (m_type == PERSON_TYPE::SCIENCEGIRL && p_rhs.type() == PERSON_TYPE::BLONDGIRL)
            || (m_type == PERSON_TYPE::SCIENCEGIRL && p_rhs.type() == PERSON_TYPE::BARBARIAN);
}
