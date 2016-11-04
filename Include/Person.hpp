#pragma once

enum class PERSON_TYPE
{
    KARATE,
    BLONDGIRL,
    BARBARIAN,
    SCIENCEGIRL,
    HIPIS
};

class Person
{
public:
    Person(unsigned int p_id, PERSON_TYPE p_type) : m_id(p_id), m_type(p_type)
    {
    }
    unsigned int getId() const
    {
        return m_id;
    }
    PERSON_TYPE getType() const
    {
        return m_type;
    }

private:
    unsigned int m_id = 0;
    PERSON_TYPE m_type = PERSON_TYPE::HIPIS;
};

bool operator==(const Person& p_lhs, const Person& p_rhs);
bool operator>(const Person& p_lhs, const Person& p_rhs);
