#include "gtest/gtest.h"
#include "../Include/IdGenerator.hpp"

class IdGeneratorTestSuite : public ::testing::Test
{
public:
    IdGeneratorTestSuite()
    {
    }

    void SetUp() override
    {
        IdGenerator::clear();
    }

    void TearDown() override
    {
    }
};

TEST_F(IdGeneratorTestSuite, AllocatedIdsShouldBeSequencedUnsignedIntegers)
{
    unsigned int l_id0 = IdGenerator::allocate();
    unsigned int l_id1 = IdGenerator::allocate();
    unsigned int l_id2 = IdGenerator::allocate();
    
    ASSERT_EQ(0, l_id0);
    ASSERT_EQ(1, l_id1);
    ASSERT_EQ(2, l_id2);
}

TEST_F(IdGeneratorTestSuite, AllocatedIdShouldBeTheFirstReleasedId)
{
    unsigned int l_id0 = IdGenerator::allocate();
    unsigned int l_id1 = IdGenerator::allocate();
    unsigned int l_id2 = IdGenerator::allocate();

    IdGenerator::release(l_id1);
    
    unsigned int l_id3 = IdGenerator::allocate();

    ASSERT_EQ(l_id3, l_id1);
}

TEST_F(IdGeneratorTestSuite, ThrowExceptionWhenToReleaseUnallocatedId)
{
    ASSERT_THROW(IdGenerator::release(0), std::invalid_argument);
    ASSERT_THROW(IdGenerator::release(1), std::invalid_argument);
}

TEST_F(IdGeneratorTestSuite, TheSizeShouldBeZeroIfNoAllocation)
{
    ASSERT_EQ(0, IdGenerator::size());
}

TEST_F(IdGeneratorTestSuite, TheSizeShouldBeZeroAfterClear)
{
    unsigned int l_id0 = IdGenerator::allocate();
    unsigned int l_id1 = IdGenerator::allocate();
    unsigned int l_id2 = IdGenerator::allocate();
    
    IdGenerator::clear();
    
    ASSERT_EQ(0, IdGenerator::size());
}
