CC = gcc
CFLAGS = -lpthread

all: mutex signal cond
	echo "build all files..."

mutex: mutex.c
	$(CC) mutex.c -o mutex $(CFLAGS)

signal: signal.c
	$(CC) signal.c -o signal $(CFLAGS)

cond: cond.c
	$(CC) cond.c -o cond $(CFLAGS)

clean:
	rm -rf *.o mutex signal cond
