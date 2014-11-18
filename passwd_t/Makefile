CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c 
CFLAGS = -lcrypt

all: check_password getuid
	echo "build all..."

check_password: check_password.c
	$(CC) -g check_password.c $(INCLUDE) -o check_password $(CFLAGS)

getuid: getuid.c
	$(CC) -g getuid.c $(INCLUDE) -o getuid

clean:
	rm -rf *.a *.o check_password getuid
