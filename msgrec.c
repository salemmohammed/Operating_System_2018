#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

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

	// first step is create a key

	if ((key = ftok("textfile.txt", 'b')) == -1)
	{
		perror("Key");
		exit(1);
	}

	// check if message id generate properly

	if((msgid = msgget(key, 0644)) == -1)
	{
		perror("msgid");
		exit(1);
	}

	for(;;)

	{
		// messages are fetched from a queue by msgrcv()
		// we fetch messages based on their type field
		// messages are retrieved from a queue 

		if(msgrcv(msgid, &msg, sizeof(msg),1,0) == -1)
		{
			perror("msgrcv");
			exit(1);
		}

	printf("%s\n", msg.msgtxt);
	}
	
	return 0;
}