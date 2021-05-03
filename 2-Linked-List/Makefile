CC = g++
CFLAGS = -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline \
-Wunused -Wuninitialized -fno-elide-constructors -fopenmp \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC

m: main.o list.o listbase.o Makefile
	$(CC) $(CFLAGS) -o m main.o list.o listbase.o 
main.o: main.cpp list.h Makefile
	$(CC) $(CFLAGS) -c -g main.cpp
list.o: list.cpp list.h Makefile
	$(CC) $(CFLAGS) -c -g list.cpp
listbase.o: listbase.cpp listbase.h Makefile
	$(CC) $(CFLAGS) -c -g listbase.cpp
clean:
	rm m *.o vgcore*
