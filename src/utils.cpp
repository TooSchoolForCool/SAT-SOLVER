#include "utils.h"

using namespace std;

int read_cnf(vector<vector<int> > &vec, const string &file_name)
{
    ifstream file_in(file_name);

    int n_var, n_cnf;
    file_in >> n_var >> n_cnf;

    string line;

    // read the '\n' at the end of the first line
    getline(file_in, line);
    while(getline(file_in, line))
    {
        istringstream iss(line);
        vector<int> sentence;
        int tmp;

        while(iss >> tmp)
            sentence.push_back(tmp);
        vec.push_back(sentence);
    }

    return n_var;
}