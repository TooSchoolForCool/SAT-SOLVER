#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

#include "parse_arg.h"
#include "utils.h"
#include "sat_solver.h"
#include "dfs_solver.h"


using namespace std;
using namespace boost::program_options;


int main(int argc, const char *argv[])
{
    variables_map cmd_opt = parse_arg(argc, argv);
    string src_file = cmd_opt["src"].as<string>();

    vector<vector<int> > sentences;
   	int n_var = read_cnf(sentences, src_file);

   	SatSolver *solver = new DfsSolver(n_var, sentences);
   	solver->solve();

   	if(solver->is_satisfiable())
   	{
   		cout << "Satisfiable" << endl;
   		solver->print_solution();
   	}
   	else
   		cout << "Unsatisfiable" << endl;

    return 0;
}