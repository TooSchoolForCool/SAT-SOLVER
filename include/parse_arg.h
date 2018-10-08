#ifndef _PARSE_ARG_H
#define _PARSE_ARG_H

#include <boost/program_options.hpp>
#include <string>
#include <iostream> 

boost::program_options::variables_map parse_arg(int argc, const char **argv);

#endif