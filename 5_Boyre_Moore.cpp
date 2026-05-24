#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class BoyerMoore
{
    char text[1000];
    char pattern[100];

    // Bad Character Table
    int badChar[256];

    // Good Suffix Tables
    int goodSuffix[105];
    int bpos[105];

public:

    // -----------------------------------------
    // Input
    // -----------------------------------------
    void getData()
    {
        cout << "Enter text: ";
        cin >> text;

        cout << "Enter pattern: ";
        cin >> pattern;
    }

    // -----------------------------------------
    // 1. Bad Character Heuristic
    // -----------------------------------------
    void badCharacterHeuristic(int m)
    {
        // Initialize all occurrences as -1
        for(int i = 0; i < 256; i++)
        {
            badChar[i] = -1;
        }

        // Store last occurrence of each character
        for(int i = 0; i < m; i++)
        {
            badChar[(unsigned char)pattern[i]] = i;
        }
    }

    // -----------------------------------------
    // 2A. Strong Good Suffix Preprocessing
    // -----------------------------------------
    void preprocessStrongSuffix(int m)
    {
        int i = m;
        int j = m + 1;

        bpos[i] = j;

        // Initialize goodSuffix array
        for(int k = 0; k <= m; k++)
        {
            goodSuffix[k] = 0;
        }

        while(i > 0)
        {
            // Search for border
            while(j <= m &&
                  pattern[i - 1] != pattern[j - 1])
            {
                if(goodSuffix[j] == 0)
                {
                    goodSuffix[j] = j - i;
                }

                j = bpos[j];
            }

            i--;
            j--;

            bpos[i] = j;
        }
    }

    // -----------------------------------------
    // 2B. Case 2 Preprocessing
    // -----------------------------------------
    void preprocessCase2(int m)
    {
        int j = bpos[0];

        for(int i = 0; i <= m; i++)
        {
            if(goodSuffix[i] == 0)
            {
                goodSuffix[i] = j;
            }

            if(i == j)
            {
                j = bpos[j];
            }
        }
    }

    // -----------------------------------------
    // 3. Boyer Moore Search
    // -----------------------------------------
    void searchPattern()
    {
        int n = strlen(text);
        int m = strlen(pattern);

        // Edge case
        if(m == 0)
        {
            cout << "Empty pattern.\n";
            return;
        }

        // Build tables
        badCharacterHeuristic(m);
        preprocessStrongSuffix(m);
        preprocessCase2(m);

        int shift = 0;
        bool found = false;

        while(shift <= (n - m))
        {
            int j = m - 1;

            // Compare from right to left
            while(j >= 0 &&
                  pattern[j] == text[shift + j])
            {
                j--;
            }

            // Pattern found
            if(j < 0)
            {
                cout << "\nPattern found at index "
                     << shift;

                found = true;

                // Shift pattern safely
                shift += (goodSuffix[0] > 0)
                         ? goodSuffix[0]
                         : 1;
            }
            else
            {
                // Bad Character Shift
                int badCharShift =
                    j - badChar[(unsigned char)
                                text[shift + j]];

                // Must shift at least 1
                badCharShift = max(1, badCharShift);

                // Good Suffix Shift
                int goodSuffixShift =
                    goodSuffix[j + 1];

                // Take maximum
                shift += max(badCharShift,
                             goodSuffixShift);
            }
        }

        if(!found)
        {
            cout << "\nPattern not found.";
        }

        // -----------------------------------------
        // Display Bad Character Table
        // -----------------------------------------
        cout << "\n\nBad Character Table:\n";

        for(int i = 0; i < m; i++)
        {
            cout << pattern[i]
                 << " -> "
                 << badChar[(unsigned char)
                            pattern[i]]
                 << endl;
        }

        // -----------------------------------------
        // Display Good Suffix Table
        // -----------------------------------------
        cout << "\nGood Suffix Table:\n";

        cout << "Full match shift -> "
             << goodSuffix[0]
             << endl;

        for(int i = 1; i <= m; i++)
        {
            cout << "Mismatch at position "
                 << i - 1
                 << " -> Shift: "
                 << goodSuffix[i]
                 << endl;
        }
    }
};

// -----------------------------------------
// Main
// -----------------------------------------
int main()
{
    BoyerMoore bm;

    bm.getData();

    bm.searchPattern();

    return 0;
}
