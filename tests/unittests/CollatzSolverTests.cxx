
#include <gtest/gtest.h>

#include "CollatzSolver.hpp"
#include "MockDictionary.hpp"

TEST(collatz, one)
{
    CollatzSolver solver;
    EXPECT_EQ(solver.solve(1), 0);
}

TEST(collatz, two)
{
    CollatzSolver solver;
    EXPECT_EQ(solver.solve(2), 1);
}

TEST(collatz, five)
{
    CollatzSolver solver;
    EXPECT_EQ(solver.solve(5), 5);
}

TEST(collatz, six)
{
    CollatzSolver solver;
    EXPECT_EQ(solver.solve(6), 8);
}

TEST(collatz, twentySeven)
{
    CollatzSolver solver;
    EXPECT_EQ(solver.solve(27), 111);
}

TEST(CachedCollatz, one)
{
    CollatzSolver<MockDictionary> solver;

    EXPECT_EQ(solver.solve(1), 15);
}