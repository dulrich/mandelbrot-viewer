CFLAGS=	-W -Wall -I.. -pthread -g

.PHONY: all clean

all:
	OS=`uname`; \
	  test "$$OS" = Linux && LIBS="-lncurses" ; \
	  $(CC) $(CFLAGS) main.c  $$LIBS $(ADD) -o mandelbrot;

clean:
	rm -rf mandelbrot *.exe *.dSYM *.obj
