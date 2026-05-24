#include <iostream>
#include <algorithm>
using namespace std;

class MinMax
{
	int arr[100], n;
	
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
	
	void findMinMax(int low, int high, int &mini, int &maxi){
		int mid;
		int min1, max1;
		int min2, max2;
		
		if(low == high)
		{
			mini = maxi = arr[low];
		}
		
		else if(high==low+1)
		
		{

			mini = min(arr[low],arr[high]);
			maxi = max(arr[high],arr[low]);

	}
	
	else{
		mid = (low + high)/2;
		
		findMinMax(low,mid,min1,max1);
		
		findMinMax(mid+1,high,min2,max2);
		
	
		mini = min(min1,min2);
		maxi = max(max1,max2);

	}
}
	
	void display(){
		int mini,maxi;
		
		findMinMax(0,n-1,mini,maxi);
		
		cout<<"\nMinimum element = "<<mini;
		cout<<"\nMaximum element = "<<maxi;
	}
};

int main(){
	MinMax m;
	m.getData();
	m.display();
	
	return 0;
}
