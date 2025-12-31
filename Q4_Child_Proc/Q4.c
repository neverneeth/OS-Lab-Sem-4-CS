#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main(){
	printf("Started Running...\n");
	pid_t check = fork();
	if(check == 0){
		printf("Child Process...\n\tChild PID: %d\n\tParent PID: %d\n", getpid(), getppid()); 
	}else{
		wait(NULL);
		printf("Parent Process...\n\tParent PID: %d\n", getpid());
	}

	sleep(1000); 
	return 0; 
}
