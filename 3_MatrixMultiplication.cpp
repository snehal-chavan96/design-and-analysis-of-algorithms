#include <iostream>
#include <climits>
#include <iomanip>

using namespace std;

class MatrixChain
{
    int p[20];
    int m[20][20];
    int n;

public:

    // Input function
    void getData()
    {
        cout << "Enter number of matrices: ";
        cin >> n;

        cout << "\nEnter dimensions array:\n";

        cout << "Enter " << n + 1
             << " values:\n";

        for(int i = 0; i <= n; i++)
        {
            cin >> p[i];
        }
    }

    // Matrix Chain Multiplication
    void matrixChainOrder()
    {
        int i, j, k, L, q;

        // Cost is zero for one matrix
        for(i = 1; i <= n; i++)
        {
            m[i][i] = 0;
        }

        // L = chain length
        for(L = 2; L <= n; L++)
        {
            for(i = 1; i <= n - L + 1; i++)
            {
                j = i + L - 1;

                m[i][j] = INT_MAX;

                for(k = i; k < j; k++)
                {
                    q = m[i][k]
                        + m[k + 1][j]
                        + p[i - 1] * p[k] * p[j];

                    if(q < m[i][j])
                    {
                        m[i][j] = q;
                    }
                }
            }
        }

        display();
    }

    // Display result
    void display()
    {
        cout << "\nCost Matrix:\n";

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(i > j)
                    cout << setw(6) << "-";
                else
                    cout << setw(6) << m[i][j];
            }

            cout << endl;
        }

        cout << "\nMinimum number of multiplications = "
             << m[1][n];
    }
};

int main()
{
    MatrixChain mc;

    mc.getData();

    mc.matrixChainOrder();

    return 0;
}
