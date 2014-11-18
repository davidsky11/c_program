CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c 

all: memlock mmap_anon mprotect_t  mmcat mmap_t
	echo "build all..."

memlock: memlock.c
	$(CC) -g memlock.c $(INCLUDE) -o memlock

mmap_anon: mmap_anon.c 
	$(CC) -g mmap_anon.c $(INCLUDE) -o mmap_anon

mmap_t: mmap_t.c
	$(CC) -g mmap_t.c $(INCLUDE) -o mmap_t

mmcat: mmcat.c
	$(CC) -g mmcat.c $(INCLUDE) -o mmcat

mprotect_t: mprotect_t.c
	$(CC) -g mprotect_t.c $(INCLUDE) -o mprotect_t

clean:
	rm -rf *.a *.o memlock mmap_anon mprotect_t  mmcat mmap_t
