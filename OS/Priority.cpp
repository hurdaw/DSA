#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

struct Process
{
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int start_time = -1;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    int remainingTime;
};

// Function to find the process to execute based on highest priority and arrival time
int findProcessToExecute(const std::vector<Process> &processes, int currentTime)
{
    int highestPriorityProcess = -1;
    int highestPriority = INT_MIN; // Change here to look for the highest priority instead

    for (int i = 0; i < processes.size(); ++i)
    {
        if (processes[i].arrivalTime <= currentTime && processes[i].remainingTime > 0)
        {
            if (processes[i].priority > highestPriority)
            { // Change here to look for the highest priority
                highestPriority = processes[i].priority;
                highestPriorityProcess = i;
            }
            // If two processes have the same priority, prefer the one that arrived earlier
            if (processes[i].priority == highestPriority)
            {
                if (processes[highestPriorityProcess].arrivalTime > processes[i].arrivalTime)
                {
                    highestPriorityProcess = i;
                }
            }
        }
    }

    return highestPriorityProcess;
}

void calculatePriorityScheduling(std::vector<Process> &processes)
{
    int currentTime = 0;
    int completed = 0;

    while (completed != processes.size())
    {
        int currentProcess = findProcessToExecute(processes, currentTime);

        if (currentProcess != -1)
        {
            if (processes[currentProcess].start_time == -1)
            {
                processes[currentProcess].start_time = currentTime;
            }
            processes[currentProcess].remainingTime -= 1;
            currentTime++;

            if (processes[currentProcess].remainingTime == 0)
            {
                processes[currentProcess].completionTime = currentTime;
                processes[currentProcess].turnaroundTime = processes[currentProcess].completionTime - processes[currentProcess].arrivalTime;
                processes[currentProcess].waitingTime = processes[currentProcess].turnaroundTime - processes[currentProcess].burstTime;

                completed++;
            }
        }
        else
        {
            currentTime++;
        }
    }
}

int main()
{
    std::vector<Process> processes = {
        {1, 0, 4, 2}, // Process ID, Arrival Time, Burst Time, Priority
        {2, 1, 3, 3},
        {3, 2, 1, 4},
        {4, 3, 5, 5},
        {5, 4, 2, 5}};

    for (auto &p : processes)
    {
        p.remainingTime = p.burstTime;
    }

    calculatePriorityScheduling(processes);

    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (const auto &p : processes)
    {
        totalWaitingTime += p.waitingTime;
        totalTurnaroundTime += p.turnaroundTime;
    }

    std::cout << "Average Waiting Time = " << (float)totalWaitingTime / processes.size() << "\n";
    std::cout << "Average Turnaround Time = " << (float)totalTurnaroundTime / processes.size() << "\n";

    return 0;
}
