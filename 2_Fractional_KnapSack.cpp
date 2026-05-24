#include <iostream>
#include <algorithm>

using namespace std;

class Knapsack
{
    struct Item
    {
        int weight;
        int profit;
        float ratio;
    };

    Item item[100];

    int n, capacity;

public:

    // Input function
    void getData()
    {
        cout << "Enter number of items: ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cout << "\nEnter weight of item " << i + 1 << ": ";
            cin >> item[i].weight;

            cout << "Enter profit of item " << i + 1 << ": ";
            cin >> item[i].profit;

            // Profit/Weight ratio
            item[i].ratio =
            (float)item[i].profit / item[i].weight;
        }

        cout << "\nEnter knapsack capacity: ";
        cin >> capacity;
    }

    // Sort items by ratio in descending order
    void sortItems()
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(item[i].ratio < item[j].ratio)
                {
                    swap(item[i], item[j]);
                }
            }
        }
    }

    // Fractional Knapsack
    void fractionalKnapsack()
    {
        sortItems();

        float totalProfit = 0.0;

        int remaining = capacity;

        cout << "\nSelected items:\n";

        for(int i = 0; i < n; i++)
        {
            // Full item can be taken
            if(item[i].weight <= remaining)
            {
                cout << "Item with weight "
                     << item[i].weight
                     << " and profit "
                     << item[i].profit
                     << " taken completely.\n";

                remaining -= item[i].weight;

                totalProfit += item[i].profit;
            }

            // Fraction of item taken
            else
            {
                float fraction =
                (float)remaining / item[i].weight;

                cout << "Fraction "
                     << fraction
                     << " of item with weight "
                     << item[i].weight
                     << " taken.\n";

                totalProfit +=
                item[i].profit * fraction;

                break;
            }
        }

        cout << "\nMaximum Profit = "
             << totalProfit;
    }
    
    
};

int main()
{
    Knapsack k;

    k.getData();

    k.fractionalKnapsack();

    return 0;
}
