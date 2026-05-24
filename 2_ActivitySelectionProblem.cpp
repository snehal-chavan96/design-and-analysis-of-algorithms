#include <iostream>

using namespace std;

class ActivitySelection
{
    struct Activity
    {
        int start;
        int finish;
    };

    Activity act[100];

    int n;

public:

    // Input function
    void getData()
    {
        cout << "Enter number of activities: ";
        cin >> n;

        cout << "\nEnter start and finish times:\n";

        for(int i = 0; i < n; i++)
        {
            cout << "\nActivity " << i + 1 << ":\n";

            cout << "Start time: ";
            cin >> act[i].start;

            cout << "Finish time: ";
            cin >> act[i].finish;
        }
    }

    // Sort activities by finish time
    void sortActivities()
    {
        for(int i = 0; i < n - 1; i++)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(act[i].finish > act[j].finish)
                {
                    swap(act[i], act[j]);
                }
            }
        }
    }

    // Activity Selection
    void selectActivities()
    {
        sortActivities();

        cout << "\nSelected Activities:\n";

        int i = 0;

        cout << "Activity 1 "
             << "(" << act[i].start
             << "," << act[i].finish << ")\n";

        // Select remaining activities
        for(int j = 1; j < n; j++)
        {
            if(act[j].start >= act[i].finish)
            {
                cout << "Activity "
                     << j + 1
                     << " ("
                     << act[j].start
                     << ","
                     << act[j].finish
                     << ")\n";

                i = j;
            }
        }
    }
};

int main()
{
    ActivitySelection a;

    a.getData();

    a.selectActivities();

    return 0;
}
