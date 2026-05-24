#include <iostream>
#include <climits>

using namespace std;

#define N 4

class TSP
{
    int graph[N][N];

    int finalPath[N + 1];
    bool visited[N];

    int finalCost;

public:

    // Constructor
    TSP()
    {
        finalCost = INT_MAX;

        for(int i = 0; i < N; i++)
        {
            visited[i] = false;
        }
    }

    // Input graph
    void getGraph()
    {
        cout << "Enter Cost Matrix:\n";

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cin >> graph[i][j];
            }
        }
    }

    // Find minimum edge cost for a city
    int firstMin(int i)
    {
        int min = INT_MAX;

        for(int k = 0; k < N; k++)
        {
            if(graph[i][k] < min && i != k)
            {
                min = graph[i][k];
            }
        }

        return min;
    }

    // Find second minimum edge cost
    int secondMin(int i)
    {
        int first = INT_MAX;
        int second = INT_MAX;

        for(int j = 0; j < N; j++)
        {
            if(i == j)
                continue;

            if(graph[i][j] <= first)
            {
                second = first;
                first = graph[i][j];
            }
            else if(graph[i][j] < second &&
                    graph[i][j] != first)
            {
                second = graph[i][j];
            }
        }

        return second;
    }

    // Recursive Branch and Bound
    void tspRec(int currBound,
                int currWeight,
                int level,
                int currPath[])
    {
        // All cities visited
        if(level == N)
        {
            // Return to starting city
            if(graph[currPath[level - 1]][currPath[0]] != 0)
            {
                int currRes =
                    currWeight +
                    graph[currPath[level - 1]][currPath[0]];

                // Update final result
                if(currRes < finalCost)
                {
                    for(int i = 0; i < N; i++)
                    {
                        finalPath[i] = currPath[i];
                    }

                    finalPath[N] = currPath[0];
                    finalCost = currRes;
                }
            }

            return;
        }

        // Try next city
        for(int i = 0; i < N; i++)
        {
            if(graph[currPath[level - 1]][i] != 0 &&
               visited[i] == false)
            {
                int temp = currBound;

                currWeight +=
                    graph[currPath[level - 1]][i];

                // Calculate new bound
                if(level == 1)
                {
                    currBound -=
                    ((firstMin(currPath[level - 1]) +
                      firstMin(i)) / 2);
                }
                else
                {
                    currBound -=
                    ((secondMin(currPath[level - 1]) +
                      firstMin(i)) / 2);
                }

                // Continue only if promising
                if(currBound + currWeight < finalCost)
                {
                    currPath[level] = i;
                    visited[i] = true;

                    tspRec(currBound,
                           currWeight,
                           level + 1,
                           currPath);
                }

                // Backtrack
                currWeight -=
                    graph[currPath[level - 1]][i];

                currBound = temp;

                for(int j = 0; j < N; j++)
                {
                    visited[j] = false;
                }

                for(int j = 0; j < level; j++)
                {
                    visited[currPath[j]] = true;
                }
            }
        }
    }

    // Main function
    void solve()
    {
        int currPath[N + 1];

        int currBound = 0;

        // Compute initial lower bound
        for(int i = 0; i < N; i++)
        {
            currBound +=
                (firstMin(i) + secondMin(i));
        }

        // Round up
        currBound =
            (currBound & 1) ?
            currBound / 2 + 1 :
            currBound / 2;

        visited[0] = true;
        currPath[0] = 0;

        tspRec(currBound,
               0,
               1,
               currPath);

        // Output
        cout << "\nMinimum Cost = "
             << finalCost;

        cout << "\nPath: ";

        for(int i = 0; i <= N; i++)
        {
            cout << finalPath[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    TSP t;

    t.getGraph();

    t.solve();

    return 0;
}
