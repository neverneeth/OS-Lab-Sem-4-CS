#include <stdio.h>
#include "scheduler.h"

void run_srtf(Process p[], int n, double *avg_wait, double *avg_tat){

    Process temp[n];

    // Copy processes
    for(int i = 0; i < n; i++){
        temp[i] = p[i];
        temp[i].remaining = temp[i].burst;
    }

    int time = 0, completed = 0;
    int wait_sum = 0, tat_sum = 0;

    int gantt[1000];
    int gpos = 0;
    int prev = -1;

    printf("\n\n===== SRTF =====\n");
    printf("ID\tAT\tBT\tCT\tWT\tTAT\n");

    while(completed < n){

        int idx = -1;
        int min = 9999;

        //  NEW LOGIC (from double srtf)
        for(int i = 0; i < n; i++){

            if(temp[i].arrival <= time && temp[i].remaining > 0){

                if(temp[i].remaining < min){
                    min = temp[i].remaining;
                    idx = i;
                }

                // Tie breaking
                else if(temp[i].remaining == min &&
                       (temp[i].arrival < temp[idx].arrival ||
                       (temp[i].arrival == temp[idx].arrival &&
                        temp[i].id < temp[idx].id))){
                    idx = i;
                }
            }
        }

        // No process available
        if(idx == -1){
            time++;
            continue;
        }

        // Gantt tracking
        if(prev != idx){
            gantt[gpos++] = temp[idx].id;
            prev = idx;
        }

        temp[idx].remaining--;
        time++;

        // Process completed
        if(temp[idx].remaining == 0){

            temp[idx].completion = time;
            temp[idx].turnaround = time - temp[idx].arrival;
            temp[idx].waiting = temp[idx].turnaround - temp[idx].burst;

            wait_sum += temp[idx].waiting;
            tat_sum += temp[idx].turnaround;

            completed++;

            printf("%d\t%d\t%d\t%d\t%d\t%d\n",
                temp[idx].id,
                temp[idx].arrival,
                temp[idx].burst,
                temp[idx].completion,
                temp[idx].waiting,
                temp[idx].turnaround);
        }
    }

    *avg_wait = (double)wait_sum / n;
    *avg_tat  = (double)tat_sum / n;

    printf("\nAverage Waiting Time: %.2lf\n", *avg_wait);
    printf("Average Turnaround Time: %.2lf\n", *avg_tat);

    // Print Gantt Chart
    printf("\nGantt Chart:\n");
    for(int i = 0; i < gpos; i++){
        printf("| %d ", gantt[i]);
    }
    printf("|\n");
}
