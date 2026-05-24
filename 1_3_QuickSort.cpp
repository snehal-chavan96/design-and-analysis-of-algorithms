#include <iostream>
#include <algorithm>

using namespace std;

class QuickSort{
	int arr[100],n;
	int pass = 1;
	
public:
	
	void getData()
	{
		cout<<"Enter number of elements: ";
		cin>>n;
		
		cout<<"Enter elements:\n";
		
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
	}
    // Display array
    void displayArray()
    {
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
	
	void finalOutput()
	    {
	        cout << "\nSorted Array:\n";
	
	        displayArray();
	    }
	
	int findMedian(int a[], int size)
	{
		sort(a,a+size);
		return a[size/2];
	}
	
	int medianOfMedians(int a[], int size)
	{
		if(size <= 5)
		{
			return findMedian(a,size);
		}
		
		int medians[20];
		int i;
		for(i=0;i<size/5;i++)
		{
			medians[i] = findMedian(a+i * 5, 5);
		}
		
		if(i * 5 < size)
		{
			medians[i] = findMedian(a+i * 5,size % 5);
			i++;
		}
		
		return medianOfMedians(medians,i);
	}
	
	int partition(int low, int high)
	{
	    int size = high - low + 1;
	
	    int temp[100];
	
	    for(int i = 0; i < size; i++)
	    {
	        temp[i] = arr[low + i];
	    }
	
	    int pivot = medianOfMedians(temp, size);
	
	    int pvtIdx;
	
	    for(int i = low; i <= high; i++)
	    {
	        if(arr[i] == pivot)
	        {
	            pvtIdx = i;
	            break;
	        }
	    }
	
	    swap(arr[pvtIdx], arr[high]);
	
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
	
	    cout << "\nPass " << pass++ << ": ";
	    displayArray();
	
	    return i + 1;
	}
void quickSort(int low,int high)
{
	if(low<high)
	{
		int p = partition(low,high);
		
		quickSort(low,p-1);
		
		quickSort(p+1,high);
	}
}

void sortArray()
{
	quickSort(0,n-1);
}
	
};

int main(){
	QuickSort q;
	q.getData();
	q.sortArray();
	q.finalOutput();
	
	return 0;
	
}
