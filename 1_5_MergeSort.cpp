#include <iostream>

using namespace std;

class MergeSort
{
    int arr[100], n;

public:

    // Function to accept array
    void getData()
    {
        cout << "Enter number of elements: ";
        cin >> n;

        cout << "Enter elements:\n";

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }

    // Merge function
    void merge(int low, int mid, int high)
    {
        int temp[100];

        int i = low;
        int j = mid + 1;
        int k = low;

        // Merge two sorted halves
        while(i <= mid && j <= high)
        {
            if(arr[i] < arr[j])
            {
                temp[k] = arr[i];
                i++;
            }
            else
            {
                temp[k] = arr[j];
                j++;
            }

            k++;
        }

        // Copy remaining elements
        while(i <= mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }

        while(j <= high)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }

        // Copy back to original array
        for(i = low; i <= high; i++)
        {
            arr[i] = temp[i];
        }
    }

    // Merge Sort function
    void mergeSort(int low, int high)
    {
        if(low < high)
        {
            int mid = (low + high) / 2;

            // Left half
            mergeSort(low, mid);

            // Right half
            mergeSort(mid + 1, high);

            // Merge halves
            merge(low, mid, high);
        }
    }

    // Start sorting
    void sortArray()
    {
        mergeSort(0, n - 1);
    }

    // Display sorted array
    void display()
    {
        cout << "\nSorted array:\n";

        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{
    MergeSort m;

    m.getData();

    m.sortArray();

    m.display();

    return 0;
}
