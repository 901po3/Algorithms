#include<iostream>
using namespace std;
//
// https://www.acmicpc.net/problem/8958
//

//TYPE WITH CAPITAL LETTER!!
void OXQuiz(int n)
{
	char **arr;
	int cntO;
	int sum;

	arr = new char*[n];
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = new char[81];

		for (int j = 0; j < 81; j++)
			arr[i][j] = NULL;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		for (int j = 0; j < 80; j++)
		{
			if (arr[i][j] == NULL) break;
			if (arr[i][j] != 'O' && arr[i][j] != 'X') return;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cntO = 0;
		sum = 0;
		for (int j = 0; j < 80; j++)
		{
			if (arr[i][j] == NULL) break;
			int ch = arr[i][j];
			if (ch == 'O')
				cntO++;
			else
				cntO = 0;

			sum += cntO;
		}
		cout << sum << endl;
	}


	for (int i = 0; i < n; i++)
		delete arr[i];
	delete arr;
}


int main()
{
	int RepeatNum;

	cin >> RepeatNum;
	if (RepeatNum < 0 || RepeatNum > 80) return 0;

	OXQuiz(RepeatNum);

	return 0;
}