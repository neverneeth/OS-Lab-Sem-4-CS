#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork();
	if(pid == 0){
		printf("\nPCCSL407 ");
	} else{
		wait(NULL); 
		printf("Operating Systems Lab\n");
	}
	return 0;
}
