# Makefile
# , 2021-10-24 08:02
#
SHELL := /usr/bin/env bash
VPATH := src
CPPFLAGS := -I include

count_words: count_words.o counter.o lexer.o -lfl
	gcc $(CPPFLAGS) $^ -o $@
	@termux-elf-cleaner $@ &> /dev/null || true

count_words.o: count_words.c
	gcc $(CPPFLAGS) -c $<

counter.o: counter.c
	gcc $(CPPFLAGS) -c $<

lexer.o: lexer.c
	gcc $(CPPFLAGS) -c $<

lexer.c: lexer.l
	flex -t $< > $@

clean:
	rm -f *.o count_words lexer.c || true

.PHONY: clean
