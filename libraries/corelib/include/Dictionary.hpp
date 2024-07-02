#pragma once

#include "IDictionary.hpp"

#include <atomic>
#include <unordered_map>
#include <shared_mutex>

class KeyNotFoundException : std::exception {};

template <typename KeyType, typename ValueType>
class Dictionary : public IDictionary
{
public:
    bool isInDict(const uint64_t key) override
    {
        std::shared_lock lock(mutex);
        auto it = map.find(key);
        bool found = it != map.end();
        return found;
    }
    void insert(const uint64_t key, const uint64_t value) override
    {
        std::unique_lock lock(mutex);
        map.insert_or_assign(key, value);
    }
    uint64_t get(const uint64_t key) override
    {
        std::shared_lock lock(mutex);
        auto it = map.find(key);
        bool found = it != map.end();
        if(!found)
        {
            throw KeyNotFoundException();
        }
        return it->second;
    }
private:
    std::unordered_map<KeyType, std::atomic<ValueType>> map;
    mutable std::shared_mutex mutex;
};