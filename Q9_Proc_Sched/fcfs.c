#include <stdio.h>

typedef struct Proc{
	int id, arrival, burst, completion, waiting, turnaround;
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
		printf("\tBurst: "); scanf("%d", &(p[i].burst) );/
		printf("Proccess %d Registered.\n", i+1);
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
	int current_time = 0, wait_sum = 0, tat_sum = 0;
	printf("\n\nFCFS Scheduling: \n");
	printf("\nPid\tArrival\tBurst\tCompletion   Waiting\tTurn Around");
	for(int i = 0; i < n;i++){
		if(current_time < p[i].arrival) current_time = p[i].arrival;
		//process completed
		p[i].completion = current_time + p[i].burst;

		p[i].turnaround = p[i].completion - p[i].arrival;
		tat_sum += p[i].turnaround;

		p[i].waiting = p[i].turnaround - p[i].burst;
		wait_sum += p[i].waiting;
		printf("\n%d\t%d\t%d\t%d\t\t%d\t%d", p[i].id, p[i].arrival, p[i].burst, p[i].completion, p[i].waiting, p[i].turnaround);
		current_time = p[i].completion;
	}
	printf("\nFCFS Scheduling Complete.\n");
	printf("\nAverage Waiting Time: %lf", (double)wait_sum/n);
	printf("\nAverage Turn Around Time: %lf", (double)tat_sum/n);

	printf("\n\nGantt chart for FCFS: \n");
	for(int i = 0; i < n; i++){
		printf(" | %d", p[i].id);
	}printf(" |\n");


	return 0;
}
