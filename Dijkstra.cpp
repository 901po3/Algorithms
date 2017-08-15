#include <iostream>
using namespace std;

#define MAX_VERTEX		100
#define INFINITE		1000

void PrintDistance(int distance[], int start, int V) {
	//printf whatever you want to
}

void DijKstra(int *a[MAX_VERTEX], int s, int V)
{
	int distance[MAX_VERTEX];
	int parent[MAX_VERTEX];//순서대로 path를 저장할 배열
	int check[MAX_VERTEX];
	int x, y, d;
	int i, checked = 0;
	
	for (x = 0; x < V; x++)
	{
		distance[x] = a[s][x];
		if (x != s) parent[x] = s; //x가 시작 정점이 아니면 x에게 값을 전달
	}

	check[s] = 1; //시작 정점 방문
	checked++; //체크한 정점의 개수 체크

	PrintDistance(distance, s, V);

	while (checked < V)
	{
		x = 0;
		while (check[x]) x++;
		for (i = x; i < V; i++)
		{
			if (check[i] == 0 && distance[i] < distance[x]) x = i;
			check[x] = 1;
			checked++;

			for (y = 0; y < V; y++)
			{
				if (x == y || a[x][y] >= INFINITE || check[y]) continue;
				d = distance[x] + a[x][y];
				if (d < distance[y])
				{
					distance[y] = d;
					parent[y] = x;
				}
			}

			PrintDistance(distance, x, V);
		}
	}

}