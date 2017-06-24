#include<iostream>
using namespace std;

void main()
{
	int maxLine;
	int	num;
	int lineNumber;
	int data;

	cout<<"put length of width and height : "; 
	cin>> num;

	maxLine = num;

	for(lineNumber = 1; lineNumber <= maxLine; lineNumber++)
	{
		if(lineNumber % 2 == 0)
		{
			for(data = (lineNumber * num) ; data >= (lineNumber * num) - (num - 1); data--)
				cout<<data<<"	";

			cout<<endl;
		}
		else
		{
			for(data = ((lineNumber - 1) * (num)) + 1 ; data < lineNumber * num + 1; data++)
				cout<<data<<"	";
			
			cout<<endl;
		}
	}
}