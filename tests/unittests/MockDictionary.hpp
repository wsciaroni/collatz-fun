#pragma once

#include <gmock/gmock.h>

#include "IDictionary.hpp"

class MockDictionary : public IDictionary
{
public:
    MockDictionary(/* args */);
    ~MockDictionary();

    MOCK_METHOD(bool, isInDict, (const uint64_t value));
    MOCK_METHOD(void, insert, (const uint64_t key, const uint64_t value));
    MOCK_METHOD(uint64_t, get, (const uint64_t key));
};
