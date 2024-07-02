
#include "CollatzSolver.hpp"
#include "Dictionary.hpp"

#include <gtest/gtest.h>

TEST(AllTogetherNow, 27)
{
    Dictionary<uint64_t, uint64_t> d;
    CollatzSolver<Dictionary<uint64_t, uint64_t>> solver;
    uint64_t answer = 0;

    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    // Timed section 1
    answer = solver.solve(27);
    // End Timed section 1
    auto end = high_resolution_clock::now();

    ASSERT_EQ(answer, 111);

    auto duration1 = duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();
    // Timed section 2
    solver.solve(82);
    answer = solver.solve(27);
    // End Timed section 2
    end = high_resolution_clock::now();

    auto duration2 = duration_cast<microseconds>(end - start);

    ASSERT_EQ(answer, 111);

    std::cout << "Time 1 " << duration1.count() << std::endl;
    std::cout << "Time 2 " << duration2.count() << std::endl;
}

TEST(AllTogetherNow, bigRange)
{
    Dictionary<uint64_t, uint64_t> d;
    CollatzSolver<Dictionary<uint64_t, uint64_t>> solver;
    CollatzSolver solverNoCache;
    uint64_t answer = 0;

    const uint64_t startRange = 1;
    const uint64_t stopRange = 300;

    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    // Timed section 1
    #pragma omp parallel for
    for (uint64_t i = startRange; i < stopRange; i++)
    {
        answer = solverNoCache.solve(i);
    }
    // End Timed section 1
    auto end = high_resolution_clock::now();

    auto duration1 = duration_cast<microseconds>(end - start);

    start = high_resolution_clock::now();
    // Timed section 1
    #pragma omp parallel for
    for (uint64_t i = startRange; i < stopRange; i++)
    {
        answer = solver.solve(i);
    }
    // End Timed section 1
    end = high_resolution_clock::now();

    auto duration2 = duration_cast<microseconds>(end - start);

    std::cout << "Time 1 " << duration1.count() << std::endl;
    std::cout << "Time 2 " << duration2.count() << std::endl;
}