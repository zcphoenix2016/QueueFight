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
    Person(const Person& rhs)
    {
        m_id = rhs.m_id;
        m_type = rhs.m_type;
    }
    unsigned int id() const
    {
        return m_id;
    }
    PERSON_TYPE type() const
    {
        return m_type;
    }
    
    bool operator==(const Person& p_rhs) const;
    bool operator>(const Person& p_rhs) const;

private:
    unsigned int m_id = 0;
    PERSON_TYPE m_type = PERSON_TYPE::HIPIS;
};
