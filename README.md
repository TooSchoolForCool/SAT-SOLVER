# SAT-SOLVER

![travis_build](https://travis-ci.com/TooSchoolForCool/SAT-SOLVER.svg?token=pTSTf8Kr3MZ8RE9G5srX&branch=master)![cpp11](https://img.shields.io/badge/C%2B%2B-11-blue.svg)![ubuntu_version](https://img.shields.io/badge/Ubuntu-16.04-blue.svg)![license](https://img.shields.io/hexpm/l/plug.svg)

This repo implements a SAT solver for Conjunctive Normal Form (CNF). This is also the homework #1 for the class CS267A: Probabilistic Programming and Relational Learning at UCLA.

## 1. Installation

This project is developed based on C++ Boost library in Ubuntu 16.04, try following command to install the Boost development environment on Ubuntu.

```bash
sudo apt-get install libboost-all-dev
```

Once the dependency is installed, get into the project directory (i.e., `./SAT-SOLVER`), and enter following command,

```bash
make
```

The binary is built under current directory, and is named `sat`.

## 2. Usage

The program take the .cnf file which looks like

```
4 2
1 2 -3 0
1 -4 0
```

The first line `4 2` indicates the file has 4 variables and 2 clauses. Then, the following 2 lines describe the 2 clauses, respectively. Every clause composed of integers where positive integers representing non-negated literals and negative integers representing negated literals. At the end of each clause, there is a `0` character which indicates the END of a clause.



You can try following command to test the program,

```bash
make test
```



Here is an example usage of the program

```bash
./sat -c ./tests/1_sat.cnf
```

where `-c` specify the directory of the .cnf file which contains the CNF. 

For more usage, please try `--help` option.