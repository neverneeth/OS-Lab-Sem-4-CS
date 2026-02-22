#include <stdio.h>
#include "scheduler.h"

void run_priority(Process p[], int n, double *avg_wait, double *avg_tat) {

    Process temp[n];
    for(int i=0;i<n;i++){
        temp[i] = p[i];
        temp[i].is_complete = 0;
    }

    int completed=0,time=0;
    int wait_sum=0,tat_sum=0;

    printf("\n\n===== Non-Preemptive Priority =====\n");
    printf("ID\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    while(completed<n){

        int idx=-1;
        int max_pr=-9999;

        for(int i=0;i<n;i++){
            if(temp[i].arrival<=time && temp[i].is_complete==0){
                if(temp[i].priority>max_pr){
                    max_pr=temp[i].priority;
                    idx=i;
                }
            }
        }

        if(idx==-1){
            time++;
            continue;
        }

        temp[idx].completion = time + temp[idx].burst;
        temp[idx].turnaround = temp[idx].completion - temp[idx].arrival;
        temp[idx].waiting = temp[idx].turnaround - temp[idx].burst;

        wait_sum += temp[idx].waiting;
        tat_sum += temp[idx].turnaround;

        time = temp[idx].completion;
        temp[idx].is_complete=1;
        completed++;

        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            temp[idx].id,temp[idx].arrival,temp[idx].burst,
            temp[idx].priority,temp[idx].completion,
            temp[idx].waiting,temp[idx].turnaround);
    }

    *avg_wait = (double)wait_sum/n;
    *avg_tat = (double)tat_sum/n;

    printf("Average Waiting Time: %.2lf\n", *avg_wait);
}

