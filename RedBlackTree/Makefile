CC=g++
OPTIONS= -W -Wfloat-equal -Wpointer-arith -Wwrite-strings -Wcast-align \
-Wformat-security -Wmissing-format-attribute -Wformat=1 \
-Wno-long-long -Wcast-align -Winline -Werror -pedantic -pedantic-errors \
-Wunused -Wuninitialized \
--param inline-unit-growth=1000000 --param max-inline-insns-single=10000000 \
--param large-function-growth=10000000 -fPIC  


m: main.o rbtree.o Makefile
	$(CC) $(OPTIONS) -o m main.o rbtree.o 
main.o: main.cpp Makefile
	$(CC) $(OPTIONS) -c -g main.cpp
rbtree.o: rbtree.cpp rbtree.h Makefile
	$(CC) $(OPTIONS) -c -g rbtree.cpp 
clean:
	rm -f *o m vgcore*
