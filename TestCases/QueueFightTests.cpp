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

    QueueFight qf;
    std::list<Person> list = {};
};

class QueueFightTwoPersonsComparisonTestSuite : public QueueFightTestSuite,
                                                public ::testing::WithParamInterface<std::pair<Person, Person>>
{
};


TEST_P(QueueFightTwoPersonsComparisonTestSuite, checkTwoPersonsComparisonResult)
{
    const Person l_first = GetParam().first;
    const Person l_second = GetParam().second;
    
    qf.push(l_second);
    qf.push(l_first);
    
    list = {l_second, l_first};
    
    ASSERT_EQ(qf.m_queue, list);
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

TEST_F(QueueFightTestSuite, TheQueueShouldNotContainMoreThanTwentyPersons)
{
    for(unsigned int index = 0; index < 20; ++ index)
    {
        list.push_front({index, PERSON_TYPE::KARATE});
        qf.push({index, PERSON_TYPE::KARATE});
    }
    
    qf.push({20, PERSON_TYPE::BARBARIAN});
    
    ASSERT_EQ(qf.m_queue, list);
}