#include <iostream>
#include <iomanip>

using namespace std;

class Knapsack
{
    int weight[100], profit[100];
    int dp[100][100];
    int n, capacity;

public:

    // Input function
    void getData()
    {
        cout << "Enter number of items: ";
        cin >> n;

        cout << "\nEnter weights:\n";

        for(int i = 1; i <= n; i++)
        {
            cin >> weight[i];
        }

        cout << "\nEnter profits:\n";

        for(int i = 1; i <= n; i++)
        {
            cin >> profit[i];
        }

        cout << "\nEnter knapsack capacity: ";
        cin >> capacity;
    }

    // Dynamic Programming Solution
    void solveKnapsack()
    {
        // Initialize table
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= capacity; j++)
            {
                if(i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }

                else if(weight[i] <= j)
                {
                    dp[i][j] = max(
                        profit[i]
                        + dp[i - 1][j - weight[i]],

                        dp[i - 1][j]
                    );
                }

                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        display();
    }

    // Display DP Table and Result
	void display()
	{
	    cout << "\nDP Table:\n";
	
	    for(int i = 0; i <= n; i++)
	    {
	        for(int w = 0; w <= capacity; w++)
	        {
	            cout << setw(4)
	                 << dp[i][w];
	        }
	
	        cout << endl;
	    }
	
	    cout << "\nMaximum Profit = "
	         << dp[n][capacity];
	
	    // ?? ADD THIS PART
	    cout << "\n\nSelected Items:\n";
	
	    int i = n;
	    int w = capacity;
	
	    while(i > 0 && w > 0)
	    {
	        // Item was selected
	        if(dp[i][w] != dp[i - 1][w])
	        {
	            cout << "Item " << i
	                 << " (Weight = "
	                 << weight[i]
	                 << ", Profit = "
	                 << profit[i]
	                 << ")\n";
	
	            w = w - weight[i];
	        }
	
	        i--;
	    }
	}
};

int main()
{
    Knapsack k;

    k.getData();

    k.solveKnapsack();

    return 0;
}
