#include "gtest/gtest.h"
#include "../Include/QueueFight.hpp"
#include "../Include/Person.hpp"
#include <list>

class QueueFightTestSuite : public ::testing::Test
{
public:
    QueueFightTestSuite()
    {
    }

    void SetUp() override
    {
    }

    void TearDown() override
    {
    }

    QueueFight qf;
    std::list<Person> list = {};
};

TEST_F(QueueFightTestSuite, KarateShouldWinHipis)
{
    Person p0(0, PERSON_TYPE::KARATE), p1(1, PERSON_TYPE::HIPIS);

    qf.push(p1);
    qf.push(p0);

    list = {p1, p0};

    ASSERT_EQ(qf.m_queue, list);
}

TEST_F(QueueFightTestSuite, BlondGirlShouldWinHipis)
{
    Person p0(0, PERSON_TYPE::BLONDGIRL), p1(1, PERSON_TYPE::HIPIS);

    qf.push(p1);
    qf.push(p0);

    list = {p1, p0};

    ASSERT_EQ(qf.m_queue, list);
}

TEST_F(QueueFightTestSuite, ScienceGirlShouldWinHipis)
{
    Person p0(0, PERSON_TYPE::SCIENCEGIRL), p1(1, PERSON_TYPE::HIPIS);

    qf.push(p1);
    qf.push(p0);

    list = {p1, p0};

    ASSERT_EQ(qf.m_queue, list);
}

TEST_F(QueueFightTestSuite, BararianShouldWinHipis)
{
    Person p0(0, PERSON_TYPE::BARBARIAN), p1(1, PERSON_TYPE::HIPIS);

    qf.push(p1);
    qf.push(p0);

    list = {p1, p0};

    ASSERT_EQ(qf.m_queue, list);
}

TEST_F(QueueFightTestSuite, BarbarianShouldWinKarate)
{
    Person p0(0, PERSON_TYPE::KARATE), p1(1, PERSON_TYPE::BARBARIAN);

    qf.push(p0);
    qf.push(p1);

    list = {p0, p1};

    ASSERT_EQ(qf.m_queue, list);
}

TEST_F(QueueFightTestSuite, ScienceGirlShouldWinBlondGirl)
{
    Person p0(0, PERSON_TYPE::BLONDGIRL), p1(1, PERSON_TYPE::SCIENCEGIRL);

    qf.push(p0);
    qf.push(p1);

    list = {p0, p1};

    ASSERT_EQ(qf.m_queue, list);
}

TEST_F(QueueFightTestSuite,TwoOrMoreBlondGirlsShouldWinKarate)
{
    Person p0(0, PERSON_TYPE::BLONDGIRL), p1(1, PERSON_TYPE::BLONDGIRL), p2(2, PERSON_TYPE::BLONDGIRL), 
           p3(3, PERSON_TYPE::KARATE), p4(4, PERSON_TYPE::KARATE);

    qf.push(p4);
    qf.push(p2);
    qf.push(p3);
    qf.push(p1);
    qf.push(p0);

    list = {p3, p4, p0, p1, p2};

    ASSERT_EQ(qf.m_queue, list);
}

TEST_F(QueueFightTestSuite, ScienceGirlShouldWinBararian)
{
    Person p0(0, PERSON_TYPE::SCIENCEGIRL), p1(1, PERSON_TYPE::BARBARIAN);

    qf.push(p1);
    qf.push(p0);

    list = {p1, p0};

    ASSERT_EQ(qf.m_queue, list);
}

TEST_F(QueueFightTestSuite, NewHipisShouldWinExistingHipis)
{
    Person p0(0, PERSON_TYPE::HIPIS), p1(1, PERSON_TYPE::HIPIS), p2(2, PERSON_TYPE::HIPIS);

    qf.push(p2);
    qf.push(p1);
    qf.push(p0);

    list = {p2, p1, p0};

    ASSERT_EQ(qf.m_queue, list);
}

TEST_F(QueueFightTestSuite, NewBararianBehindExistingBararianShouldBeDiscarded)
{
    Person p0(0, PERSON_TYPE::BARBARIAN), p1(1, PERSON_TYPE::BARBARIAN), p2(2, PERSON_TYPE::KARATE);

    qf.push(p2);
    qf.push(p1);
    qf.push(p0);

    list = {p2, p1};

    ASSERT_EQ(qf.m_queue, list);
}

TEST_F(QueueFightTestSuite, TenHipisShouldBeMovedToTheFront)
{
    std::vector<Person> vec = {};
    vec.push_back({0, PERSON_TYPE::KARATE});
    vec.push_back({1, PERSON_TYPE::BARBARIAN});
    unsigned int index = 0;
    for(index = 2; index <= 12; ++ index)
    {
        vec.push_back({index, PERSON_TYPE::HIPIS});
    }

    for(index = 0; index < vec.size(); ++ index)
    {
        qf.push(vec[index]);
    }

    for(index = 0; index < vec.size() - 1; ++ index)
    {
        list.push_back(vec[index]);
    }
    list.push_front(vec[vec.size() - 1]);

    ASSERT_EQ(qf.m_queue, list);
}
