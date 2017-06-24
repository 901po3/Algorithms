#include<iostream>
using namespace std;

struct Time
{
	int startTime;
	int endTime;
};


void ShellSort(Time *time, int n)
{
	int i, j;
	int step;
	Time saveTime;
	int saveIndex, saveValue;

	for(step = 1; step < n; step = 3 * step + 1);
	for(step /= 3; step > 0; step /= 3)
	{
		for(i = 0; i < step; i++)
		{
			for(j = step + i; j < n; j += step)
			{
				saveTime = time[j];
				saveValue = time[j].endTime;
				saveIndex = j;
				while(saveIndex > step - 1 && saveValue < time[saveIndex - step].endTime)
				{
					time[saveIndex] = time[saveIndex - step];
					saveIndex -= step;
				}
				time[saveIndex] = saveTime;
			}
		}
	}
}

int GetManageTime(Time *time, int n)
{
	int i, j;
	int minEndTime = 256;
	int prevJIndex = 0;
	int index;
	int count = 1;

	ShellSort(time, n);

	i = 0;
	while(i < n -1)
	{
		for(j = i + 1; j < n; j++)
		{
			if(time[i].endTime > time[j].startTime ) 
			{
				continue;
			}
			
			if(time[j].endTime < minEndTime)
			{
				minEndTime = time[j].endTime;
				index = j;
			}
		}
		minEndTime = 256;

		if(prevJIndex == 0 || prevJIndex != index) 
		{
			count++;
			i = prevJIndex = index;
		}
		else break;	
	}
	
	return count;
}

int main()
{
	int max;
	scanf("%d",&max);
	Time *time = (Time*)malloc(sizeof(Time) * max);
	
	for(int i = 0; i < max; i++)
	{
		scanf("%d	%d", &time[i].startTime, &time[i].endTime);
	}

	printf("%d\n", GetManageTime(time, max));
	free(time);
	return 0;
}