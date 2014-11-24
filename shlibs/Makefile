CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c
CFLAGS = -ldl

all: dynload
	echo "build all..."

dynload: dynload.c mod.c
	$(CC) -g -fPIC -Wall mod.c -shared -o libmod.so
	$(CC) -g dynload.c $(INCLUDE) -o dynload $(CFLAGS)

clean:
	rm -rf *.a *.o dynload libmod.so
