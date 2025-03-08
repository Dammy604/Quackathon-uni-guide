#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char id [10];
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    int remainingTime;
    int responseTime;
} Process;



void roundRobin (Process * processes, int noOfProcesses, int quantum){
    int t = 0, completed = 0;
    int firstResponse [noOfProcesses];
    for (int i = 0; i < noOfProcesses; i++){
        firstResponse [i] = -1;
    }

    while (completed < noOfProcesses){
    for (int i = 0; i < noOfProcesses; i++){
        if (processes[i].remainingTime > 0 && processes[i].arrivalTime <= t) {
            if (firstResponse [i] == -1){
                firstResponse[i] = t - processes[i].arrivalTime;
            }

            if (processes[i].remainingTime > quantum) {
                t += quantum;
                processes[i].remainingTime -= quantum;
            }

            else{
                t += processes[i].remainingTime;
                processes[i].completionTime = t;
                processes[i].remainingTime = 0;
                processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
                processes[i].responseTime = firstResponse[i];
                completed++;

            }

            
        }

        else if (processes[i].remainingTime > 0 && processes[i].arrivalTime > t) {
            t++;
        }
    }
    }
}


void printProcesses(Process* processes, int noOfProcesses) {
    printf("ID\tArrival\tBurst\tCompletion\tTurnaround\tResponse\n");
    for (int i = 0; i < noOfProcesses; i++) {
        printf("%-10s\t%-5d\t%-5d\t%-5d\t%-5d\t%-5d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, processes[i].completionTime, processes[i].turnaroundTime, processes[i].responseTime);
    }
}

int main() {
    int noOfProcesses; int quantum;
    printf("Enter the number of processes: ");
    scanf ("%d", &noOfProcesses);

    Process*processes = (Process*)malloc(noOfProcesses * sizeof(Process));

    for (int i = 0; i < noOfProcesses; i++) {
        processes[i].id[0] = '\0';
        printf ("Enter the process ID for process %d (e.g ad123)");
        scanf("%9s", processes[i].id);
        printf("Enter arrival time for process %d: \n", i + 1);
        scanf("%d", &processes[i].arrivalTime); 
        printf("Enter burst time for process %d: \n", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime;
    }

    printf ("Enter the time quantum: ");
    scanf("%d, &quantum");

    roundRobin(processes, noOfProcesses, quantum);
    printProcesses (processes, noOfProcesses);

    free (processes);


    return 0;


}