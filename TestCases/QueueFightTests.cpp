#include "gtest/gtest.h"
#include "../Include/QueueFight.hpp"
#include "../Include/Person.hpp"
#include <list>
#include <vector>
#include <utility>

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

    QueueFight m_qf;
    std::list<Person> m_result = {};
};

class QueueFightTwoPersonsComparisonTestSuite : public QueueFightTestSuite,
                                                public ::testing::WithParamInterface<std::pair<Person, Person>>
{
};


TEST_P(QueueFightTwoPersonsComparisonTestSuite, checkTwoPersonsComparisonResult)
{
    const Person l_first = GetParam().first;
    const Person l_second = GetParam().second;
    
    m_qf.push(l_second);
    m_qf.push(l_first);
    
    m_result = {l_second, l_first};
    
    ASSERT_EQ(m_qf.m_queue, m_result);
}

INSTANTIATE_TEST_CASE_P(QueueFightTwoPersonsComparisonTests,
                        QueueFightTwoPersonsComparisonTestSuite,
                        ::testing::Values(std::make_pair<Person, Person>({0, PERSON_TYPE::HIPIS}, {1, PERSON_TYPE::HIPIS}),
                                          std::make_pair<Person, Person>({0, PERSON_TYPE::KARATE}, {1, PERSON_TYPE::HIPIS}),
                                          std::make_pair<Person, Person>({0, PERSON_TYPE::BLONDGIRL}, {1, PERSON_TYPE::HIPIS}),
                                          std::make_pair<Person, Person>({0, PERSON_TYPE::SCIENCEGIRL}, {1, PERSON_TYPE::HIPIS}),
                                          std::make_pair<Person, Person>({0, PERSON_TYPE::BARBARIAN}, {1, PERSON_TYPE::HIPIS}),
                                          std::make_pair<Person, Person>({0, PERSON_TYPE::BARBARIAN}, {1, PERSON_TYPE::KARATE}),
                                          std::make_pair<Person, Person>({0, PERSON_TYPE::SCIENCEGIRL}, {1, PERSON_TYPE::BLONDGIRL}),
                                          std::make_pair<Person, Person>({0, PERSON_TYPE::SCIENCEGIRL}, {1, PERSON_TYPE::BARBARIAN})));

TEST_F(QueueFightTestSuite, TwoOrMoreBlondGirlsShouldWinKarate)
{
    Person p0(0, PERSON_TYPE::BLONDGIRL), p1(1, PERSON_TYPE::BLONDGIRL), p2(2, PERSON_TYPE::BLONDGIRL), 
           p3(3, PERSON_TYPE::KARATE), p4(4, PERSON_TYPE::KARATE);

    m_qf.push(p4);
    m_qf.push(p2);
    m_qf.push(p3);
    m_qf.push(p1);
    m_qf.push(p0);

    m_result = {p3, p4, p0, p1, p2};

    ASSERT_EQ(m_qf.m_queue, m_result);
}

TEST_F(QueueFightTestSuite, NewBararianBehl_indexistingBararianShouldBeDiscarded)
{
    Person p0(0, PERSON_TYPE::BARBARIAN), p1(1, PERSON_TYPE::BARBARIAN), p2(2, PERSON_TYPE::KARATE);

    m_qf.push(p2);
    m_qf.push(p1);
    m_qf.push(p0);

    m_result = {p2, p1};

    ASSERT_EQ(m_qf.m_queue, m_result);
}

TEST_F(QueueFightTestSuite, TenHipisShouldBeMovedToTheFront)
{
    std::vector<Person> l_vec = {};
    l_vec.push_back({0, PERSON_TYPE::KARATE});
    l_vec.push_back({1, PERSON_TYPE::BARBARIAN});
    
    unsigned int l_index = 0;
    for(l_index = 2; l_index <= 12; ++ l_index)
    {
        l_vec.push_back({l_index, PERSON_TYPE::HIPIS});
    }

    for(l_index = 0; l_index < l_vec.size(); ++ l_index)
    {
        m_qf.push(l_vec[l_index]);
    }

    for(l_index = 0; l_index < l_vec.size() - 1; ++ l_index)
    {
        m_result.push_back(l_vec[l_index]);
    }
    m_result.push_front(l_vec[l_vec.size() - 1]);

    ASSERT_EQ(m_qf.m_queue, m_result);
}

TEST_F(QueueFightTestSuite, TheQueueShouldNotContainMoreThanTwentyPersons)
{
    for(unsigned int l_index = 0; l_index < 20; ++ l_index)
    {
        m_result.push_front({l_index, PERSON_TYPE::KARATE});
        m_qf.push({l_index, PERSON_TYPE::KARATE});
    }
    
    m_qf.push({20, PERSON_TYPE::BARBARIAN});
    
    ASSERT_EQ(m_qf.m_queue, m_result);
}