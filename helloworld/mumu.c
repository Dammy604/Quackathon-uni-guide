#include <stdio.h>

typedef struct {
    int pid;
    int burst_time;
    int remaining_time;
} Process;

void findWaitingTime(Process proc[], int n, int quantum) {
    int t = 0;
    int waiting_time[n];
    int turn_around_time[n];
    int completed = 0;
    
    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (proc[i].remaining_time > 0) {
                if (proc[i].remaining_time > quantum) {
                    t += quantum;
                    proc[i].remaining_time -= quantum;
                } else {
                    t += proc[i].remaining_time;
                    waiting_time[i] = t - proc[i].burst_time;
                    proc[i].remaining_time = 0;
                    completed++;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        turn_around_time[i] = proc[i].burst_time + waiting_time[i];
    }

    printf("Processes   Burst time   Waiting time   Turn around time\n");
    for (int i = 0; i < n; i++) {
        printf("   %d \t\t%d \t\t%d \t\t%d\n", proc[i].pid, proc[i].burst_time, waiting_time[i], turn_around_time[i]);
    }

    printf("Average waiting time = %.2f\n", (float)t / n);
    printf("Average turn around time = %.2f\n", (float)t / n);
}

int main() {
    Process proc[] = {{1, 24, 24}, {2, 3, 3}, {3, 3, 3}};
    int n = sizeof(proc) / sizeof(proc[0]);
    int quantum = 4;

    findWaitingTime(proc, n, quantum);
    return 0;
}
