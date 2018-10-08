#ifndef _SAT_SOLVER_H
#define _SAT_SOLVER_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

class SatSolver
{
public:
    virtual ~SatSolver(){};

public:
    virtual void solve() = 0;
    virtual bool is_satisfiable() = 0;
    virtual std::vector<int> get_solution() = 0;
    virtual void print_solution() = 0;

protected:
    int verify(const std::vector<int> &clause, const std::vector<int> &solution);
};

#endif