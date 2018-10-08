#ifndef _DFS_SOLVER_H
#define _DFS_SOLVER_H

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>

#include "sat_solver.h"


class DfsSolver: public SatSolver
{
public:
    DfsSolver(int n_var, const std::vector<std::vector<int> > &clauses);

    void solve();
    bool is_satisfiable();
    std::vector<int> get_solution();
    void print_solution();

private:
    bool dfs_(int idx, std::vector<int> &solution);

private:
    int n_var_;
    std::vector<std::vector<int> > clauses_;
    
    bool satisfiable_;
    std::vector<int> solution_;
};


#endif