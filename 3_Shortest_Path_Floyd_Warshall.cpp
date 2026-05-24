#include <iostream>
#include <iomanip>

using namespace std;

class FloydWarshall
{
    int graph[20][20];
    int dist[20][20];
    int n;

public:

    // Input function
    void getData()
    {
        cout << "Enter number of vertices: ";
        cin >> n;

        cout << "\nEnter adjacency matrix:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> graph[i][j];

                dist[i][j] = graph[i][j];
            }
        }
    }

    // Floyd Warshall Algorithm
    void floydWarshall()
    {
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    // Update shortest distance
                    if(dist[i][k] + dist[k][j]
                       < dist[i][j])
                    {
                        dist[i][j] =
                        dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        display();
    }

    // Display shortest path matrix
    void display()
    {
        cout << "\nShortest Path Matrix:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << setw(5)
                     << dist[i][j];
            }

            cout << endl;
        }
    }
};

int main()
{
    FloydWarshall f;

    f.getData();

    f.floydWarshall();

    return 0;
}
