
//3번 문제
//한 개의 회의실이 있는데 이를 사용하고자 하는 n개의 회의들에 대하여 회의실 사용표를 만들려고 한다.
//각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고, 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 최대수의 회의를 찾아라. 
//단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가 끝나는 것과 동시에 다음 회의가 시작될 수 있다.
//회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.

//첫째 줄에 회의의 수 n(1<=n<=100,000)이 주어진다. 
//둘째 줄부터 n+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의 시작시간과 끝나는 시간이 주어진다. 
//시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.

//There is a meeting room and you are trying to make a time arrangement to use this.
//Each meeting(I) will be given the start and end time, and the meeting time should not interfere the other meetings.
//End time of the previous meeting and the start time of the next meeting can be equal.
//A meeting can have same time for start and end time, assuming the meeting ends as it is just begun.

//In the first line, numbers of meeting( n(1 <= n <= 100,000)) will be given by the programmer.
//From the second line to n+1 line, start end time of each meeting will be given, putting a space between times.
//Start and end time is the number that is samller or same with 2^31-1 or integer 0.

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
