#include <iostream>
#include <climits>

using namespace std;

class CoinChangeDP
{
    int coins[100];
    int n, amount;

public:

    // Input function
    void getData()
    {
        cout << "Enter number of coin denominations: ";
        cin >> n;

        cout << "Enter coin denominations:\n";

        for(int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }

        cout << "Enter amount: ";
        cin >> amount;
    }

    // Dynamic Programming Method
	void minCoins()
	{
	    int dp[100][1000]; // dp[coin_index][amount]
	
	    // Initialize
	    for(int i = 0; i <= n; i++)
	    {
	        for(int j = 0; j <= amount; j++)
	        {
	            dp[i][j] = INT_MAX;
	        }
	    }
	
	    // Base case: 0 coins to make 0 amount
	    for(int i = 0; i <= n; i++)
	        dp[i][0] = 0;
	
	    // Build DP table
	    for(int i = 1; i <= n; i++)
	    {
	        for(int j = 1; j <= amount; j++)
	        {
	            // Case 1: don't take coin i-1
	            dp[i][j] = dp[i-1][j];
	
	            // Case 2: take coin i-1 (if possible)
	            if(coins[i-1] <= j)
	            {
	                int subResult = dp[i][j - coins[i-1]];
	
	                if(subResult != INT_MAX)
	                {
	                    dp[i][j] = min(dp[i][j], subResult + 1);
	                }
	            }
	        }
	
	        // ?? Print table after each coin row
	
	        for(int j = 0; j <= amount; j++)
	        {
	          cout << dp[i][j] << "\t";
	        }
	        cout << "\n";
	    }
	
	    // Final answer
	    if(dp[n][amount] == INT_MAX)
	    {
	        cout << "\nAmount cannot be formed.";
	    }
	    else
	    {
	        cout << "\nMinimum coins required = " << dp[n][amount];
	    }
	}    
};

int main()
{
    CoinChangeDP c;

    c.getData();

    c.minCoins();

    return 0;
}
