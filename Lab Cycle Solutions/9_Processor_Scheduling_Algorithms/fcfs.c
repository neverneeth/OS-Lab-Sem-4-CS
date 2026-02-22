#include <stdio.h>
#include "scheduler.h"

void run_fcfs(Process p[], int n, double *avg_wait, double *avg_tat) {

    Process temp[n];
    for(int i=0;i<n;i++) temp[i] = p[i];

    // sort by arrival
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(temp[j].arrival < temp[i].arrival){
                Process t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }
        }
    }

    int time = 0;
    int wait_sum=0, tat_sum=0;

    printf("\n\n===== FCFS =====\n");
    printf("ID\tAT\tBT\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++){
        if(time < temp[i].arrival)
            time = temp[i].arrival;

        temp[i].completion = time + temp[i].burst;
        temp[i].turnaround = temp[i].completion - temp[i].arrival;
        temp[i].waiting = temp[i].turnaround - temp[i].burst;

        wait_sum += temp[i].waiting;
        tat_sum += temp[i].turnaround;

        time = temp[i].completion;

        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
            temp[i].id,temp[i].arrival,temp[i].burst,
            temp[i].completion,temp[i].waiting,temp[i].turnaround);
    }

    *avg_wait = (double)wait_sum/n;
    *avg_tat = (double)tat_sum/n;

    printf("Average Waiting Time: %.2lf\n", *avg_wait);
}

