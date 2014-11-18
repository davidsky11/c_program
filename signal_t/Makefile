CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c ../lib/signal_functions.c

all: intquit kill_t ouch sig_receiver
	echo "build all..."

intquit: intquit.c
	$(CC) -g intquit.c $(INCLUDE) -o intquit

kill_t: kill_t.c
	$(CC) -g kill_t.c $(INCLUDE) -o kill_t

ouch: ouch.c
	$(CC) -g ouch.c $(INCLUDE) -o ouch

sig_receiver: sig_receiver.c
	$(CC) -g sig_receiver.c $(INCLUDE) -o sig_receiver

clean:
	rm -rf *.a *.o intquit kill_t ouch sig_receiver
