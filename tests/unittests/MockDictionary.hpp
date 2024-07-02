#pragma once

#include <gmock/gmock.h>

#include "IDictionary.hpp"

using uint128_t = unsigned __int128;

class MockDictionary : public IDictionary
{
public:
    MockDictionary(/* args */);
    ~MockDictionary();

    MOCK_METHOD(bool, isInDict, (const uint128_t value));
    MOCK_METHOD(void, insert, (const uint128_t key, const uint128_t value));
    MOCK_METHOD(uint128_t, get, (const uint128_t key));
};
