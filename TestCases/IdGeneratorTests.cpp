#include "gtest/gtest.h"
#include "../Include/IdGenerator.hpp"

TEST(IdGeneratorTestSuite, AllocatedIdsShouldBeSequencedUnsignedIntegers)
{
    unsigned int l_id0 = IdGenerator::allocate();
    unsigned int l_id1 = IdGenerator::allocate();
    unsigned int l_id2 = IdGenerator::allocate();
    
    ASSERT_EQ(0, l_id0);
    ASSERT_EQ(1, l_id1);
    ASSERT_EQ(2, l_id2);
}
