
#include "IDictionary.hpp"

#include "MockDictionary.hpp"

#include <gtest/gtest.h>
#include <cstdint>

class FakeDictionary : public IDictionary
{
public:
    bool isInDict(const uint64_t value) override { return false; };
    void insert(const uint64_t key, const uint64_t value) override {};
    uint64_t get(const uint64_t key) override { return key; };
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
