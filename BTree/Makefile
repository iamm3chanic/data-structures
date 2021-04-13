CC=g++
OPTIONS=-std=c++11 -g  -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -pedantic  \
-Wuninitialized \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC


all: btree
btree: main.o btree.o
	$(CC) $(OPTIONS) main.o btree.o -o btree
main.o: 
	$(CC) $(OPTIONS) -c main.cpp -o main.o
btree.o: 
	$(CC) $(OPTIONS) -c btree.cpp -o btree.o
clean:
	rm -f *o btree vgcore*
