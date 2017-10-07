#include<iostream>
#include<ctime>
using namespace std;

#define ATTEMPT		5
#define SINGLE		1
#define DOUBLE		2
#define TRIPLE		3
#define MAX_SCORE	10
#define MIN_SCORE	0
#define GOOD_PRICE	0
#define BAD_PRICE	1

#define intToChar(n)	n + 48
#define charToInt(ch)	ch - 48
//int score[ATTEMPT];

int power(int num, int n)
{
	int originN = num;
	for (int i = 0; i < n - 1; i++)
		num *= originN;
	return num;
}

int setGame(char *str)
{
	int bonus, price, score;
	int count = 0, i = 0;

	while (count++ < ATTEMPT)
	{
		bonus = rand() % 3 + 1;
		price = rand() % 3;
		score = rand() % 11;
		
		str[i++] = intToChar(score);

		if (bonus == SINGLE)
			str[i++] = 'S';
		else if (bonus == DOUBLE)
			str[i++] = 'D';
		else if (bonus == TRIPLE)
			str[i++] = 'T';

		if (price == GOOD_PRICE)
			str[i++] = '*';
		else if (price == BAD_PRICE)
			str[i++] = '#';
	}
	return i;
}

int calculateScore(char *str, int len)
{
	int score[ATTEMPT];
	int i = 0, cnt = 0;
	int sum = 0;

	while(cnt < ATTEMPT)
	{
		if (str[i] >= 48 && str[i] <= 58)
		{
			score[cnt] = charToInt(str[i++]);
			score[cnt] = ((str[i] == 'S') ? score[cnt] : (str[i] == 'D')
				? power(score[cnt], DOUBLE) : power(score[cnt], TRIPLE));
		}
		if (str[i + 1] == '*')
		{
			i++;
			score[cnt] *= 2;
			if (cnt > 0)
				score[cnt - 1] *= 2;
		}
		else if (str[i + 1] == '#')
		{
			i++;
			score[cnt] *= -1;
		}
		cnt++;
		i++;
	}
	for (int i = 0; i < ATTEMPT; i++)
	{
		sum += score[i];
	}
	return sum;
}

int main()
{
	char str[ATTEMPT * 3];
	int len, result;
	memset(str, NULL, sizeof(str));
	srand((unsigned)time(NULL));

	for (int i = 0; i < 100;i++)
	{
		len = setGame(str);
		result = calculateScore(str, len);

		for (int i = 0; i < len; i++)
		{
			if (str[i] != ':') cout << str[i];
			else cout << "10";
		}

		cout << "					" << result << endl;

	}

	system("pause");
	return 0;
}