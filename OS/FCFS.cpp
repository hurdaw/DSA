#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;     // Process ID
    int bt;     // Burst Time
    int at;     // Arrival Time
    int wt;     // Waiting Time
    int tat;    // Turn Around Time
    int ct;     // Completion Time
};

// Function to find waiting time of all processes
void findWaitingTime(vector<Process>& procs) {
    // Waiting time for first process is its arrival time
    procs[0].wt = 0;
    procs[0].ct = procs[0].bt + procs[0].at; // Completion time

    // Calculating waiting time
    for (int i = 1; i < procs.size(); i++) {
        // Completion time of previous
        int prev_ct = procs[i - 1].ct;
        
        // Waiting time is previous completion time - current arrival time
        procs[i].wt = prev_ct - procs[i].at;

        // If waiting time is negative, it means there was idle time, set waiting time to 0
        if (procs[i].wt < 0) procs[i].wt = 0;

        // Update completion time for the current process
        procs[i].ct = procs[i].bt + procs[i].wt + procs[i].at;
    }
}

// Function to find turn around time for all processes
void findTurnAroundTime(vector<Process>& procs) {
    // Turn around time is burst time + waiting time
    for (int i = 0; i < procs.size(); i++)
        procs[i].tat = procs[i].bt + procs[i].wt;
}

// Function to calculate average time
void findAvgTimes(vector<Process>& procs) {
    int n = procs.size();
    int total_wt = 0, total_tat = 0;

    // Functions to find waiting time and turn around time
    findWaitingTime(procs);
    findTurnAroundTime(procs);

    // Display processes along with all details
    cout << "Processes " << " Burst time " << " Arrival time "
         << " Waiting time " << " Turn around time\n";

    // Calculate total waiting time and total turn around time
    for (int i = 0; i < n; i++) {
        total_wt = total_wt + procs[i].wt;
        total_tat = total_tat + procs[i].tat;

        cout << " " << procs[i].id << "\t\t" << procs[i].bt << "\t\t"
             << procs[i].at << "\t\t" << procs[i].wt << "\t\t" << procs[i].tat << endl;
    }

    cout << "Average waiting time = "
         << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n << endl;
}

int main() {
    vector<Process> procs = {{1, 5, 5}, {2, 6, 4}, {3, 7, 3}, {4, 9, 1}, {5, 2, 2}, {6, 3, 6}};
    // Sort processes by arrival time
    sort(procs.begin(), procs.end(), [](Process &a, Process &b) {
        return a.at < b.at;
    });

    findAvgTimes(procs);

    return 0;
}
