#include "sat_solver.h"


using namespace std;


int SatSolver::verify(const vector<int> &clause, const vector<int> &solution)
{
    bool is_capable = false;

    for(auto it : clause)
    {
        int idx = abs(it);

        if(solution[idx] == it)
            return 1;
        if(solution[idx] == 0)
            is_capable = true;
    }

    return is_capable ? 0 : -1;
}