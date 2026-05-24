#include <iostream>
using namespace std;

class SumOfSubsets {
private:
    int w[20], x[20];
    int n, target;

public:
    void input() {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements in increasing order:\n";
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }

        cout << "Enter target sum: ";
        cin >> target;
    }

    void printSubset() {
        cout << "Subset Found = { ";
        for (int i = 0; i < n; i++) {
            if (x[i] == 1)
                cout << w[i] << " ";
        }
        cout << "}" << endl;
    }

    void sumOfSubsets(int s, int k, int r) {

        cout << "\nCurrent Sum = " << s
             << ", Current Element = " << w[k]
             << ", Remaining Sum = " << r << endl;

        // Include current element
        x[k] = 1;

        cout << "-> Including " << w[k] << endl;

        if (s + w[k] == target) {
            printSubset();
        }
        else if (k + 1 < n && s + w[k] + w[k + 1] <= target) {
            sumOfSubsets(s + w[k], k + 1, r - w[k]);
        }

        // Exclude current element
        if (k + 1 < n &&
            (s + r - w[k] >= target) &&
            (s + w[k + 1] <= target)) {

            x[k] = 0;

            cout << "-> Excluding " << w[k] << endl;

            sumOfSubsets(s, k + 1, r - w[k]);
        }
    }

    void solve() {
        int total = 0;

        for (int i = 0; i < n; i++)
            total += w[i];

        cout << "\nSteps of Branch and Bound:\n";

        sumOfSubsets(0, 0, total);
    }
};

int main() {
    SumOfSubsets s;

    s.input();
    s.solve();

    return 0;
}
