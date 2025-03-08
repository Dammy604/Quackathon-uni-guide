#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char id[10];
    int arrivalTime;
    int burstTime;
    int completionTime;
    int responseTime;
    int turnaroundTime;
} Process;

void fcfs(Process* processes, int n) {
    int currentTime = 0, idleTime = 0, totalTime = 0;
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arrivalTime) {
            idleTime += processes[i].arrivalTime - currentTime;
            currentTime = processes[i].arrivalTime;
        }
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].responseTime = currentTime - processes[i].arrivalTime;
        currentTime += processes[i].burstTime;
    }
    totalTime = currentTime;
    size_t totalMemoryAllocated = n * sizeof(Process);
    printf("Total Memory Allocated: %zu bytes\n", totalMemoryAllocated);
}

void printProcesses(Process* processes, int n) {
    int totalResponseTime = 0, totalTurnaroundTime = 0, totalBurstTime = 0;
    int totalTime = processes[n - 1].completionTime - processes[0].arrivalTime;
    printf("ID\tArrival\tBurst\tCompletion\tTurnaround\tResponse\n");
    for (int i = 0; i < n; i++) {
        totalResponseTime += processes[i].responseTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
        totalBurstTime += processes[i].burstTime;
        printf("\n%-6s\t%-5d\t%-5d\t%-5d\t%-5d\t%-5d\n", processes[i].id, processes[i].arrivalTime, processes[i].burstTime, processes[i].completionTime, processes[i].turnaroundTime, processes[i].responseTime);
    }

    float avgResponseTime = (float)totalResponseTime / n;
    float avgTurnaroundTime = (float)totalTurnaroundTime / n;
    float cpuUtilization = ((float)totalBurstTime / totalTime) * 100;

    printf("\nAverage Response Time: %.2f\n", avgResponseTime);
    printf("Average Turnaround Time: %.2f\n", avgTurnaroundTime);
    printf("CPU Utilization: %.2f%%\n", cpuUtilization);
}

int main() {
    int noOfProcesses;
    printf("Enter the number of processes: ");
    scanf("%d", &noOfProcesses);

    Process* processes = (Process*)malloc(noOfProcesses * sizeof(Process));
    for (int i = 0; i < noOfProcesses; i++) {
        processes[i].id[0] = '\0';
        printf("Enter the process ID for process %d (e.g ad123): ", i + 1);
        scanf("%9s", processes[i].id);
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    fcfs(processes, noOfProcesses);
    printProcesses(processes, noOfProcesses);

    free(processes);
    return 0;
}
