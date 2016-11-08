#include "gtest/gtest.h"
#include "../Include/QueueFight.hpp"
#include "../Include/Person.hpp"
#include <list>

TEST(QueueFightTestSuite, KarateShouldWinHipis)
{
    QueueFight qf;
    Person p0(0, PERSON_TYPE::KARATE), p1(1, PERSON_TYPE::HIPIS);

    qf.push(p1);
    qf.push(p0);

    std::list<Person> list{p1, p0};

    ASSERT_EQ(qf.m_queue, list);
}

TEST(QueueFightTestSuite, BarbarianShouldWinKarate)
{
    QueueFight qf;
    Person p0(0, PERSON_TYPE::KARATE), p1(1, PERSON_TYPE::BARBARIAN);

    qf.push(p0);
    qf.push(p1);

    std::list<Person> list{p0, p1};

    ASSERT_EQ(qf.m_queue, list);
}

TEST(QueueFightTestSuite, ScienceGirlShouldWinBlondGirl)
{
    QueueFight qf;
    Person p0(0, PERSON_TYPE::BLONDGIRL), p1(1, PERSON_TYPE::SCIENCEGIRL);

    qf.push(p0);
    qf.push(p1);

    std::list<Person> list{p0, p1};

    ASSERT_EQ(qf.m_queue, list);
}

TEST(QueueFightTestSuite,TwoOrMoreBlondGirlsShouldWinKarate)
{
    QueueFight qf;
    Person p0(0, PERSON_TYPE::BLONDGIRL), p1(1, PERSON_TYPE::BLONDGIRL), p2(2, PERSON_TYPE::BLONDGIRL), 
           p3(3, PERSON_TYPE::KARATE), p4(4, PERSON_TYPE::KARATE);

    qf.push(p4);
    qf.push(p3);
    qf.push(p2);
    qf.push(p1);
    qf.push(p0);

    std::list<Person> list{p0, p3, p4, p1, p2};
    ASSERT_EQ(qf.m_queue, list);
}
