CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c 

all: sys_t
	echo "build all..."

sys_t: sys_t.c
	$(CC) -g sys_t.c $(INCLUDE) -o sys_t

clean:
	rm -rf *.a *.o sys_t
