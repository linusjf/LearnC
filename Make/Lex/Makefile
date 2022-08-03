# Makefile
# , 2021-10-24 08:02
#
SHELL := /usr/bin/env bash
VPATH := src include
CPPFLAGS = -I include
ISTERMUX := ${TERMUX}
$(info $$ISTERMUX is [${ISTERMUX}])
ifeq ($(ISTERMUX), 1)
	PREFIX := /data/data/com.termux/files/usr
else
	PREFIX := /usr
endif
CC := gcc
LEX := flex

SOURCES := count_words.c lexer.c counter.c
$(info $$SOURCES is [${SOURCES}])

include $(subst .c,.d,$(SOURCES))

%.d: %.c
	@$(CC) -M $(CPPFLAGS) $< > $@.$$$$;                      \
		sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@;     \
		rm -f $@.$$$$

all: count_words
	@termux-elf-cleaner $< &> /dev/null || true

count_words: libcounter.a -lfl
libcounter.a: libcounter.a(lexer.o) libcounter.a(counter.o)
count_words.o: counter.h
counter.o: counter.h lexer.h
lexer.o: lexer.h

clean:
	rm -f *.o *.d *.a count_words lexer.c || true

.PHONY: clean
