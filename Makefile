CC     = gcc
CFLAGS = -W -Wall -I.. -pthread -g

.PHONY: all clean

all: | clean curses glsl

clean:
	rm -rf curses glsl *.exe *.dSYM *.obj

curses:
	OS=`uname`; \
		test "$$OS" = Linux && LIBS="-lncurses" ; \
		$(CC) $(CFLAGS) main.c  $$LIBS $(ADD) -o curses;

glsl:
	$(CC) $(CFLAGS) viewer.c -o glsl
