#include <iostream>
#include <string>

#include <parse_arg.h>


using namespace std;
using namespace boost::program_options;


int main(int argc, const char *argv[])
{
    variables_map cmd_opt = parse_arg(argc, argv);

    cout << cmd_opt["src"].as<string>() << endl;
    
    return 0;
}