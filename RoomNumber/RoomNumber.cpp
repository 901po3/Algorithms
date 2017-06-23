//Room number can be N( 0 <= N <= 10000000)
//one set have numbers from 0~9;
//number 6  and 9 can replace each other.
//for example if the room number is 6699, least number of set you need is 2.
//make program getting least set number.


#include<iostream>
using namespace std;

#define MAX	6

int main()
{
	int roomNum;
	int saveArr[MAX];
	bool checkSixNine = false;
	int setNum = 1;
	int maxSetNum = 1;
	int cnt = 0;

	cin>>roomNum;
	if(roomNum < 0 || roomNum > 1000000) return 0;

	while(roomNum != 0)
	{
		saveArr[cnt++] = roomNum % 10;
		roomNum /= 10;
	}
	
	for(int i = 0; i < cnt - 1; i++)
	{
		int iTemp = saveArr[i];
		for(int j = i + 1; j < cnt; j++)
		{
			int jTemp = saveArr[j];

			if((iTemp == 6 || iTemp == 9) && (jTemp == 6 || jTemp == 9))
			{
				if(checkSixNine)
				{
					checkSixNine = false;
					setNum++;
					continue;
				}
				checkSixNine = true;
			}
			else if(iTemp == jTemp)
			{
				setNum++;
			}
		}
		maxSetNum = (setNum > maxSetNum) ? setNum : maxSetNum;
		setNum = 1;
	}	
}