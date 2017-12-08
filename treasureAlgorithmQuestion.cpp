#include <iostream>
using namespace std;
/*
https://www.acmicpc.net/problem/1026
*/

void ShellSort(int a[], int n);

int main()
{
	int n; //length of array;
	cin >> n;
	if (n < 0 || n > 50) return 0;
	int *A = new int[n];
	int *B = new int[n];
	int inputValue;
	int s = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> inputValue;
		A[i] = inputValue;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> inputValue;
		B[i] = inputValue;
	}

	ShellSort(A, n);
	ShellSort(B, n);

	int j = n - 1;
	for (int i = 0; i < n; i++)
	{
		s += A[i] * B[j--];
	}
	cout << s << endl;

	delete[]A;
	delete[]B;

	system("pause");
	return 0;
}

void ShellSort(int a[], int n)
{
	int i, j;
	int gap;
	int saveValue;
	int saveIndex;

	for (gap = 1; gap < n; gap = 3 * gap + 1); 
	for (gap /= 3; gap > 0; gap /= 3)
	{
		for (i = 0; i < gap; i++)
		{
			for (j = gap + i; j < n; j += gap)
			{
				saveValue = a[j];
				saveIndex = j;
				while (saveIndex > gap - 1 && saveValue < a[saveIndex - gap])
				{
					a[saveIndex] = a[saveIndex - gap];
					saveIndex -= gap;
				}
				a[saveIndex] = saveValue;
			}
		}
	}
}
