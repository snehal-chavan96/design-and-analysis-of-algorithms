#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <random>

using namespace std;

class NQueens
{
    int board[20][20];
    int n;

public:

    void getData()
    {
        cout << "Enter value of N: ";
        cin >> n;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                board[i][j] = 0;
    }

    bool isSafe(int row, int col)
    {
        for(int i = 0; i < col; i++)
            if(board[row][i]) return false;

        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if(board[i][j]) return false;

        for(int i = row, j = col; i < n && j >= 0; i++, j--)
            if(board[i][j]) return false;

        return true;
    }

    bool solveNQ(int col)
    {
        if(col >= n) return true;

        vector<int> rows;
        for(int i = 0; i < n; i++)
            rows.push_back(i);

        shuffle(rows.begin(), rows.end(),
                std::mt19937(std::random_device{}()));

        for(int i = 0; i < n; i++)
        {
            int r = rows[i];

            if(isSafe(r, col))
            {
                board[r][col] = 1;

                if(solveNQ(col + 1))
                    return true;

                board[r][col] = 0;
            }
        }

        return false;
    }

    void display()
    {
        if(!solveNQ(0))
        {
            cout << "Solution does not exist.\n";
            return;
        }

        cout << "\nSolution Matrix:\n";

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    NQueens q;
    srand(time(0));

    q.getData();
    q.display();

    return 0;
}
