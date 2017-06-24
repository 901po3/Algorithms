#include<iostream>
using namespace std;

//1�� ����
//fibonacci(N)�� ȣ������ ��, 0�� 1�� ���� �� �� ��µǴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// �� �׽�Ʈ ���̽����� 0�� ��µǴ� Ƚ���� 1�� ��µǴ� Ƚ���� �������� �����ؼ� ����Ѵ�.


//Make the program calculates each 0 and 1's calling times when you are calling fibonacci(N)

int fibonacci(int n, int *countZero, int *countOne, int i)
{
    if (n==0) {
		countZero[i] += 1;
        return 0;
    } else if (n==1) {
		countOne[i] += 1;
        return 1;
    } else {
        return fibonacci(n - 1, countZero, countOne, i) + fibonacci(n - 2, countZero, countOne,i);
    }
}

int main()
{
	int len; // lenth of the repeating time.
	int num; // N
	int *countZero, *countOne;
	scanf("%d", &len);
	countZero	= (int*)malloc(sizeof(int) * len);
	countOne		= (int*)malloc(sizeof(int) * len);
	
	memset(countZero, 0, sizeof(int) * len);
	memset(countOne, 0, sizeof(int) * len);

	for(int i = 0; i < len; i++)
	{
		scanf("%d", &num);
		fibonacci(num, countZero, countOne, i); 
	}

	for(int i = 0; i < len; i++)
	{
		printf("%d %d\n", countZero[i], countOne[i]);
	}

	free(countZero);
	free(countOne);

	return 0;
}