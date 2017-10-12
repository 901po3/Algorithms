#include<iostream>
#include<ctime>
using namespace std;

#define MAX_CHARACTER	2
#define BLANK			' '
#define MAX				70
#define MIN				2

const char characterList[MAX_CHARACTER] = { 'R', 'M'};

struct block {
	char type;
	bool removable;
};

int cnt = 0;
block **map;
int width, height;

block **randomMapGenerator()
{
	block **newMap = new block*[height + 2];
	int pick;
	for (int i = 0; i < height + 2; i++)
		newMap[i] = new block[width + 2];

	for (int i = 0; i < height + 2; i++)
	{
		for (int j = 0; j < width + 2; j++)
		{
			newMap[i][j].removable = false;
			newMap[i][j].type = BLANK;
		}
	}

	for (int i = 1; i < height + 1; i++)
	{
		for (int j = 1; j < width + 1; j++)
		{
			pick = rand() % MAX_CHARACTER;
			newMap[i][j].type = characterList[pick];
		}
	}
	return newMap;
}

void displayMap()
{
	cout << endl;
	for (int i = 1; i < height + 1; i++)
	{
		for (int j = 1; j < width + 1 ; j++)
		{
			printf("%2c", map[i][j].type);
		}
		cout << endl;
	}
	cout << endl;
}

void checkBlock()
{
	char curType;
	char left, right, up, bottom, leftUp, leftBottom, rightUp, rightBottom;

	for (int i = 1; i < height + 1; i++)
	{
		for (int j = 1; j < width + 1; j++)
		{
			curType = map[i][j].type;
			if (curType == BLANK) continue;

			left = map[i][j - 1].type;	
			right = map[i][j + 1].type;
			up = map[i - 1][j].type;
			bottom = map[i + 1][j].type;
			leftUp = map[i - 1][j - 1].type;
			leftBottom = map[i + 1][j - 1].type;
			rightUp = map[i - 1][j + 1].type;
			rightBottom = map[i + 1][j + 1].type;
			
			if (curType == left && curType == up && curType == leftUp)
			{
				map[i][j].removable = true;
				map[i][j - 1].removable = true;
				map[i - 1][j].removable = true;
				map[i - 1][j - 1].removable = true;
			}
			if (curType == left && curType == bottom && curType == leftBottom)
			{
				map[i][j].removable = true;
				map[i][j - 1].removable = true;
				map[i + 1][j].removable = true;
				map[i + 1][j - 1].removable = true;
			}
			if (curType == right && curType == up && curType == rightUp)
			{
				map[i][j].removable = true;
				map[i - 1][j].removable = true;
				map[i][j + 1].removable = true;
				map[i - 1][j + 1].removable = true;
			}
			if (curType == right && curType == bottom && curType == rightBottom)
			{
				map[i][j].removable = true;
				map[i + 1][j].removable = true;
				map[i][j + 1].removable = true;
				map[i + 1][j + 1].removable = true;
			}
		}
	}
}

void removeBlock()
{
	for (int i = 1; i < height + 1; i++)
	{
		for (int j = 1; j < width + 1; j++)
		{
			if (map[i][j].type == BLANK) continue;

			if (map[i][j].removable)
			{
				map[i][j].type = BLANK;
				cnt++;
			}
			map[i][j].removable = false;
		}
	}
}

void moveBlock()
{
	int temp;
	for (int i = 1; i < width + 1; i++)
	{
		for (int j = 1; j < height + 1; j++)
		{
			temp = j;
			if (map[temp][i].type == BLANK)
			{
				while (1)
				{
					map[temp][i].type = map[temp - 1][i].type;
					if (map[temp - 1][i].type == BLANK)
						break;
					temp--;
				}
			}
		}
	}
}

bool shouldContinue()
{
	checkBlock();
	for (int i = 1; i < height + 1; i++)
	{
		for (int j = 1; j < width + 1; j++)
		{
			if (map[i][j].removable)
			{
				return true;
			}
		}
	}
	return false;
}

void playGame()
{
	displayMap();
	while(shouldContinue())
	{
		removeBlock();
		displayMap();
		moveBlock();
		displayMap();
	} 
}

int main()
{
	cout << "type width and height: ";
	cin >> width >> height;

	if (width < MIN || height < MIN || width > MAX || height > MAX)
	{
		cout << "out of range" << endl;
		system("pause");
		return 0;
	}
	srand((unsigned)time(NULL));
	map = randomMapGenerator();

	playGame();

	cout << endl << "removed block(s): " << cnt << endl;

	for (int i = 0; i < height + 2; i++)
		delete[]map[i];
	delete[]map;

	system("pause");
	return 0;
}