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
		printf("Proccess %d Registered\n.", i+1);
	}

	Proc small; int pos;
	for(int i = 0; i < n-1; i++){
		small = p[i], pos = i;
		for(int j = i+1; j < n;j++){
			if(p[j].arrival < small.arrival){
				small = p[j]; 
				pos = j;
			}
		}
		p[pos] = p[i];
		p[i] = small;
	}

	printf("\nProccesses entered in sorted order: \n");
	for(int i = 0; i < n;i++){
		printf("Proc %d: %d\n", i+1, p[i].arrival);
	}
	return 0;
}
