#include <stdio.h>

typedef struct Proc{
	int id, arrival, burst, completion, waiting, turnaround, remaining;
}Proc ;

int main(){
	printf("\nNumber of Processes: ");
	int n, tat_sum =0, wait_sum = 0;
	scanf("%d", &n); Proc p[n]; int tq = 3;int completed = 0,current_time = 0;
	printf("\nEnter Details of %d proccess:\n", n);
	for(int i = 0; i < n;i++){
		printf("\nProccess %d:\n", i+1);
		printf("\tID: "); scanf("%d", &(p[i].id));
		printf("\tArrival: "); scanf("%d", &(p[i].arrival) );
		printf("\tBurst: "); scanf("%d", &(p[i].burst) );
		p[i].remaining = p[i].burst;
		printf("Proccess %d Registered.\n", i+1);
	}
	Proc small; int pos, gantt[1000];
	for(int i = 0; i< n-1;i++){
		small = p[i];pos = i;
		for(int j = i+1; j < n;j++){
			if(small.arrival > p[j].arrival){
				small = p[j];pos = j;
			}
		}
		p[pos] = p[i];
		p[i] = small;
	}
	for(int i = 0; i < n;i++){
		p[i].completion = 0, p[i].waiting = 0, p[i].turnaround = 0;
	}
	pos = 0;int flag = 0;
	printf("\nRound Robin Scheduling: \n");
	printf("\nPid\tArrival\tBurst\tCompletion   Waiting\tTurn Around");
	while(completed < n){
		for(int i = 0;i < n;i++){
			if(p[i].arrival <= current_time && p[i].remaining > 0){
				gantt[pos++] = p[i].id;
				flag = 1;
				if(p[i].remaining > 3){
					p[i].remaining = p[i].remaining - 3;
					printf("\n%d\t%d\t%d\t%d\t\t%d\t%d", p[i].id, p[i].arrival, p[i].burst, p[i].completion, p[i].waiting, p[i].turnaround); 
					current_time += 3;
				}else{
					current_time += p[i].remaining;
					p[i].remaining = 0;
					completed++;

              				p[i].completion = current_time;
					p[i].turnaround = p[i].completion - p[i].arrival;
					p[i].waiting = p[i].turnaround  - p[i].burst;
					printf("\n%d\t%d\t%d\t%d\t\t%d\t%d", p[i].id, p[i].arrival, p[i].burst, p[i].completion, p[i].waiting, p[i].turnaround);

					wait_sum += p[i].waiting;
					tat_sum += p[i].turnaround;
				}
			}
		}
		if(flag == 0) current_time++;
	}

	printf("\nRound Robin Scheduling Complete.\n");
	printf("\nAverage Waiting Time: %lf", (double)wait_sum/n);
	printf("\nAverage Turn Around Time: %lf", (double)tat_sum/n);
	printf("\n\nGantt Chart: \n");
	for(int i = 0;i < pos;i++){
		printf("| %d ", gantt[i]);
	}printf("|\n");


        return 0;
}
