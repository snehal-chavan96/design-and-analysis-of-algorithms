	#include <iostream>
	#include <iomanip>
	
	using namespace std;
	
	class OBST
	{
	    int n;
	
	    float p[20], q[20];
	
	    float cost[20][20];
	    float weight[20][20];
	
	    int root[20][20];
	
	public:
	
	    // Input function
	    void getData()
	    {
	        cout << "Enter number of keys: ";
	        cin >> n;
	
	        cout << "\nEnter successful search probabilities:\n";
	
	        for(int i = 1; i <= n; i++)
	        {
	            cin >> p[i];
	        }
	
	        cout << "\nEnter unsuccessful search probabilities:\n";
	
	        for(int i = 0; i <= n; i++)
	        {
	            cin >> q[i];
	        }
	    }
	
	    // Construct Optimal BST
	    void constructOBST()
	    {
	        // Initialize all matrices
	        for(int i = 0; i < 20; i++)
	        {
	            for(int j = 0; j < 20; j++)
	            {
	                cost[i][j] = 0;
	                weight[i][j] = 0;
	                root[i][j] = 0;
	            }
	        }
	
	        // Base condition
	        for(int i = 0; i <= n; i++)
	        {
	            cost[i][i] = 0;
	
	            weight[i][i] = q[i];
	        }
	
	        // Length of subtree
	        for(int len = 1; len <= n; len++)
	        {
	            for(int i = 0; i <= n - len; i++)
	            {
	                int j = i + len;
	
	                cost[i][j] = 9999;
	
	                // Calculate weight
	                weight[i][j] =
	                weight[i][j - 1]
	                + p[j]
	                + q[j];
	
	                // Find optimal root
	                for(int r = i + 1; r <= j; r++)
	                {
	                    float c =
	                    cost[i][r - 1]
	                    + cost[r][j]
	                    + weight[i][j];
	
	                    // Minimum cost
	                    if(c < cost[i][j])
	                    {
	                        cost[i][j] = c;
	
	                        root[i][j] = r;
	                    }
	                }
	            }
	        }
	
	        display();
	    }
	
	    // Display matrices
	    void display()
	    {
	        cout << "\nCost Matrix:\n\n";
	
	        for(int i = 0; i <= n; i++)
	        {
	            for(int j = 0; j <= n; j++)
	            {
	                cout << setw(8)
	                     << cost[i][j] << " ";
	            }
	
	            cout << endl;
	        }
	
	        cout << "\nRoot Matrix:\n\n";
	
	        for(int i = 0; i <= n; i++)
	        {
	            for(int j = 0; j <= n; j++)
	            {
	                cout << setw(5)
	                     << root[i][j] << " ";
	            }
	
	            cout << endl;
	        }
	
	        cout << "\nMinimum Expected Cost = "
	             << cost[0][n];
	    }
	};
	
	int main()
	{
	    OBST o;
	
	    o.getData();
	
	    o.constructOBST();
	
	    return 0;
	}
