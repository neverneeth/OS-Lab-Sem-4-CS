#include <stdio.h>
#include "scheduler.h"

int main() {
    int n;

    printf("Number of Processes: ");
    scanf("%d", &n);

    Process processes[n];

    printf("\nEnter process details:\n");
    for(int i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("ID: ");
        scanf("%d", &processes[i].id);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst);
        printf("Priority: ");
        scanf("%d", &processes[i].priority);
    }

    double fcfs_w, fcfs_t;
    double pri_w, pri_t;
    double rr_w, rr_t;
    double srtf_w, srtf_t;

    run_fcfs(processes, n, &fcfs_w, &fcfs_t);
    run_priority(processes, n, &pri_w, &pri_t);
    run_rr(processes, n, 3, &rr_w, &rr_t);
    run_srtf(processes, n, &srtf_w, &srtf_t);

    printf("\n\n===== COMPARISON =====\n");
    printf("FCFS Avg Waiting: %.2lf\n", fcfs_w);
    printf("Priority Avg Waiting: %.2lf\n", pri_w);
    printf("Round Robin Avg Waiting: %.2lf\n", rr_w);
    printf("SRTF Avg Waiting: %.2lf\n", srtf_w);

    double min = fcfs_w;
    char best[20] = "FCFS";

    if(pri_w < min){ min = pri_w; sprintf(best,"Priority"); }
    if(rr_w < min){ min = rr_w; sprintf(best,"Round Robin"); }
    if(srtf_w < min){ min = srtf_w; sprintf(best,"SRTF"); }

    printf("\nBest Scheduling Algorithm (Lowest Avg Waiting Time): %s\n", best);

    return 0;
}

