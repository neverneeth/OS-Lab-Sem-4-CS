#include <stdio.h>
#include <string.h>

typedef struct Proc{
	int id, arrival, burst, priority, completion, waiting, turnaround, remaining, is_complete;
}Proc;

double fcfs(Proc p[], int n){
	// Sort by arrival time
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
	double avg_wait = (double)wait_sum/n;
	printf("\nAverage Waiting Time: %lf", avg_wait);
	printf("\nAverage Turn Around Time: %lf", (double)tat_sum/n);

	printf("\n\nGantt chart for FCFS: \n");
	for(int i = 0; i < n; i++){
		printf(" | %d", p[i].id);
	}printf(" |\n");
	
	return avg_wait;
}

double priority_scheduling(Proc p[], int n){
	int gantt[n], pos = 0;
	int current_time = 0, wait_sum = 0, tat_sum = 0;
	printf("\n\nNon-Preemptive Priority Scheduling: \n");

	for(int i = 0;i < n;i++){
		p[i].is_complete = 0;
		p[i].completion = 0;
		p[i].waiting = 0, p[i].turnaround = 0;
	}
	printf("\nPid\tArrival\tBurst\tPriority   Completion\tWaiting   Turn Around");
	int completed = 0;
	while(completed < n){
		int max_prio = p[0].priority, index = -1;
		for(int i = 0;i < n;i++){
			if(p[i].arrival <= current_time && p[i].is_complete == 0){
				if(index == -1 || p[i].priority > max_prio){
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

		gantt[pos++] = p[index].id;
		p[index].is_complete = 1; completed++;
		current_time = p[index].completion;
		printf("\n%d\t%d\t%d\t%d\t\t%d\t   %d\t   %d", p[index].id,  p[index].arrival,  p[index].burst,  p[index].priority,  p[index].completion,  p[index].waiting,  p[index].turnaround );
	}
        printf("\nNon-Preemptive Priority Scheduling Complete.\n");
        double avg_wait = (double)wait_sum/n;
        printf("\nAverage Waiting Time: %lf", avg_wait);
        printf("\nAverage Turn Around Time: %lf", (double)tat_sum/n);

        printf("\n\nGantt chart for Non-Preemptive Priority: \n");
        for(int i = 0; i < n; i++){
            	printf(" | %d", gantt[i]);
        }printf(" |\n");
        
        return avg_wait;
}

double round_robin(Proc p[], int n){
	int tat_sum =0, wait_sum = 0;
	int tq = 3;int completed = 0,current_time = 0;
	
	// Sort by arrival time
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
	
	// Initialize remaining time
	for(int i = 0; i < n;i++){
		p[i].remaining = p[i].burst;
		p[i].completion = 0, p[i].waiting = 0, p[i].turnaround = 0;
	}
	
	pos = 0;int flag = 0;
	printf("\n\nRound Robin Scheduling: \n");
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
	double avg_wait = (double)wait_sum/n;
	printf("\nAverage Waiting Time: %lf", avg_wait);
	printf("\nAverage Turn Around Time: %lf", (double)tat_sum/n);
	printf("\n\nGantt Chart: \n");
	for(int i = 0;i < pos;i++){
		printf("| %d ", gantt[i]);
	}printf("|\n");
	
	return avg_wait;
}

double srtf(Proc p[], int n){
	int completed = 0,current_time = 0;

	int gantt[1000];
	
	// Initialize remaining time
	for(int i = 0; i < n;i++){
		p[i].remaining = p[i].burst;
	}

	int prev = -1,pos=0;
	printf("\n\nSRTF Process Scheduling: \n");
	while(completed<n)
	{
		int minRT=9999, index = -1;

		for(int i=0;i<n;i++)
		{
			
			if(p[i].arrival<=current_time && p[i].remaining >0)
			{
				if(p[i].remaining<minRT)
				{
					minRT=p[i].remaining;
					index=i;
				}

				else if(p[i].remaining==minRT && (p[i].arrival<p[index].arrival ||(p[i].arrival == p[index].arrival
                         && p[i].id < p[index].id)))
				{
					index=i;
				}
			}
		}

		if(index==-1)  
		{
			current_time++;
			continue;
		}

		if(prev!=index)
		{
			gantt[pos++]=p[index].id;
			prev=index;
		}

		p[index].remaining--;  
		current_time++;

		if(p[index].remaining==0)
		{
			p[index].completion=current_time;
			completed++;
			p[index].turnaround = p[index].completion - p[index].arrival;
        	p[index].waiting = p[index].turnaround - p[index].burst;
		}
	}

	printf("\n%-5s %-10s %-10s %-10s %-10s %-10s\n", 
       "Pid", "Arrival", "Burst", "Completion", "Waiting", "Turn Around");
    
    int wait_sum = 0;
    for (int i = 0; i < n; i++)
    {
        printf("%-5d %-10d %-10d %-10d %-10d %-10d\n",p[i].id, p[i].arrival, p[i].burst,p[i].completion,  p[i].waiting,p[i].turnaround);
        wait_sum += p[i].waiting;
    }

    printf("\n\nGantt Chart: \n");
	for(int i = 0;i < pos;i++)
	{
		printf("| %d ", gantt[i]);
	}
	printf("|\n");
	
	return (double)wait_sum/n;
}

int main(){
	printf("\nNumber of Processes: ");
	int n; 
	scanf("%d", &n); 
	Proc p[n], p_copy1[n], p_copy2[n], p_copy3[n];
	
	printf("\nEnter Details of %d proccess:\n", n);
	for(int i = 0; i < n;i++){
		printf("\nProccess %d:\n", i+1);
		printf("\tID: "); scanf("%d", &(p[i].id));
		printf("\tArrival: "); scanf("%d", &(p[i].arrival) );
		printf("\tBurst: "); scanf("%d", &(p[i].burst) );
		printf("\tPriority: "); scanf("%d", &(p[i].priority) );
		printf("Proccess %d Registered.\n", i+1);
	}
	
	// Create copies for each algorithm since they modify the array
	memcpy(p_copy1, p, n * sizeof(Proc));
	memcpy(p_copy2, p, n * sizeof(Proc));
	memcpy(p_copy3, p, n * sizeof(Proc));
	
	// Run all 4 scheduling algorithms and capture average waiting times
	double fcfs_avg = fcfs(p, n);
	double priority_avg = priority_scheduling(p_copy1, n);
	double rr_avg = round_robin(p_copy2, n);
	double srtf_avg = srtf(p_copy3, n);
	
	// Find minimum average waiting time
	double min_avg = fcfs_avg;
	char min_algo[50] = "FCFS";
	
	if(priority_avg < min_avg){
		min_avg = priority_avg;
		strcpy(min_algo, "Priority");
	}
	if(rr_avg < min_avg){
		min_avg = rr_avg;
		strcpy(min_algo, "Round Robin");
	}
	if(srtf_avg < min_avg){
		min_avg = srtf_avg;
		strcpy(min_algo, "SRTF");
	}
	
	printf("\nMinimum Average Waiting Time: %lf\n", min_avg);
	printf("Best Algorithm: %s\n", min_algo);
	
	return 0;
}
