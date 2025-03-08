#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char id [10];
    int arrivalTime;
    int burstTime;
    int completionTime;
    int responseTime;
    int turnaroundTime;
} Process;

void sjf(Process *processes, int n) {
    int currentTime = 0, completed = 0;
    int firstResponse [n];
    for (int i = 0; i < n; i++) {
        firstResponse[i] = -1;
    }

    while (completed < n) {
        int shortest = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrivalTime <= currentTime && processes[i].completionTime == 0) {
                if (shortest == -1 || processes[i].burstTime < processes[shortest].burstTime) {
                    shortest = i;
                }
            }
        }

        if (shortest ==-1) {
            currentTime++;
        }

        else {
            if (firstResponse[shortest] == -1) {
                processes[shortest].responseTime = currentTime - processes[shortest].arrivalTime;
                firstResponse[shortest] = 0;
            }

            currentTime += processes[shortest].burstTime;
            processes[shortest].completionTime = currentTime;
            processes[shortest].turnaroundTime = processes[shortest].completionTime - processes[shortest].arrivalTime;
            completed++;

        }
    }
}

void printProcesses(Process *processes, int n) {
    int totalResponseTime = 0, totalTurnaroundTime = 0, totalBurstTime = 0;
    int currentTime = 0;
    
    int totalTime = processes[n-1].completionTime - processes[0].arrivalTime; 
    printf("ID\tArrival\tBurst\tCompletion\tTurnaround\tResponse\n");
    for (int i = 0; i < n; i ++) {
        totalResponseTime += processes[i].responseTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
        totalBurstTime += processes[i].burstTime;
        printf("%-6s\t%-5d\t%-5d\t%-5d\t%-5d\t%-5d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, processes[i].completionTime, processes[i].turnaroundTime, processes[i].responseTime);
    }

    float avgResponseTime = (float)totalResponseTime/ n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;
    float cpuUtilization = ((float)totalBurstTime / totalTime) * 100; 

    printf("\nAverage Response Time: %.2f\n", avgResponseTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("CPU Utilization: %.2f%%\n", cpuUtilization);

    
    size_t totalMemoryAllocated = n * sizeof(Process);
    printf("Total Memory Allocated: %zu bytes\n", totalMemoryAllocated);

}


int main() {
    int noOfProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &noOfProcesses);

    Process *processes = (Process *)malloc(noOfProcesses * sizeof(Process));
    for (int i = 0; i < noOfProcesses; i++){
        processes[i].id[0] = '\0';
        printf ("Enter the process ID for process %d (e.g ad123): ", i + 1);
        scanf("%9s", processes[i].id);
        printf("Enter arrival time for process %d: \n", i + 1);
        scanf("%d", &processes[i].arrivalTime); 
        printf("Enter burst time for process %d: \n", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].completionTime = 0;
        processes[i].responseTime = -1;             
    }

    sjf(processes, noOfProcesses);
    printProcesses(processes, noOfProcesses);


    free(processes);

    return 0;

}