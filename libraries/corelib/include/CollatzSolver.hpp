#pragma once

#include "IDictionary.hpp"

#include <type_traits>

template <typename DictType = bool>
class CollatzSolver
{
public:
    uint128_t solve(const uint128_t value)
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
    };

private:
    bool isEven(const uint128_t value)
    {
        return 0 == (value % 2);
    }
    DictType T;
};

// template <typename DictType = bool>
// class CollatzSolver<std::enable_if<std::is_layout_compatible<DictType, IDictionary>, DictType>>
// {
// public:
//     uint128_t solve(const uint128_t value)
//     {
//         if (1 == value)
//         {
//             return 0;
//         }

//         if (isEven(value))
//         {
//             return 1 + solve(value / 2);
//         }
//         else
//         {
//             return 1 + solve((3 * value) + 1);
//         }
//     };

// private:
//     bool isEven(const uint128_t value)
//     {
//         return 0 == (value % 2);
//     }
//     DictType T;
// };