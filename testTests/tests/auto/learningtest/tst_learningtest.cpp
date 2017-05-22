#include "quadratic.h"
#include <gtest/gtest.h>

#include <QDebug>

TEST(EquationSolverTest, returnTwoEquationRoots_validsArgumentsPass)
{
    EquationSolver solver;
    Result res = solver.solve(5, 9, 2);
    ASSERT_NEAR(-1.5403, res.x1, 0.0001);
    ASSERT_NEAR(-0.2596, res.x2, 0.0001);
    ASSERT_EQ(Status::Solved, res.status);
}

TEST(EquationSolverTest, returnError_descriminantIsNegative)
{
    EquationSolver solver;
    Result res = solver.solve(100, 9, 90);
    ASSERT_NEAR(0.0, res.x1, 0.0001);
    ASSERT_NEAR(0.0, res.x2, 0.0001);
    ASSERT_EQ(Status::RealRootsAbsent, res.status);
}

TEST(EquationSolverTest, returnEqualRoots_descriminantIsEqualToZero)
{
    EquationSolver solver;
    Result res = solver.solve(2, 10, 12.5);
    ASSERT_NEAR(-2.5, res.x1, 0.0001);
    ASSERT_NEAR(res.x2, res.x1, 0.0001);
    ASSERT_EQ(Status::Solved, res.status);
}

TEST(EquationSolverTest, returnEqualRoots_aIsZero)
{
    EquationSolver solver;
    Result res = solver.solve(0, 2, 4);
    ASSERT_NEAR(-2.0, res.x1, 0.0001);
    ASSERT_NEAR(res.x2, res.x1, 0.0001);
    ASSERT_EQ(Status::Solved, res.status);
}

TEST(EquationSolverTest, returnEqualRoots_cIsZero)
{
    EquationSolver solver;
    Result res = solver.solve(2, -4, 0);
    ASSERT_NEAR(0.0, res.x1, 0.0001);
    ASSERT_NEAR(2.0, res.x2, 0.0001);
    ASSERT_EQ(Status::Solved, res.status);
}

TEST(EquationSolverTest, returnEqualRoots_bIsZero)
{
    EquationSolver solver;
    Result res = solver.solve(2, 0, -8);
    ASSERT_NEAR(2.0, res.x1, 0.0001);
    ASSERT_NEAR(res.x2, res.x1, 0.0001);
    ASSERT_EQ(Status::Solved, res.status);
}

TEST(EquationSolverTest, returnEqualRoots_aAndbAreZero)
{
    EquationSolver solver;
    Result res = solver.solve(0, 0, -8);
    ASSERT_EQ(Status::Unsolved, res.status);
}

TEST(EquationSolverTest, returnRootsEqualToZero_aAndbAndcAreZero)
{
    EquationSolver solver;
    Result res = solver.solve(0, 0, 0);
    ASSERT_NEAR(0.0, res.x1, 0.0001);
    ASSERT_NEAR(res.x2, res.x1, 0.0001);
    ASSERT_EQ(Status::InfiniteRoots, res.status);
}

TEST(EquationSolverTest, returnEqualRoots_aAndcIsZero)
{
    EquationSolver solver;
    Result res = solver.solve(0, 3, 0);
    ASSERT_NEAR(0.0, res.x1, 0.0001);
    ASSERT_NEAR(res.x2, res.x1, 0.0001);
    ASSERT_EQ(Status::Solved, res.status);
}
