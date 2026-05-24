#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class RandomizedQuickSort
{
    int arr[100];
    int n;

public:

    // Input function
    void getData()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter array elements:\n";

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    // Swap function
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // Partition function
    int partition(int low, int high)
    {
        int pivot = arr[high];

        int i = low - 1;

        for(int j = low; j < high; j++)
        {
            if(arr[j] < pivot)
            {
                i++;

                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);

        return i + 1;
    }

    // Randomized Partition
    int randomizedPartition(int low, int high)
    {
        int random =
        low + rand() % (high - low + 1);

        swap(arr[random], arr[high]);

        return partition(low, high);
    }

    // Randomized Quick Sort
    void quickSort(int low, int high)
    {
        if(low < high)
        {
            int pi =
            randomizedPartition(low, high);

            quickSort(low, pi - 1);

            quickSort(pi + 1, high);
        }
    }

    // Display sorted array
    void display()
    {
        cout << "\nSorted Array:\n";

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }

    // Start sorting
    void start()
    {
        srand(time(0));

        quickSort(0, n - 1);

        display();
    }
};

int main()
{
    RandomizedQuickSort q;

    q.getData();

    q.start();

    return 0;
}
