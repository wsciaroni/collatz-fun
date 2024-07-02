#pragma once

using uint128_t = unsigned __int128;

class IDictionary
{
public:
    virtual bool isInDict(const uint128_t value) { return false; };
    virtual void insert(const uint128_t key, const uint128_t value) { return; };
    virtual uint128_t get(const uint128_t key) { return 0; };
};
