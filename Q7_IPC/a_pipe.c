#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

int main(){

	int fd[2];

	int a, b, c;
	pid_t pid;


	printf("\na = "); scanf("%d", &a);
	printf("b = "); scanf("%d", &b);
	printf("c = "); scanf("%d", &c);

	if(pipe(fd) == -1){
		printf("\nPipe failed.\n");
		return 1;
	}

 	pid = fork();
	if(pid < 0){
		printf("\nFork failed\n");
		return 1;
	}

	if(pid == 0){
		close(fd[0]);
		int output = 4 * a * c ;
		printf("\nSecond Process Calculated 4ac: %d", output);

		write(fd[1], &output, sizeof(int));
		close(fd[1]);

		return 0;
	} else {
		close(fd[1]) ;
		printf("\nParent Process Calculated b2: %d", b*b);

		int recieved ;
		recieved = read(fd[0], &recieved, sizeof(int)); 
		printf("\nParent Recieved 4ac: %d", recieved);
		close(fd[0]);

		int result = sqrt((b*b) - recieved) ;
		printf("\nFinal Result : %d\n", result);
		wait(NULL);

	}



	return 0;
}
