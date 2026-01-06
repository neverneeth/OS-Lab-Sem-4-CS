#include <stdio.h>

typedef struct Proc{
	int id, arrival, burst, priority, completion, waiting, turnaround, is_complete;
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
		printf("Proccess %d Registered.\n", i+1);
	}
	int current_time = 0, wait_sum = 0, tat_sum = 0;
	printf("\n\nNon-Preemptive Priority Scheduling: \n");
	

	for(int i = 0;i < n;i++){
		p[i].is_complete = 0;
	}
	int completed = 0;
	while(completed < n){
		int max_prio = -1, index = -1;
		for(int i = 0;i < n;i++){
			if(p[i].arrival <= current_time && p[i].is_complete == 0){
				if(p[i].priority > max_prio){
					max_prio = p[i].priority, index = i;
				}
			}
		}
		if(index == -1){
			current_time++;continue;
		}
		p[index].completion = current_time + p[index].burst;

       	 	p[index].turnaround = p[index].completion - p[index].arrival;
        	tat_sum += p[index].turnaround;

        	p[index].waiting = p[index].turnaround - p[index].burst;
        	wait_sum += p[index].waiting;

		p[index].is_complete = 1; completed++;
	}
        printf("\nNon-Preemptive Priority Scheduling Complete.\n");
        printf("\nAverage Waiting Time: %lf", (double)wait_sum/n);
        printf("\nAverage Turn Around Time: %lf", (double)tat_sum/n);

        printf("\n\nGantt chart for Non-Preemptive Priority: \n");
        for(int i = 0; i < n; i++){
            	printf(" | %d", p[i].id);
        }printf(" |\n");

        return 0;
}
