CC=g++
OPTIONS= -W -Wall -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC  


m: main.o BinarySearchTree.o Makefile
	$(CC) $(OPTIONS) -o m main.o BinarySearchTree.o 
main.o: main.cpp BinarySearchTree.h Makefile
	$(CC) $(OPTIONS) -c -g -O2 main.cpp
BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h Makefile
	$(CC) $(OPTIONS) -c -g -O2 BinarySearchTree.cpp 
clean:
	rm -f *o m vgcore*
