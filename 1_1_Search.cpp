#include <iostream>
#include <ctime>
#include <cstdlib >
using namespace std;

class Search
{
	int arr[100],n;
	
public:
	void getData(){
		cout<<"Enter number of elements: ";
		cin>>n;
		
		cout<< "Enter sorted elements:\n";
		
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
	}
	
	void linearSearch(int key){
		int i;
		for(int i=0;i<n;i++){
			cout<<"\nFinding element "<<key<< " at pos "<<i+1<<endl;
			if(arr[i] == key)
			{
				cout<<"Element found at position "
					<< i+1 << " using Linear Search\n";
					return;
			}
		}
		cout<<"Element not found using Linear Search\n";
	}
	
	void binarySearch(int key){
		int low = 0,high=n-1,mid;
		
		while(low<=high)
		{
			mid = (low+high)/2;
			
			cout<<"\nFinding element "<<key<< " at pos "<<mid+1<<endl;

			
			if(arr[mid] == key)
			{
				cout<<"Element found at position "
					<< mid + 1<< " using Binary Search\n";
					return;
			}
			else if(arr[mid] < key){
				low = mid + 1;
			}
			else{
				high = mid -1;
			}
		}
		cout<< "Element not found using Binary Search\n";
	}
	
	void modifiedBinarySearch(int key){
		int low = 0, high=n-1,mid;
		
		srand(time(0));
		
		while(low<=high){
			mid = low + rand() % (high - low + 1);
			
			cout<<"\nFinding element "<<key<< " at pos "<<mid+1<<endl;

			
			if(arr[mid]==key){
				cout<<"Element found at position "
					<< mid+1
					<<" using Modified Binary Search\n";
					return;
			}
			else if(arr[mid]<key){
				low = mid + 1;
			}
			else{
				high = mid - 1;
			}
		}
		
		cout<<"Element not found using Modified Binary Search\n";
	}
};

int main(){
	Search s;
	
	int key;
	
	s.getData();
	
	cout<<"Enter element to search: ";
	cin>> key;
	
	cout<<"\n";
	
	s.linearSearch(key);
	s.binarySearch(key);
	s.modifiedBinarySearch(key);
	
	return 0;
}
