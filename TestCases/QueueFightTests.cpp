#include "gtest/gtest.h"
#include "../Include/QueueFight.hpp"
#include "../Include/Person.hpp"

TEST(QueueFightTestSuite, KarateShouldWinHipis)
{
    QueueFight qf;
    Person p0(0, PERSON_TYPE::KARATE), p1(1, PERSON_TYPE::HIPIS);

    qf.push(p1);
    qf.push(p0);

    ASSERT_EQ(qf.m_queue[0], p0);
    ASSERT_EQ(qf.m_queue[1], p1);
}

TEST(QueueFightTestSuite, BarbarianShouldWinKarate)
{
    QueueFight qf;
    Person p0(0, PERSON_TYPE::KARATE), p1(1, PERSON_TYPE::BARBARIAN);

    qf.push(p0);
    qf.push(p1);

    ASSERT_EQ(qf.m_queue[0], p1);
    ASSERT_EQ(qf.m_queue[1], p0);
}

TEST(QueueFightTestSuite, ScienceGirlShouldWinBlondGirl)
{
    QueueFight qf;
    Person p0(0, PERSON_TYPE::BLONDGIRL), p1(1, PERSON_TYPE::SCIENCEGIRL);

    qf.push(p0);
    qf.push(p1);

    ASSERT_EQ(qf.m_queue[0], p1);
    ASSERT_EQ(qf.m_queue[1], p0);
}
