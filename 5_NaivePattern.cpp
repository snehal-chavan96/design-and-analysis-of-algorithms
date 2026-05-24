#include <iostream>
#include <cstring>

using namespace std;

class NaivePattern
{
    char text[100];
    char pattern[100];

public:

    // Input function
    void getData()
    {
        cout << "Enter text: ";
        cin >> text;

        cout << "Enter pattern: ";
        cin >> pattern;
    }

    // Naive Pattern Matching
    void searchPattern()
    {
        int n = strlen(text);
        int m = strlen(pattern);

        bool found = false;

        // Slide pattern over text
        for(int i = 0; i <= n - m; i++)
        {
            int j;

            // Compare pattern characters
            for(j = 0; j < m; j++)
            {
                if(text[i + j] != pattern[j])
                {
                    break;
                }
            }

            // Pattern found
            if(j == m)
            {
                cout << "\nPattern found at position "
                     << i + 1;

                found = true;
            }
        }

        if(!found)
        {
            cout << "\nPattern not found.";
        }
    }
};

int main()
{
    NaivePattern n;

    n.getData();

    n.searchPattern();

    return 0;
}
