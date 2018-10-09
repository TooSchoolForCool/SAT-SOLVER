# SAT-SOLVER

[![Build Status](https://travis-ci.com/TooSchoolForCool/SAT-SOLVER.svg?token=pTSTf8Kr3MZ8RE9G5srX&branch=master)](https://travis-ci.com/TooSchoolForCool/SAT-SOLVER) ![cpp11](https://img.shields.io/badge/C%2B%2B-11-blue.svg) ![ubuntu_version](https://img.shields.io/badge/Ubuntu-16.04-blue.svg) ![license](https://img.shields.io/hexpm/l/plug.svg)

This repo implements a SAT solver for Conjunctive Normal Form (CNF) by utilizing DPLL algorithm. This is also the homework #1 for the class CS267A: Probabilistic Programming and Relational Learning at UCLA.

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
5 3
1 -5 4 0
-1 5 3 4 0
-3 -4 0
```

The first line `5 3` indicates the file has 5 variables and 3 clauses. Then, the following 3 lines describe the 3 clauses, respectively. Every clause composed of integers where positive integers representing non-negated literals and negative integers representing negated literals. At the end of each clause, there is a `0` character which indicates the END of a clause. The output should look like following,

```
----------------tests/5_sat.cnf----------------
Satisfiable
1 0 -3 0 5
```

Since there are 5 variables, the solution contains 5 integers, where `1` and `5` indicate the 1st and the 5th variables should be `True`, and `-3` indicates the 3rd variable should be `False`. The `0` at the 2nd and 4th place indicate the 2nd and 4th variable could be either `True` or `False`.



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