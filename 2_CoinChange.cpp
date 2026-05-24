#include <iostream>
#include <algorithm>

using namespace std;

class CoinChange
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

        cout << "Enter amount to pay: ";
        cin >> amount;
    }

    // Sort denominations in descending order
    void sortCoins()
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(coins[i] < coins[j])
                {
                    swap(coins[i], coins[j]);
                }
            }
        }
    }

    // Greedy Coin Change
    void coinChange()
    {
        sortCoins();

        int count = 0;

        cout << "\nCoins used:\n";

        for(int i = 0; i < n; i++)
        {
            while(amount >= coins[i])
            {
                amount = amount - coins[i];

                cout << coins[i] << " ";

                count++;
            }
        }

        cout << "\n\nMinimum number of coins = "
             << count;
    }
};

int main()
{
    CoinChange c;

    c.getData();

    c.coinChange();

    return 0;
}
