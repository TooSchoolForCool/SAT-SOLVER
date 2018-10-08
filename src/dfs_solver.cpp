#include "dfs_solver.h"


using namespace std;


bool cmp(const vector<int> &a, const vector<int> &b)
{
    return a.size() < b.size();
}


DfsSolver::DfsSolver(int n_var, const vector<vector<int> > &clauses):
    clauses_(clauses)
{
    n_var_ = n_var;
    satisfiable_ = false;

    // sorting the sentenses according to their length
    sort(clauses_.begin(), clauses_.end(), cmp);
}


void DfsSolver::solve()
{
    vector<int> solution = vector<int>(n_var_ + 1, 0);

    if( dfs_(0, solution) )
    {
        satisfiable_ = true;
        solution_.swap(solution);
    }
}


bool DfsSolver::is_satisfiable()
{
    return satisfiable_;
}


vector<int> DfsSolver::get_solution()
{
    return satisfiable_ ? solution_ : vector<int>();
}


void DfsSolver::print_solution()
{
    for(size_t i = 1; i < solution_.size(); i++)
        cout << solution_[i] << " ";
    cout << endl;
}


bool DfsSolver::dfs_(int idx, vector<int> &solution)
{
    if(idx >= clauses_.size())
        return true;

    const vector<int> &clause = clauses_[idx];
    int res = verify(clause, solution);

    // not satisfiable
    if(res == -1)
        return false;
    // already satisfy current clause, then move to the next
    if(res == 1)
        return dfs_(idx + 1, solution);
    
    // find capable solution in current clause
    for(auto it : clause)
    {
        int i = abs(it);
        
        if(solution[i] != 0)
            continue;

        solution[i] = it;
        if(dfs_(idx + 1, solution))
            return true;
        solution[i] = 0;
    }
    
    return false;
}