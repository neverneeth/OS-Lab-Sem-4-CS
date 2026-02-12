#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>

typedef struct msg_buffer {
	long msg_type;
	char msg_text[100];
}msg_buffer ;




int main() {
	key_t msg_key;
	int msgid;
	msg_buffer message ;
	pid_t pid;

	msg_key = ftok("progfile", 65);
	msgid = msgget(msg_key, 0666 | IPC_CREAT);

	if(msgid == -1){
		printf("\nMessage Que Failed\n");
		return 1;
	}

	pid = fork();
	if(pid == 0){
		msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);
		printf("\nChild recieved string: %s\n", message.msg_text);

		int len = strlen(message.msg_text);
		for(int i = 0;i< (len/2); i++){
			char temp = message.msg_text[i]; 
			message.msg_text[i] = message.msg_text[len-i-1];
			message.msg_text[len-1-i] = temp;
		}

		printf("\nChild sending reversed string: %s\n", message.msg_text); 
		message.msg_type = 2;
		msgsnd(msgid, &message, sizeof(message.msg_text), 0);
	}else {
		printf("\nEnter the String (Unifrom Caps): ");
		scanf("%s", message.msg_text);
		char temp[100];
		strcpy(temp, message.msg_text);

		message.msg_type = 1;
		msgsnd(msgid, &message, sizeof(message.msg_text), 0);
		printf("\nParent Send: %s\n", message.msg_text);
		msgrcv(msgid, &message, sizeof(message.msg_text), 2, 0);
		printf("\nParent Received: %s\n", message.msg_text);
		if(strcmp(message.msg_text, temp) == 0){
			printf("\nThe String: %s is Palindrome\n", message.msg_text);
		} else printf("\nThe String: %s is NOT Palindrome\n", message.msg_text);

		msgctl(msgid, IPC_RMID, NULL);

	}


	return 0;
}
