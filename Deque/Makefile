CC = g++
CFLAGS = -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -pedantic -pedantic-errors  -Wuninitialized \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC

m: Main.o Makefile
	$(CC) $(CFLAGS) -o m Main.o
Main.o: Main.cpp Deque.h Test.h Makefile
	$(CC) $(CFLAGS) -c -g Main.cpp
clean:
	rm m *.o vgcore*
