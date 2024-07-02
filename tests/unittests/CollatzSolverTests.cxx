
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

using ::testing::Return;
using ::testing::Sequence;
using ::testing::StrictMock;

TEST(CachedCollatz, one)
{
    Sequence s;
    StrictMock<MockDictionary> dict;
    CollatzSolver<MockDictionary> solver(dict);

    EXPECT_CALL(dict, isInDict(1)).InSequence(s).WillOnce(Return(false));
    EXPECT_CALL(dict, insert(1, 0)).InSequence(s);
    EXPECT_EQ(solver.solve(1), 0);
}

TEST(CachedCollatz, cacheHit)
{
    Sequence s;
    StrictMock<MockDictionary> dict;
    CollatzSolver<MockDictionary> solver(dict);

    EXPECT_CALL(dict, isInDict(3)).InSequence(s).WillOnce(Return(true));
    EXPECT_CALL(dict, get(3)).InSequence(s).WillOnce(Return(35));
    EXPECT_EQ(solver.solve(3), 35);
}

TEST(CachedCollatz, five)
{
    Sequence s;
    StrictMock<MockDictionary> dict;
    CollatzSolver<MockDictionary> solver(dict);

    EXPECT_CALL(dict, isInDict(5)).InSequence(s).WillOnce(Return(false));
    EXPECT_CALL(dict, isInDict(16)).InSequence(s).WillOnce(Return(false));
    EXPECT_CALL(dict, isInDict(8)).InSequence(s).WillOnce(Return(false));
    EXPECT_CALL(dict, isInDict(4)).InSequence(s).WillOnce(Return(false));
    EXPECT_CALL(dict, isInDict(2)).InSequence(s).WillOnce(Return(false));
    EXPECT_CALL(dict, isInDict(1)).InSequence(s).WillOnce(Return(false));

    EXPECT_CALL(dict, insert(1, 0)).InSequence(s);
    EXPECT_CALL(dict, insert(2, 1)).InSequence(s);
    EXPECT_CALL(dict, insert(4, 2)).InSequence(s);
    EXPECT_CALL(dict, insert(8, 3)).InSequence(s);
    EXPECT_CALL(dict, insert(16, 4)).InSequence(s);
    EXPECT_CALL(dict, insert(5, 5)).InSequence(s);
    
    EXPECT_EQ(solver.solve(5), 5);
}

TEST(CachedCollatz, fiveCacheHit)
{
    Sequence s;
    StrictMock<MockDictionary> dict;
    CollatzSolver<MockDictionary> solver(dict);

    EXPECT_CALL(dict, isInDict(5)).InSequence(s).WillOnce(Return(false));
    EXPECT_CALL(dict, isInDict(16)).InSequence(s).WillOnce(Return(false));
    EXPECT_CALL(dict, isInDict(8)).InSequence(s).WillOnce(Return(true));
    EXPECT_CALL(dict, get(8)).InSequence(s).WillOnce(Return(3));

    EXPECT_CALL(dict, insert(16, 4)).InSequence(s);
    EXPECT_CALL(dict, insert(5, 5)).InSequence(s);
    
    EXPECT_EQ(solver.solve(5), 5);
}
