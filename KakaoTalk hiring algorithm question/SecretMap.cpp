#include<iostream>
#include<ctime>
using namespace std;

#define WALL		1
#define BLANK		0
const char WALL_SHAPE = '#';
const char BLANK_SHAPE = ' ';

int** newMap(int n)
{
	int **dpa = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		dpa[i] = (int*)malloc(sizeof(int) * n);
		for (int j = 0; j < n; j++)
		{
			dpa[i][j] = NULL;
		}
	}
	return dpa;
}

void makeMap(int **dpa, int n)
{
	int cnt = 0;
	int pick;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pick = rand() % 2;
			if (pick == 1)
			{
				if(cnt++ < n - 1)
					dpa[i][j] = WALL;
			}
			else
				dpa[i][j] = BLANK;
		}
		cnt = 0;
	}
}

void displayMap(int **dpa, int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ((dpa[i][j] == WALL) ? '#' : ' ') << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;
}

void deleteMap(int **dpa, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (dpa[i] != NULL)
			free(dpa[i]);
	}
	if (dpa != NULL)
		free(dpa);
}

void decipherMap(int **dpa1, int **dpa2, int **screetMap, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dpa1[i][j] == WALL || dpa2[i][j] == WALL)
				screetMap[i][j] = WALL;
		}
	}
}

int main()
{
	int sideN;
	int **mapOne = NULL;
	int **mapTwo = NULL;
	int **screetMap = NULL;
	srand((unsigned)time(NULL));

	cout << "select the length of side: ";
	cin >> sideN;

	mapOne = newMap(sideN);
	mapTwo = newMap(sideN);
	screetMap = newMap(sideN);

	makeMap(mapOne, sideN);
	makeMap(mapTwo, sideN);

	decipherMap(mapOne, mapTwo, screetMap, sideN);

	displayMap(mapOne, sideN);
	displayMap(mapTwo, sideN);
	displayMap(screetMap, sideN);

	deleteMap(mapOne, sideN);
	deleteMap(mapTwo, sideN);
	deleteMap(screetMap, sideN);
	system("pause");
	return 0;
}
