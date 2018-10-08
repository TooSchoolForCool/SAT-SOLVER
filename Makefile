#############################################################################
# 'make depend' uses makedepend to automatically generate dependencies 
#               (dependencies are added to end of Makefile)
# 'make'        build executable file $(TARGET)
# 'make clean'  removes all .o and executable files
# 'make run'    build executalbe file $(TARGET) and run it ./$(TARGET)
#############################################################################

# define the C compiler to use
CC = g++

# define thr remove command
RM = rm

# define object files directory
OBJS_DIR = obj

# define any compile-time flags
CFLAGS = -g -std=c++11

#############################################################################
# define any directories containing header files other than /usr/include
# eg: INCLUDES = -I/home/newhall/include  -I../include `pkg-config --cflags opencv`
#############################################################################
INCLUDES = -I./include

#############################################################################
# define the searching scope of the library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
#   eg: LFLAGS = -L/home/newhall/lib  -L../lib `pkg-config --libs opencv`
#############################################################################
LFLAGS = 

#############################################################################
# define any libraries to link into executable:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
#   eg: LIBS = -lmylib -lm -lboost_program_options
#############################################################################
LIBS = -lboost_program_options

# define header files
HEADERS = $(wildcard include/*.h)

# define the C/C++ source files
SRCS = $(wildcard src/*.cpp)

#############################################################################
# define the C/C++ object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#############################################################################
OBJS = $(SRCS:%.cpp=$(OBJS_DIR)/%.o)

# define the executable file 
TARGET = sat

# Testcases
TEST_FILES = $(wildcard tests/*.cnf)

#############################################################################
# The following part define the color highlights of the makefile output
#   Errors are Red
#   Warnings are Yellow
#   Success is Green
#############################################################################

# Define color MACRO
COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

# define result tag
OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"

# define the function that run the command and check the running state
# run_and_check($1: cmd_info, $2: target_name, $3: cmd)
# Note: in this shell function, every line have to be ended with \ (including a empty line)
define run_and_check
	printf "%-18b%b" "$(COM_COLOR)$(1)" "$(OBJ_COLOR) $(2)$(NO_COLOR)\r"; \
	$(3) 2> $@.log; \
	RESULT=$$?; \
		if [ $$RESULT -ne 0 ]; then \
		  printf "%-18b%-60b%b" "$(COM_COLOR)$(1)" "$(OBJ_COLOR) $2" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"   ; \
		elif [ -s $@.log ]; then \
		  printf "%-18b%-60b%b" "$(COM_COLOR)$(1)" "$(OBJ_COLOR) $2" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"   ; \
		else  \
		  printf "%-18b%-60b%b" "$(COM_COLOR)$(1)" "$(OBJ_COLOR) $(2)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"   ; \
		fi; \
		cat $@.log; \
		rm -f $@.log; \
	exit $$RESULT
endef


#############################################################################
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#############################################################################
.PHONY: depend clean test all

all: $(TARGET)
	@echo $(TARGET) has been succesfully built

$(TARGET): $(OBJS)
	@$(call run_and_check,"Building",$@,$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ $(LFLAGS) $(LIBS))

#############################################################################
# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
#############################################################################
$(OBJS_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@$(call run_and_check,"Compiling",$<,$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@)

test: $(TARGET)
	@$(foreach var, $(TEST_FILES), \
		echo "----------------$(var)----------------"; \
		./$(TARGET) -c $(var); \
	)

clean:
	$(RM) -rf $(OBJS_DIR) $(TARGET)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it