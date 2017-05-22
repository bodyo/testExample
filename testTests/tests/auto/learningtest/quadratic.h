#ifndef QUADRATIC_H
#define QUADRATIC_H

enum class Status{Solved, RealRootsAbsent, InfiniteRoots, Unsolved};

struct Result
{
    Result() = default;
    Result(Status _Status);
    double x1{0};
    double x2{0};
    Status status{Status::RealRootsAbsent};
};

/*!
 * doxygen docs
 * \brief The EquationSolver class
 */
class EquationSolver
{
public:
    Result solve(double a, double b, double c);

private:
    bool isRootsAreInfinit(double a, double b, double c);
    bool isRootsAreAbsent(double a, double b, double c);
    bool isEquationIsLinear(double a, double b, double c);
    bool isEquationIsQuadratic(double a, double b, double c);

    Result solveAsLinear(double b, double c);
    Result solveAsQuadratic(double a, double c);
    Result solveAsFullQuadratic(double a, double b, double c);
};

#endif // QUADRATIC_H
