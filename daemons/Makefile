CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c become_daemon.c

all: daemon_SIGHUP test_become_daemon
	echo "build all..."

test_become_daemon: test_become_daemon.c become_daemon.c
	$(CC) -g test_become_daemon.c $(INCLUDE) -o test_become_daemon

daemon_SIGHUP: daemon_SIGHUP.c become_daemon.c
	$(CC) -g daemon_SIGHUP.c $(INCLUDE) -o daemon_SIGHUP

clean:
	rm -rf *.a *.o test_become_daemon daemon_SIGHUP
