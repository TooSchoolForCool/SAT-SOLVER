#include <parse_arg.h>


using namespace boost::program_options;
using namespace std;


variables_map parse_arg(int argc, const char **argv)
{
    try
    {
        options_description desc{"Options"};
        desc.add_options()
            ("help,h", "Help screen")
            ("src,c", value<string>()->required(), "CNF source file")
            ("out,o", value<string>()->default_value(""), "Output directory");

        variables_map vm;
        store(parse_command_line(argc, argv, desc), vm);
        notify(vm);

        return vm;
    }
    catch (const error &ex)
    {
        std::cerr << ex.what() << '\n';
        exit(-1);
    }
}