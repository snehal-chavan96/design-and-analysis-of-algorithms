#include <iostream>
#include <climits>

using namespace std;

class TSP
{
    int graph[10][10];
    int visited[10];
    int n;

    int minCost = INT_MAX;

public:

    // Input function
    void getData()
    {
        cout << "Enter number of cities: ";
        cin >> n;

        cout << "\nEnter cost matrix:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> graph[i][j];
            }
        }
    }

    // Recursive TSP function
    void tsp(int city,
             int count,
             int cost)
    {
        // All cities visited
        if(count == n &&
           graph[city][0] > 0)
        {
            minCost =
            min(minCost,
                cost + graph[city][0]);

            return;
        }

        // Visit next city
        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 0 &&
               graph[city][i] > 0)
            {
                visited[i] = 1;

                tsp(i,
                    count + 1,
                    cost + graph[city][i]);

                visited[i] = 0;
            }
        }
    }

    // Start TSP
	void solve()
	{
	    // Initialize visited array
	    for(int i = 0; i < n; i++)
	    {
	        visited[i] = 0;
	    }
	
	    visited[0] = 1;
	
	    tsp(0, 1, 0);
	
	    cout << "\nMinimum Travelling Cost = "
	         << minCost;
	}
};

int main()
{
    TSP t;

    t.getData();

    t.solve();

    return 0;
}
