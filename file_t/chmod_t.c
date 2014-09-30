#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(void)
{
	int fd;
	mkdir("test", S_IRUSR|S_IWUSR|S_IXUSR);
	chdir("test");
	fd = open("myfile", O_RDWR|O_CREAT, S_IRUSR|S_IWUSR);
	symlink("myfile", "../mylink");
	chmod("../link", S_IRUSR);
}
