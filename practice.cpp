#include <iostream>
#include <algorithm>

using namespace std;

class KnapSack{
	struct Item{
		int weight;
		int profit;
		float ratio;
		
	};
	
	Item item[100];
	
	int n, capacity;
	
public:
	
	void getData(){
		cout<<"Enter number of items: ";
		cin>>n;
		
		for(int i=0;i<n;i++){
			
			cout<<"Enter profits: ";
			cin>>item[i].profit;
			
			cout<<"Enter weights: ";
			cin>>item[i].weight;
			
			item[i].ratio = (float) item[i].profit / item[i].weight;						
			
		}
		
		cin>>capacity;
	}
	void sortItems(){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(item[i].ratio<item[j].ratio){
					swap(item[i],item[j]);
				}
			}
		}
	}
	
	void knapsack(){
		sortItems();
		float tp = 0.0;
		int u = capacity;
		for(int i=0;i<n;i++){
			if(item[i].weight<u){
				u -= item[i].weight;
				tp += item[i].profit;
			}
			else{
				float fr = (float) u/item[i].weight;
				
				tp += item[i].profit * fr;
				break;
			}
		}
		
		cout<<tp;
	}
	
};

int main(){
	KnapSack k1;
	
	k1.getData();
	k1.knapsack();
	
	return 0;
}
