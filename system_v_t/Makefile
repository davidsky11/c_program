CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c ../lib/signal_functions.c binary_sems.c

all: parent_to_child_signal svmsg_chqbytes svmsg_create svmsg_file_client  svmsg_file_server svmsg_ls svmsg_receive svmsg_rm svmsg_send svshm_xfr_reader svshm_xfr_writer
	echo "build all..."

parent_to_child_signal: parent_to_child_signal.c
	$(CC) -g parent_to_child_signal.c $(INCLUDE) -o parent_to_child_signal

svmsg_chqbytes: svmsg_chqbytes.c
	$(CC) -g svmsg_chqbytes.c $(INCLUDE) -o svmsg_chqbytes

svmsg_create: svmsg_create.c
	$(CC) -g svmsg_create.c $(INCLUDE) -o svmsg_create

svmsg_file_client: svmsg_file_client.c
	$(CC) -g svmsg_file_client.c $(INCLUDE) -o svmsg_file_client

svmsg_file_server: svmsg_file_server.c
	$(CC) -g svmsg_file_server.c $(INCLUDE) -o svmsg_file_server

svmsg_ls: svmsg_ls.c
	$(CC) -g svmsg_ls.c $(INCLUDE) -o svmsg_ls

svmsg_receive: svmsg_receive.c
	$(CC) -g svmsg_receive.c $(INCLUDE) -o svmsg_receive

svmsg_rm: svmsg_rm.c
	$(CC) -g svmsg_rm.c $(INCLUDE) -o svmsg_rm

svmsg_send: svmsg_send.c
	$(CC) -g svmsg_send.c $(INCLUDE) -o svmsg_send

svshm_xfr_reader: svshm_xfr_reader.c
	$(CC) -g svshm_xfr_reader.c $(INCLUDE) -o svshm_xfr_reader

svshm_xfr_writer: svshm_xfr_writer.c
	$(CC) -g svshm_xfr_writer.c $(INCLUDE) -o svshm_xfr_writer

clean:
	rm -rf *.a *.o parent_to_child_signal svmsg_chqbytes svmsg_create svmsg_file_client  svmsg_file_server svmsg_ls svmsg_receive svmsg_rm svmsg_send svshm_xfr_reader svshm_xfr_writer
