#include <iostream>

using namespace std;

class JobSequencing
{
    struct Job
    {
        char id;
        int deadline;
        int profit;
    };

    Job job[100];

    int n;

public:

    // Input function
    void getData()
    {
        cout << "Enter number of jobs: ";
        cin >> n;

        cout << "\nEnter Job ID, Deadline and Profit:\n";

        for(int i = 0; i < n; i++)
        {
            cin >> job[i].id
                >> job[i].deadline
                >> job[i].profit;
        }
    }

    // Sort jobs by profit (descending)
    void sortJobs()
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(job[i].profit < job[j].profit)
                {
                    swap(job[i], job[j]);
                }
            }
        }
    }

    // Job Sequencing Algorithm
    void sequenceJobs()
    {
        sortJobs();

        int maxDeadline = 0;

        // Find maximum deadline
        for(int i = 0; i < n; i++)
        {
            if(job[i].deadline > maxDeadline)
            {
                maxDeadline = job[i].deadline;
            }
        }

        char slot[100];

        // Initialize slots
        for(int i = 0; i < maxDeadline; i++)
        {
            slot[i] = '-';
        }

        int totalProfit = 0;

        // Assign jobs
        for(int i = 0; i < n; i++)
        {
            for(int j = job[i].deadline - 1;
                j >= 0;
                j--)
            {
                if(slot[j] == '-')
                {
                    slot[j] = job[i].id;

                    totalProfit += job[i].profit;

                    break;
                }
            }
        }

        cout << "\nSelected Job Sequence:\n";

        for(int i = 0; i < maxDeadline; i++)
        {
//            if(slot[i] != '-')
//            {
                cout << slot[i] << " ";
//            }
        }

        cout << "\n\nMaximum Profit = "
             << totalProfit;
    }
};

int main()
{
    JobSequencing j;

    j.getData();

    j.sequenceJobs();

    return 0;
}
