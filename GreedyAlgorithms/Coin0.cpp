#include<iostream>
using namespace std;

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


//동전0 문제 해답
int main()
{
	int n, k;
	int *pNStore;
	int rest;
	int count = 0;

	cin >> n >> k;
	if (n < 1 && n > 10 && k < 1 && k > 100000000) return 0;

	pNStore = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> pNStore[i];
	}

	ShellSort(pNStore, n);
	
	for (int i = 0; i < n; i++)
	{
		rest = k % pNStore[i];
		if (i == n - 1)
			count += (k / pNStore[i]);

		if(rest != 0 && i != 0)
		{
			count += (rest / pNStore[i - 1]);
		}
	}

	cout << count;
	delete[]pNStore;

	return 0;
}