CFLAGS = -g -Wall 
LDFLAGS = -lpthread
SHARED = -fPIC -shared
CC = gcc

source = daemon.c \
		 thread_pool_t.c \
		 work.c \
		 tp_test.c

target = server

work.o: work.c
	$(CC) $(SHARED) -c work.c

daemon.o: daemon.c
	$(CC) $(SHARED) -c daemon.c

thread_pool_t.o: thread_pool_t.c
	$(CC) $(SHARED) -c thread_pool_t.c

default: work.o daemon.o thread_pool_t.o
	$(CC) $(CFLAGS) $(source) -o $(target) $(LDFLAGS)
	
clean:
	rm -f *.o *.a $(target)
