#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuf
{
	long mtype;
	char msgtxt[200];
};


int main(int argc, char const *argv[])
{
	struct msgbuf msg;
	int msgid;
	key_t key; // ???

	// first step is create a unique key

	if ((key = ftok("textfile.txt", 'b')) == -1)
	{
		perror("Key");
		exit(1);
	}

	// create or open exist queue by msgget()
	// it will return identifier

	if(( msgid = msgget(key, 0644 | IPC_CREAT )) == -1)
	{
		perror("msgid");
		exit(1);
	}

	printf("\n the msgid is %d", msgid);
	printf("Enter the Text\n");

	msg.mtype = 1;

	while(gets(msg.msgtxt), !feof(stdin))
	{
		// a new message add to the end of the queue 
		// by msgsnd()
		// data is placed on to a message queue by calling msgsnd()


		if(msgsnd(msgid, &msg, sizeof(msg),0) == -1)
		{
			perror("msgsnd");
			exit(1);
		}
	}

	// usually used to destroy message queue 

	if (msgctl(msgid, IPC_RMID, NULL) == -1)
	{
		perror("msgctl");
		exit(1);
	}

	return 0;
}