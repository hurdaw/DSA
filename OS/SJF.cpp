#include <iostream>
#include <vector>
#include <algorithm>

struct Process
{
    int pid; // Process ID
    int at;  // Arrival Time
    int bt;  // Burst Time
    int wt;  // Waiting Time
    int tat; // Turnaround Time
};

// Function to find the waiting time for all processes
void findWaitingTime(std::vector<Process> &processes)
{
    int n = processes.size();
    std::vector<int> complete(n, 0), burst_remaining(n);
    int current_time = 0, completed = 0, prev = 0;

    // Copy the burst times into burst_remaining
    for (int i = 0; i < n; i++)
        burst_remaining[i] = processes[i].bt;

    while (completed != n)
    {
        int idx = -1;
        int min = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (processes[i].at <= current_time && !complete[i])
            {
                if (burst_remaining[i] < min)
                {
                    min = burst_remaining[i];
                    idx = i;
                }
                if (burst_remaining[i] == min)
                {
                    if (processes[i].at < processes[idx].at)
                    {
                        min = burst_remaining[i];
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1)
        {
            if (burst_remaining[idx] == processes[idx].bt)
            {
                processes[idx].wt = current_time - processes[idx].at;
                current_time += burst_remaining[idx];
                burst_remaining[idx] = 0;
                completed++;
                complete[idx] = 1;
            }
            else
            {
                burst_remaining[idx]--;
                current_time++;
            }
        }
        else
        {
            current_time++;
        }
    }
}

// Function to find the turn around time for all processes
void findTurnAroundTime(std::vector<Process> &processes)
{
    for (auto &p : processes)
        p.tat = p.bt + p.wt;
}

// Function to calculate average time
void findAvgTime(std::vector<Process> &processes)
{
    findWaitingTime(processes);
    findTurnAroundTime(processes);

    std::cout << "Processes  "
              << "Burst time  "
              << "Waiting time  "
              << "Turn around time\n";

    int total_wt = 0, total_tat = 0;
    for (const auto &p : processes)
    {
        total_wt += p.wt;
        total_tat += p.tat;
        std::cout << "   " << p.pid << "\t\t" << p.bt << "\t    " << p.wt << "\t\t  " << p.tat << std::endl;
    }

    std::cout << "Average waiting time = " << (float)total_wt / (float)processes.size() << std::endl;
    std::cout << "Average turn around time = " << (float)total_tat / (float)processes.size() << std::endl;
}

int main()
{
    std::vector<Process> processes = {{1, 1, 3}, {2, 4, 1}, {3, 2, 4}, {4, 6, 0}, {5, 3, 2}};
    findAvgTime(processes);
    return 0;
}
