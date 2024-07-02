#pragma once

#include "IDictionary.hpp"

#include <type_traits>

class MockDictionary;

template <typename DictType = bool>
class CollatzSolver
{
public:
    CollatzSolver() : fake(), d(fake) {}
    CollatzSolver(DictType &dictionaryIn) : fake(), d(dictionaryIn) {}

    uint128_t solve(const uint128_t value)
    {
        return solve_impl(value, std::is_base_of<IDictionary, DictType>{});
    };

private:
    bool isEven(const uint128_t value)
    {
        return 0 == (value % 2);
    }
    template <typename T = DictType> // Add template parameter T here
    uint128_t solve_impl(const uint128_t value, std::true_type)
    {
        if (d.isInDict(value))
        {
            return d.get(value);
        }

        uint128_t answer;
        if (1 == value)
        {
            answer = 0;
        }
        else if (isEven(value))
        {
            answer = 1 + solve(value / 2);
        }
        else
        {
            answer = 1 + solve((3 * value) + 1);
        }
        d.insert(value, answer);
        return answer;
    }

    template <typename T = DictType> // Add template parameter T here
    uint128_t solve_impl(const uint128_t value, std::false_type)
    {
        if (1 == value)
        {
            return 0;
        }

        if (isEven(value))
        {
            return 1 + solve(value / 2);
        }
        else
        {
            return 1 + solve((3 * value) + 1);
        }
    }

    DictType fake;
    DictType &d;
};