# Makefile
# , 2021-10-24 08:02
#
SHELL := /usr/bin/env bash

count_words: count_words.o lexer.o -lfl
	gcc $^ -o $@
	@termux-elf-cleaner $@ &> /dev/null || true

count_words.o: count_words.c
	gcc -c $<

lexer.o: lexer.c
	gcc -c $<

lexer.c: lexer.l
	flex -t $< > $@

clean:
	rm -f *.o count_words lexer.c || true

.PHONY: clean
