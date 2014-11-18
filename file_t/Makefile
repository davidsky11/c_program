CC = gcc
INCLUDE = ../lib/error_functions.c ../lib/get_num.c 

all: chmod_t dirbasename nftw_t listfiles
	echo "build all..."

chmod_t: chmod_t.c
	$(CC) -g chmod_t.c $(INCLUDE) -o chmod_t

dirbasename: dirbasename.c 
	$(CC) -g dirbasename.c $(INCLUDE) -o dirbasename

listfiles: list_files.c
	$(CC) -g list_files.c $(INCLUDE) -o listfiles

nftw_t: nftw_t.c
	$(CC) -g nftw_t.c $(INCLUDE) -o nftw_t

clean:
	rm -rf *.a *.o chmod_t dirbasename listfiles nftw_t
