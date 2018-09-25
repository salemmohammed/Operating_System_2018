#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

	int fd, retval; // variables 
	char buffer [8] = "TESTDATA"; // array of 8 chars
	fflush(stdin); // flush the input lib
	retval = mkfifo("/tmp/myfifo", 0666); // create fifo
	fd = open("/tmp/myfifo",O_WRONLY); // write only
	write(fd, buffer, sizeof(buffer)); // buffer --> fd
	close(fd);
return 0;
}
