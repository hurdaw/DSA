#include <iostream>
#include <vector>
#include <queue>

struct Process
{
    int pid;             // Process ID
    int at;              // Arrival Time
    int bt;              // Burst Time
    int start_time;      // Start Time
    int completion_time; // Completion Time
    int remaining_bt;    // Remaining Burst Time
    int waiting_time;    // Waiting Time
};

void findAvgTime(std::vector<Process> &processes, int quantum)
{
    int n = processes.size();
    std::queue<int> q; // Queue to store the indexes of processes
    int current_time = 0, completed = 0;
    std::vector<bool> is_in_queue(n, false);

    // Initially push all processes that arrive at time 0 into the queue
    for (int i = 0; i < n; i++)
    {
        if (processes[i].at == 0)
        {
            q.push(i);
            is_in_queue[i] = true;
        }
        processes[i].remaining_bt = processes[i].bt;
    }

    while (completed != n)
    {
        if (!q.empty())
        {
            int idx = q.front();
            q.pop();
            is_in_queue[idx] = false;

            if (processes[idx].remaining_bt == processes[idx].bt)
            {
                // Process is getting CPU for the first time
                processes[idx].start_time = std::max(current_time, processes[idx].at);
                current_time = processes[idx].start_time;
            }

            int exec_time = std::min(processes[idx].remaining_bt, quantum);
            processes[idx].remaining_bt -= exec_time;
            current_time += exec_time;

            // Check for new arrivals
            for (int i = 0; i < n; i++)
            {
                if (!is_in_queue[i] && processes[i].at <= current_time && processes[i].remaining_bt > 0)
                {
                    q.push(i);
                    is_in_queue[i] = true;
                }
            }

            if (processes[idx].remaining_bt > 0)
            {
                q.push(idx);
                is_in_queue[idx] = true;
            }
            else
            {
                processes[idx].completion_time = current_time;
                processes[idx].waiting_time = processes[idx].completion_time - processes[idx].bt - processes[idx].at;
                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }

    double total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
    {
        total_wt += processes[i].waiting_time;
        total_tat += processes[i].waiting_time + processes[i].bt;
    }

    std::cout << "Average Waiting Time = " << (total_wt / n) << "\n";
    std::cout << "Average Turnaround Time = " << (total_tat / n) << "\n";
}

int main()
{
    int quantum = 1;
    std::vector<Process> processes = {{1, 4, 0}, {2, 1, 0}, {3, 8, 0}, {4, 1, 0}};

    findAvgTime(processes, quantum);

    return 0;
}
