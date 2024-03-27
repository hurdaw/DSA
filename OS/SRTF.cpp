#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

struct Process
{
    int id;  // Process ID
    int bt;  // Burst Time
    int at;  // Arrival Time
    int ct;  // Completion Time
    int wt;  // Waiting Time
    int tat; // Turn Around Time
    int rt;  // Remaining Time
};

void findCompletionTime(vector<Process> &procs)
{
    int time = 0, complete = 0, shortest = 0, finish_time;
    int n = procs.size();
    int minm = INT_MAX;
    bool check = false;

    while (complete != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((procs[j].at <= time) && (procs[j].rt < minm) && procs[j].rt > 0)
            {
                minm = procs[j].rt;
                shortest = j;
                check = true;
            }
        }

        if (!check)
        {
            time++;
            continue;
        }

        procs[shortest].rt--;

        minm = procs[shortest].rt == 0 ? INT_MAX : procs[shortest].rt;
        if (procs[shortest].rt == 0)
        {
            complete++;
            check = false;

            finish_time = time + 1;
            procs[shortest].ct = finish_time;
            procs[shortest].tat = procs[shortest].ct - procs[shortest].at;
            procs[shortest].wt = procs[shortest].tat - procs[shortest].bt;
        }
        time++;
    }
}

void findAverageTimes(vector<Process> &procs)
{
    int total_wt = 0, total_tat = 0;
    int n = procs.size();

    findCompletionTime(procs);

    cout << "Processes "
         << " Burst time "
         << " Arrival time "
         << " Completion time "
         << " Turn around time "
         << " Waiting time\n";

    for (int i = 0; i < n; i++)
    {
        total_tat += procs[i].tat;
        total_wt += procs[i].wt;

        cout << " " << procs[i].id << "\t\t" << procs[i].bt << "\t\t"
             << procs[i].at << "\t\t" << procs[i].ct << "\t\t"
             << procs[i].tat << "\t\t" << procs[i].wt << endl;
    }

    cout << "Average turn around time = " << (float)total_tat / (float)n << endl;
    cout << "Average waiting time = " << (float)total_wt / (float)n << endl;
}

int main()
{
    vector<Process> procs = {{1, 20, 0}, {2, 25, 15}, {3, 10, 30}, {4, 15, 45}};

    for (auto &proc : procs)
    {
        proc.rt = proc.bt; // Initialize remaining time
    }
    findAverageTimes(procs);

    return 0;
}
