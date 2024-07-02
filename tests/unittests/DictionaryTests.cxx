
#include <gtest/gtest.h>

#include "Dictionary.hpp"

TEST(DictionaryTests, isInDict)
{
    Dictionary<uint64_t, uint64_t> d;
    EXPECT_FALSE(d.isInDict(1));
    d.insert(1, 15);
    EXPECT_TRUE(d.isInDict(1));
    EXPECT_EQ(d.get(1), 15);
}

TEST(DictionaryTests, badGet)
{
    Dictionary<uint64_t, uint64_t> d;
    EXPECT_FALSE(d.isInDict(1));
    EXPECT_THROW(d.get(1), KeyNotFoundException);
}