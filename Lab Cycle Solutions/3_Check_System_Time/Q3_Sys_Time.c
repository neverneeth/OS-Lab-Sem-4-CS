#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main(){
	time_t t;
	time(&t);
	printf("Time: %s\n", ctime(&t));
	printf("PID: %d\n" , getpid()); 
	long i;
    for(i = 0; i < 500000000; i++);
    sleep(1000);
	return 0;
}
