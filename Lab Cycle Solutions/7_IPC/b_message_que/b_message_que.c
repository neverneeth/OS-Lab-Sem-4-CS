#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <mqueue.h>
#include <sys/wait.h>

#define MAX_SIZE 1024

void reverse_string(char* str){
	int len = strlen(str);
    	for(int i = 0; i < len / 2; i++) {
        	char temp = str[i];
        	str[i] = str[len - i - 1];
        	str[len - i - 1] = temp;
    	}
}

int main(){
	mqd_t mq1, mq2;

	struct mq_attr attr;

	attr.mq_flags=0;
	attr.mq_maxmsg=10;
	attr.mq_msgsize=MAX_SIZE;
	attr.mq_curmsgs=0;

	mq1=mq_open("/queue1",O_RDWR|O_CREAT,0644,&attr);
	mq2=mq_open("/queue2",O_RDWR|O_CREAT,0644,&attr);

	char string[MAX_SIZE];

	pid_t cpid = fork();

	// Child
	if(cpid==0){
		mq_receive(mq1, string, attr.mq_msgsize, 0);

		reverse_string(string);

		mq_send(mq2, string, strlen(string) + 1, 0);

		mq_close(mq1);
		mq_close(mq2);
	}
	// Parent
	else{
		printf("\nEnter a string: ");

		fgets(string, MAX_SIZE, stdin);
		string[strcspn(string, "\n")] = '\0';

		mq_send(mq1, string, strlen(string) + 1, 0);

		char buffer[MAX_SIZE];

		mq_receive(mq2, buffer, MAX_SIZE, 0);

		printf("Reversed String : %s\n", buffer);

		if(strcmp(buffer, string)==0){
			printf("The given string is Palindromic.\n\n");
		}
		else{
			printf("Not palindromic!\n\n");
		}

		mq_close(mq1);
		mq_close(mq2);

		wait(NULL);

		mq_unlink("/queue1");
		mq_unlink("/queue2");
	}

	return 0;
}
