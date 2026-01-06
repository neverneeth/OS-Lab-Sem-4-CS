#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Proc{
	int id, arrival, burst, priority, completion, waiting, turnaround;
}Proc ;

int main(){
	printf("\nNumber of Processes: ");
	int n; 
	scanf("%d", &n); Proc p[n];
	printf("\nEnter Details of %d proccess:\n", n);
	for(int i = 0; i < n;i++){
		printf("\nProccess %d:\n", i+1);
		printf("\tID: "); scanf("%d", &(p[i].id));
		printf("\tArrival: "); scanf("%d", &(p[i].arrival) );
		printf("\tBurst: "); scanf("%d", &(p[i].burst) );
		printf("\tPriority: "); scanf("%d", &(p[i].priority) );
		printf("\tCompletion: "); scanf("%d", &(p[i].completion) );
		printf("\tWaiting: "); scanf("%d", &(p[i].waiting) );
		printf("\tTurnAround: "); scanf("%d", &(p[i].turnaround) );
		printf("Proccess %d Registered\n.", i+1);
	}
	return 0;
}
