#include<iostream>
using namespace std;

void main()
{
	int i, j;
	int count = 1;

	cout<<"Calculating number(s) of prime number from the numbers between 0 to 1000"<<endl;

	for(i = 1; i <= 1000; i++)
	{
		for(j = 2; j < i; j++)
		{
			if(i % j == 0)
				break;
		}

		if(i == j)
		{
			cout<<i<<"	";
			count++;

			if(count % 8 ==  0)
				cout<<endl;
		}
	}

	cout<<"Number(s) of prime number is "<<count<<endl;
}