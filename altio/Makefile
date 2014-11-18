CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c

all: poll_pipes select_t
	echo "build all..."

poll_pipes: poll_pipes.c
	$(CC) -g poll_pipes.c $(INCLUDE) -o poll_pipes

select_t: select_t.c
	$(CC) -g select_t.c $(INCLUDE) -o select_t

clean:
	rm -rf *.a *.o poll_pipes select_t
