CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c 
CFLAGS = -lcrypt

all: fifo_open fifo_read fifo_write parent_child_trans_pipe pipe_relation pipe_t readtest sample_pipe write_atom write_dependency
	echo "build all..."

fifo_open: fifo_open.c
	$(CC) -g fifo_open.c $(INCLUDE) -o fifo_open

fifo_read: fifo_read.c
	$(CC) -g fifo_read.c $(INCLUDE) -o fifo_read

fifo_write: fifo_write.c
	$(CC) -g fifo_write.c $(INCLUDE) -o fifo_write

parent_child_trans_pipe: parent_child_trans_pipe.c
	$(CC) -g parent_child_trans_pipe.c $(INCLUDE) -o parent_child_trans_pipe

pipe_relation: pipe_relation.c
	$(CC) -g pipe_relation.c $(INCLUDE) -o pipe_relation

pipe_t: pipe_t.c
	$(CC) -g pipe_t.c $(INCLUDE) -o pipe_t

readtest: readtest.c
	$(CC) -g readtest.c $(INCLUDE) -o readtest

sample_pipe: sample_pipe.c
	$(CC) -g sample_pipe.c $(INCLUDE) -o sample_pipe

write_atom: write_atom.c
	$(CC) -g write_atom.c $(INCLUDE) -o write_atom

write_dependency: write_dependency.c
	$(CC) -g write_dependency.c $(INCLUDE) -o write_dependency

clean:
	rm -rf *.a *.o fifo_open fifo_read fifo_write parent_child_trans_pipe pipe_relation pipe_t readtest sample_pipe write_atom write_dependency
