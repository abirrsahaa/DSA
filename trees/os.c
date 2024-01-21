#include <stdio.h>

// Structure to represent a process
struct Process
{
    int pid;
    int arrival_time;
    int service_time;
    int remaining_time;
    int priority;
    int waiting_time;
};
// shoretest remaing
//  Function to find the process with highest priority
int findHighestPriority(struct Process processes[], int n, int currentTime)
{
    int highestPriority = -1;
    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrival_time <= currentTime && processes[i].remaining_time > 0)
        {
            if (processes[i].remaining_time == processes[i].service_time)
            {
                processes[i].priority += 2;
            }
            if (highestPriority == -1 || processes[i].priority > processes[highestPriority].priority)
            {
                highestPriority = i;
            }
        }
    }
    return highestPriority;
}

// Function to perform scheduling
void scheduleProcesses(struct Process processes[], int n)
{
    int currentTime = 0;
    int executedProcesses = 0;

    while (executedProcesses < n)

    {
        int highestPriority = findHighestPriority(processes, n, currentTime);
        printf(" the highest priority of the process is : %d\n", processes[highestPriority].pid);

        if (highestPriority == -1)
        {
            currentTime++;
            continue;
        }

        processes[highestPriority].remaining_time--;
        processes[highestPriority].priority += 1;

        if (processes[highestPriority].remaining_time == 0)
        {
            executedProcesses++;
            // waiting tat - arrival time-execution time
            processes[highestPriority].waiting_time = currentTime + 1 - processes[highestPriority].arrival_time - processes[highestPriority].service_time;
        }

        currentTime++;
    }
}

int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];
    float average = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and service time for process P%d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].service_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].service_time;

        processes[i].priority = 0;
        processes[i].waiting_time = 0;
    }

    // Perform scheduling
    scheduleProcesses(processes, n);

    // Display results
    printf("\nProcess\tArrival Time\tService Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].service_time, processes[i].waiting_time);
        average += processes[i].waiting_time;
    }

    printf("\nThe average waiting time is %.3f", average / n);
    return 0;
}