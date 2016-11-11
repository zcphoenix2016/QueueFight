#include "gtest/gtest.h"
#include "../Include/IdGenerator.hpp"

TEST(IdGeneratorTestSuite, TheFirstAllocatedIdShouldBeZero)
{
    unsigned int l_id = IdGenerator::allocate();
    
    ASSERT_EQ(0, l_id);
}
