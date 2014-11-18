CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c 

all: bigEnd stringcat
	echo "build all..."

bigEnd: bigEnd.c
	$(CC) -g bigEnd.c $(INCLUDE) -o bigEnd

stringcat: stringcat.c
	$(CC) -g stringcat.c $(INCLUDE) -o stringcat

clean:
	rm -rf *.a *.o bigEnd stringcat
