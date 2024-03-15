#include <iostream>
#include <queue>
using namespace std;

// Function to simulate the CPU scheduling algorithm
void nCPUScheduling(int n) {
    // Create n queues for n CPUs
    vector<queue<int> > queues(n);

    int numProcess;
    int id;
    cout << "Enter the number of processes: ";
    cin >> numProcess;
    vector<queue<int> > idq(n);
    // Initialize the ready queue for the first CPU with the processes/jobs
    for (int i = 0; i < numProcess; i++) {
        int process;
        cout << "Enter the process id and burst time " << ": ";
        cin >> id;
        cin >> process;

        queues[i%n].push(process);
        idq[i%n].push(id);
    }

    int timeQuantum;
    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    int completedProcesses = 0;
    int currentCPU = 0;

    // Simulate the CPU scheduling algorithm
    int spent[n];
    for(int i=0;i<n;i++)
    {
        spent[i]=0;
    }
    cout<<"Process ID"<<"\t timeline"<<"\t CPU"<<endl;
    while (completedProcesses < numProcess) {
        // Move the process/job to the next queue or complete it
        if (!queues[currentCPU].empty()) {
            int currentProcess = queues[currentCPU].front();
            queues[currentCPU].pop();
            int x;
            if(currentProcess>=timeQuantum)
            {
            x=spent[currentCPU]+timeQuantum;
            }
            else
            {
                x=spent[currentCPU]+currentProcess;
            }
            cout <<"    "<< idq[currentCPU].front() <<"    \t"<<" from "<<spent[currentCPU] <<" to "<<x<<"\t  "<< currentCPU + 1 << endl;
            // spent[currentCPU]+=currentProcess;
            int id =idq[currentCPU%n].front();
            idq[currentCPU%n].pop();
            // Check if the process/job is completed
            if (currentProcess >= timeQuantum) {

                currentProcess -= timeQuantum;
                spent[currentCPU]+=timeQuantum;
                // Move the process/job to the next queue
                if(currentProcess!=0)
                {
                queues[(currentCPU + 1) % n].push(currentProcess);
                
                idq[(currentCPU+1)%n].push(id);
                
                }
            } else {
                // Process/job is completed
                spent[currentCPU]+=currentProcess;
                completedProcesses++;
            }
        }

        // Move to the next CPU
        currentCPU = (currentCPU + 1) % n;
    }
}

int main() {
    int numCPUs;
    cout << "Enter the number of CPUs: ";
    cin >> numCPUs;

    nCPUScheduling(numCPUs);

    return 0;
}

//adding it to github 
