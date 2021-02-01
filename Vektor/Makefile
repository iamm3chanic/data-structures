CC = g++
CFLAGS =  -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC

m: malloc_reserve.o CFunctions.o Main.o Makefile
	$(CC) $(CFLAGS) -o m CFunctions.o Main.o #malloc_reserve.o 
#malloc_reserve.o: malloc_reserve.cpp  Makefile
#	wg++ -c malloc_reserve.cpp
CFunctions.o: CFunctions.cpp CVektor.h Makefile
	$(CC) $(CFLAGS) -c -g CFunctions.cpp
Main.o: Main.cpp CVektor.h Makefile
	$(CC) $(CFLAGS) -c -g Main.cpp
clean:
	rm m *.o
