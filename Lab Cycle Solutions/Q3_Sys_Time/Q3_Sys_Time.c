#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main(){
	time_t t;
	time(&t);
	printf("Time: %s\n", ctime(&t));
	printf("PID: %d\n" , getpid()); 
	sleep(1000);
	return 0;
}
