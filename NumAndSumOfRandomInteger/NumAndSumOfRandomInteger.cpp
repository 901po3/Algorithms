#include<iostream>
using namespace std;

void main()
{
	int num;
	int count = 0;
	int sum = 0;

	cout<<"type random integer number : ";
	cin >> num;

	for(int i=1; i<= num; i++)
	{
		if(num%i==0)
		{
			sum += i;
			count++;
		}
	}

	cout<<"number of mutiple(s) : "<<count<<endl;
	cout<<"sum of mutiple(s) : "<<sum<<endl;
}