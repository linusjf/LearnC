# Makefile
# , 2021-10-24 08:02
#
SHELL := /usr/bin/env bash

count_words: count_words.o lexer.o -lfl
	gcc count_words.o lexer.o -lfl -o count_words
	@termux-elf-cleaner count_words &> /dev/null || true

count_words.o: count_words.c
	gcc -c count_words.c

lexer.o: lexer.c
	gcc -c lexer.c

lexer.c: lexer.l
	flex -t lexer.l > lexer.c

clean:
	rm -f *.o count_words lexer.c || true

.PHONY: clean
