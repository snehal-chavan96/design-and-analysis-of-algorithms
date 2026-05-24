#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

class KMP
{
    char text[1000];
    char pattern[100];
    int lps[100];

public:

    // Input function
    void getData()
    {
        cout << "Enter text: ";
        cin >> text;

        cout << "Enter pattern: ";
        cin >> pattern;
    }

    // Construct LPS Array
    void computeLPS()
    {
        int len = 0;

        lps[0] = 0;

        int i = 1;

        int m = strlen(pattern);

        while(i < m)
        {
            if(pattern[i] == pattern[len])
            {
                len++;

                lps[i] = len;

                i++;
            }

            else
            {
                if(len != 0)
                {
                    len = lps[len - 1];
                }

                else
                {
                    lps[i] = 0;

                    i++;
                }
            }
        }
    }

    // KMP Search
    void KMPSearch()
    {
        computeLPS();

        int n = strlen(text);
        int m = strlen(pattern);

        int i = 0;
        int j = 0;

        bool found = false;

        // Start timing
        clock_t start = clock();

        while(i < n)
        {
            if(pattern[j] == text[i])
            {
                i++;
                j++;
            }

            // Pattern found
            if(j == m)
            {
                cout << "\nPattern found at index "
                     << i - j;

                found = true;

                j = lps[j - 1];
            }

            else if(i < n &&
                    pattern[j] != text[i])
            {
                if(j != 0)
                {
                    j = lps[j - 1];
                }

                else
                {
                    i++;
                }
            }
        }

        // End timing
        clock_t end = clock();

        double timeTaken =
        double(end - start) / CLOCKS_PER_SEC;

        if(!found)
        {
            cout << "\nPattern not found.";
        }

        // Display LPS Table
        cout << "\n\nLPS Table:\n";

        for(int k = 0; k < m; k++)
        {
            cout << pattern[k] << " ";
        }

        cout << endl;

        for(int k = 0; k < m; k++)
        {
            cout << lps[k] << " ";
        }

        cout << "\n\nTime Required = "
             << timeTaken
             << " seconds";
    }
};

int main()
{
    KMP k;

    k.getData();

    k.KMPSearch();

    return 0;
}
