
#include "IDictionary.hpp"

#include "MockDictionary.hpp"

#include <gtest/gtest.h>

class FakeDictionary : public IDictionary
{
public:
    bool isInDict(const uint128_t value) override { return false; };
    void insert(const uint128_t key, const uint128_t value) override {};
    uint128_t get(const uint128_t key) override { return key; };
};

TEST(IDictionary, isInDict)
{
    FakeDictionary d;
    EXPECT_FALSE(d.isInDict(1));
}

TEST(IDictionary, insert)
{
    FakeDictionary d;
    d.insert(1, 1);
}

TEST(IDictionary, get)
{
    FakeDictionary d;
    d.get(1);
}

TEST(MockDictionary, initial)
{
    MockDictionary mockDict;
}
