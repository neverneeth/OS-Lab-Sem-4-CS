#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

struct msg_buffer {
	long msg_type;
	char msg_text[100];
};




int main() {
	key_t key;
	int msgid;
	struct msg_buffer message ;
	pid_t pid;
	return 0;
}
