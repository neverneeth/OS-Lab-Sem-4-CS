#ifndef SCHEDULER_H
#define SCHEDULER_H

typedef struct {
    int id;
    int arrival;
    int burst;
    int priority;
    int completion;
    int waiting;
    int turnaround;
    int remaining;
    int is_complete;
} Process;

void run_fcfs(Process p[], int n, double *avg_wait, double *avg_tat);
void run_priority(Process p[], int n, double *avg_wait, double *avg_tat);
void run_rr(Process p[], int n, int tq, double *avg_wait, double *avg_tat);
void run_srtf(Process p[], int n, double *avg_wait, double *avg_tat);

#endif

