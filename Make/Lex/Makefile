# Makefile
# , 2021-10-24 08:02
#
SHELL := /usr/bin/env bash
VPATH := src include
CPPFLAGS = -I include
CC := gcc
LEX := flex

all: count_words
	@termux-elf-cleaner $< &> /dev/null || true

count_words: count_words.o counter.o lexer.o -lfl
count_words.o: counter.h
counter.o: counter.h lexer.h
lexer.o: lexer.h

clean:
	rm -f *.o count_words lexer.c || true

.PHONY: clean
