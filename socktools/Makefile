CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c

all: msgtool semtool shmtool
	echo "build all..."

msgtool: msgtool.c
	$(CC) -g msgtool.c $(INCLUDE) -o msgtool

semtool: semtool.c
	$(CC) -g semtool.c $(INCLUDE) -o semtool

shmtool: shmtool.c
	$(CC) -g shmtool.c $(INCLUDE) -o shmtool

clean:
	rm -rf *.a *.o msgtool semtool shmtool
