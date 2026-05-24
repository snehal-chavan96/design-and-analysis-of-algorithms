#include <iostream>
#include <cstring>

using namespace std;

class RabinKarp
{
    char text[1000];
    char pattern[100];

public:

    void getData()
    {
        cout << "Enter text: ";
        cin >> text;

        cout << "Enter pattern: ";
        cin >> pattern;
    }

    void searchPattern()
    {
        int n = strlen(text);
        int m = strlen(pattern);

        int patternHash = 0;
        int textHash = 0;

        // Calculate pattern hash
        cout << "\nPattern Character Hash Values:\n";

        for(int i = 0; i < m; i++)
        {
            cout << pattern[i]
                 << " = "
                 << (int)pattern[i]
                 << endl;

            patternHash += pattern[i];
        }

        cout << "\nPattern Total Hash = "
             << patternHash << endl;

        // First window hash
        for(int i = 0; i < m; i++)
        {
            textHash += text[i];
        }

        cout << "\nIndex\tWindow\tHash\n";
        cout << "-----------------------------\n";

        // Sliding window
        for(int i = 0; i <= n - m; i++)
        {
            // Print current window
            cout << i << "\t";

            for(int j = 0; j < m; j++)
            {
                cout << text[i + j];
            }

            cout << "\t" << textHash << endl;

            // If hash matches
            if(patternHash == textHash)
            {
                int j;

                // Character comparison
                for(j = 0; j < m; j++)
                {
                    if(text[i + j] != pattern[j])
                    {
                        break;
                    }
                }

                if(j == m)
                {
                    cout << "Pattern found at index "
                         << i << endl;
                }
            }

            // Next window hash
            if(i < n - m)
            {
                textHash =
                    textHash
                    - text[i]
                    + text[i + m];
            }
        }
    }
};

int main()
{
    RabinKarp r;

    r.getData();

    r.searchPattern();

    return 0;
}
