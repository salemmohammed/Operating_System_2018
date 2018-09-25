#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

	int fd, retval; // variables 
	char buffer [8];
	fd = open("/tmp/myfifo",O_RDONLY); // write only
	retval = read(fd, buffer, sizeof(buffer));
	fflush(stdin); // flush the input lib
	write(1, buffer, sizeof(buffer)); // buffer --> fd
	close(fd);
return 0;
}
