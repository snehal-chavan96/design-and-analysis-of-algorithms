#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class LargeInteger
{
public:
	int digits(long long n)
	{
		int count = 0;
		
		while(n>0)
		{
			count++;
			n = n/10;
		}
		
		return count;
	}
	
	long long multiply(long long x, long long y)	
	{
		if(x<10 || y<10){
			return x*y;
		}
		
		int n = max(digits(x), digits(y));
		
		int half = n/2;
		
		long long power = pow(10,half);
		
		long long a = x / power;
		long long b = x % power;
		
		long long c = y / power;
		long long d = y % power;
		
		long long ac = multiply(a,c);
		
		long long bd = multiply(b,d);
		
		long long adbc = multiply(a + b, c + d) - ac - bd;
		
		return (ac * pow(10,2*half))
				+ (adbc * power)
				+ bd;
	
	}		
		
};

int main(){
	LargeInteger obj;
	
	long long num1,num2;
	
	cout<<"Enter first large number: ";
	cin>>num1;
	
	cout<<"Enter second large number: ";
	cin>>num2;
	
	long long result = obj.multiply(num1,num2);
	
	cout<<"\nMultiplication result = "<<result;
	
	return 0;
}



