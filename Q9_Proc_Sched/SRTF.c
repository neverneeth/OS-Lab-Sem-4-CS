#include <stdio.h>

typedef struct
{
	int id, arrival,burst,completion,turnaround,waiting,remaining;
}Process;


int main()
{
	printf("\nNumber of Processes: ");
	int n;
	scanf("%d", &n); 
	Process p[n]; 
	int completed = 0,current_time = 0;

	printf("\nEnter Details of %d proccess:\n", n);
	for(int i = 0; i < n;i++)
	{
		printf("\nProccess %d:\n", i+1);
		printf("\tID: "); scanf("%d", &(p[i].id));
		printf("\tArrival: "); scanf("%d", &(p[i].arrival) );
		printf("\tBurst: "); scanf("%d", &(p[i].burst) );
		p[i].remaining = p[i].burst;
		printf("Proccess %d Registered.\n", i+1);
	}

	int gantt[1000];

	int prev = -1,pos=0;

	while(completed<n)
	{
		int minRT=9999, index = -1;

		for(int i=0;i<n;i++)
		{
			//finding proc with min remaining time arrived until the current_time
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

		if(index==-1)  //CPU idle
		{
			current_time++;
			continue;
		}

		if(prev!=index)
		{
			gantt[pos++]=p[index].id;
			prev=index;
		}

		p[index].remaining--;  //process executed for 1 unit of time
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
       "ID", "Arrival", "Burst", "Exit", "TAT", "Wait");
    printf("----------------------------------------------------- \n");
    for (int i = 0; i < n; i++)
    {
        printf("P%-5d %-10d %-10d %-10d %-10d %-10d\n",p[i].id, p[i].arrival, p[i].burst,p[i].completion, p[i].turnaround, p[i].waiting);
    }

    printf("\n\nGantt Chart: \n");
	for(int i = 0;i < pos;i++)
	{
		printf("| %d ", gantt[i]);
	}
	printf("|\n");

	return 0;
}