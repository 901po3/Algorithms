#include<iostream>
#include<ctime>
#include"LRUStack.h"
using namespace std;

char* getCityName()
{
	int n = rand() % 7;
	switch (n)
	{
	case 0:
		return "Jeju";
		break;
	case 1:
		return "Pangyo";
		break;
	case 2:
		return "Seoul";
		break;
	case 3:
		return "NewYork";
		break;
	case 4:
		return "LA";
		break;
	case 5:
		return "Rome";
		break;
	case 6:
		return "Paris";
		break;
	default:
		return nullptr;
	}
}

int main()
{
	srand((unsigned)time(NULL));
	LRUStack cities;
	int citySize;

	while (true)
	{
		cout << "type citySize: ";
		cin >> citySize;
		if (citySize >= 0 && citySize <= 30)
			break;
	}

	for (int j = 0; j < 30; j++)
	{
		for (int i = 0; i < citySize; i++)
		{
			cities.LRUPush(getCityName());
		}

		for (int i = 0; i < citySize; i++)
		{
			if (cities.getSize() == 0) break;
			cout << cities.pop() << " ";
		}
		cout << "	" << cities.getTime() << endl;
		cities.removeAll();

	}
	system("pause");
	return 0;
}