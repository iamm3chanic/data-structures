m: malloc_reserve.o CFunctions.o Main.o Makefile
	g++ -o m malloc_reserve.o CFunctions.o Main.o
malloc_reserve.o: malloc_reserve.cpp  Makefile
	wg++ -c malloc_reserve.cpp
CFunctions.o: CFunctions.cpp CVektor.h Makefile
	wg++ -c -g CFunctions.cpp
Main.o: Main.cpp CVektor.h Makefile
	wg++ -c -g Main.cpp
clean:
	rm m malloc_reserve.o CFunctions.o Main.o
