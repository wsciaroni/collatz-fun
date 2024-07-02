#pragma once

#include <cstdint>

class IDictionary
{
public:
    virtual bool isInDict(const uint64_t value) = 0;
    virtual void insert(const uint64_t key, const uint64_t value) = 0;
    virtual uint64_t get(const uint64_t key) = 0;
};
