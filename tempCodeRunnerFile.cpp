#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Process {
    int id;
    int burstTime;
};

bool compare(Process a, Process b) {
    return a.burstTime < b.burstTime;
}

void findWaitingTime(vector<Process> &processes, vector<int> &waitingTime) {
    int n = processes.size();
    waitingTime[0] = 0;

    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + processes[i - 1].burstTime;
    }
}

void findTurnAroundTime(vector<Process> &processes, vector<int> &waitingTime, vector<int> &turnAroundTime) {
    int n = processes.size();

    for (int i = 0; i < n; i++) {
        turnAroundTime[i] = processes[i].burstTime + waitingTime[i];
    }
}

void findAverageTime(vector<Process> &processes) {
    int n = processes.size();
    vector<int> waitingTime(n);
    vector<int> turnAroundTime(n);

    findWaitingTime(processes, waitingTime);

    findTurnAroundTime(processes, waitingTime, turnAroundTime);

    cout << "Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n";

    int totalWaitingTime = 0;
    int totalTurnAroundTime = 0;

    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnAroundTime += turnAroundTime[i];
        cout << processes[i].id << "\t\t" << processes[i].burstTime << "\t\t" << waitingTime[i] << "\t\t" << turnAroundTime[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << (float)totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << (float)totalTurnAroundTime / n << endl;
}

int main() {
    vector<Process> processes = {{1, 6}, {2, 8}, {3, 7}, {4, 3}};
    sort(processes.begin(), processes.end(), compare);
    findAverageTime(processes);
    return 0;
}
