CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c

all: uname_t
	echo "build all..."

uname_t: uname_t.c uid_process.c
	$(CC) -g uname_t.c $(INCLUDE) -o uname_t

clean:
	rm -rf *.a *.o uname_t
