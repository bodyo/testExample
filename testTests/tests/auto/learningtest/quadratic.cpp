#include "quadratic.h"
#include <math.h>

Result EquationSolver::solve(double a, double b, double c)
{
    if (isRootsAreInfinit(a, b, c))
        return Result(Status::InfiniteRoots);

    if (isRootsAreAbsent(a, b, c))
        return Result(Status::Unsolved);

    if (isEquationIsLinear(a, b, c))
        return solveAsLinear(b, c);

    else if (isEquationIsQuadratic(a, b, c))
        return solveAsQuadratic(a, c);

    else
        return solveAsFullQuadratic(a, b, c);
}

bool EquationSolver::isRootsAreInfinit(double a, double b, double c)
{
    return (a == 0 && b == 0 && c == 0);
}

bool EquationSolver::isRootsAreAbsent(double a, double b, double c)
{
    return (a == 0 && b == 0 && c != 0);
}

bool EquationSolver::isEquationIsLinear(double a, double b, double c)
{
    return (a == 0 && b != 0 && c != 0);
}

bool EquationSolver::isEquationIsQuadratic(double a, double b, double c)
{
    return (a != 0 && b == 0 && c != 0);
}

Result EquationSolver::solveAsLinear(double b, double c)
{
    Result res;
    res.x1 = res.x2 = -c/b;
    res.status = Status::Solved;
    return res;
}

Result EquationSolver::solveAsQuadratic(double a, double c)
{
    Result res;
    res.x1 = res.x2 = sqrt(-c/a);
    res.status = Status::Solved;
    return res;
}

Result EquationSolver::solveAsFullQuadratic(double a, double b, double c)
{
    if (a == 0)
        return Result(Status::Solved);

    double D = (b*b) - 4*(a*c);
    if (D < 0)
        return Result(Status::RealRootsAbsent);

    Result res;
    res.x1= (-b-sqrt(D))/(2*a);
    res.x2= (-b+sqrt(D))/(2*a);
    res.status = Status::Solved;
    return res;
}

Result::Result(Status _Status)
{
    x1 = 0.0;
    x2 = 0.0;
    status = _Status;
}
