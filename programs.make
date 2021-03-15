############################################################################
# 'A Generic Makefile for Building Multiple main() Targets in $PWD'
# Author:  Robert A. Nader (2012)
# Email: naderra at some g
# Web: xiberix
############################################################################
#  The purpose of this makefile is to compile to executable all C source
#  files in CWD, where each .c file has a main() function, and each object
#  links with a common LDFLAG.
#
#  This makefile should suffice for simple projects that require building
#  similar executable targets.  For example, if your CWD build requires
#  exclusively this pattern:
#
#  cc -c $(CFLAGS) main_01.c
#  cc main_01.o $(LDFLAGS) -o main_01
#
#  cc -c $(CFLAGS) main_2..c
#  cc main_02.o $(LDFLAGS) -o main_02
#
#  etc, ... a common case when compiling the programs of some chapter,
#  then you may be interested in using this makefile.
#
#  What YOU do:
#
#  Set PRG_SUFFIX_FLAG below to either 0 or 1 to enable or disable
#  the generation of a .exe suffix on executables
#
#  Set CFLAGS and LDFLAGS according to your needs.
#
#  What this makefile does automagically:
#
#  Sets SRC to a list of *.c files in PWD using wildcard.
#  Sets PRGS BINS and OBJS using pattern substitution.
#  Compiles each individual .c to .o object file.
#  Links each individual .o to its corresponding executable.
#
###########################################################################
#
PRG_SUFFIX_FLAG := 1
#
ifeq ($(origin CC),default)
CC := gcc
endif
TERMUX := termux-elf-cleaner
LDFLAGS := -lm
CFLAGS_INC := -std=c11
CFLAGS := -g -Wall  $(CFLAGS_INC)

#
## ==================- NOTHING TO CHANGE BELOW THIS LINE ===================
##
SRCS := $(wildcard *.c)
PRGS := $(patsubst %.c,%,$(SRCS))
PRG_SUFFIX=.exe
BINS := $(patsubst %,%$(PRG_SUFFIX),$(PRGS))
$(info $$BINS is [${BINS}])
## OBJS are automagically compiled by make.
## It's not quite magic.Relies on implicit 
## rule for .c files.
OBJS := $(patsubst %,%.o,$(PRGS))
DEPS := ""
##
all : $(BINS)
##
## For clarity sake we make use of:
.SECONDEXPANSION:
OBJ = $(patsubst %$(PRG_SUFFIX),%.o,$@)

LINK =	$(CC) $(OBJ) $(DEPS) $(LDFLAGS) -o $(BIN)
STRIP =	$(TERMUX) $(BIN) > /dev/null

ifeq ($(PRG_SUFFIX_FLAG),0)
        BIN = $(patsubst %$(PRG_SUFFIX),%,$@)
else
        BIN = $@
endif
## Compile and link  the executable
## The rule below explicitly links the 
## .o files.
%$(PRG_SUFFIX) : $(OBJS)
	-$(LINK)
	-$(STRIP)
##
## $(OBJS) should be automagically removed right after linking.
##
veryclean:
ifeq ($(PRG_SUFFIX_FLAG),0)
	$(RM) $(PRGS)
else
	$(RM) $(BINS)
endif
##
rebuild: veryclean all
##
