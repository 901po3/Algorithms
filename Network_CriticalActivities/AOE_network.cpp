#include <iostream>
#include "ArrayStack.h"
using namespace std;
//To transform AOV into AOM, we need (Dummy Vertex) & (Dummy Edge)

#define int2name(i) (i + 'A')
#define name2int(c) (c - 'A')

#define MAX_VERTEX	100

struct Node
{
	int vertex;
	int weight;
	Node *pNext;
};

struct  Head
{
	int count;
	Node *pNext;
};

Head network[MAX_VERTEX];
int earliest[MAX_VERTEX];
int lastest[MAX_VERTEX];

void SetCountIndegree(Head net[], int V)
{
	int i, j;
	int count;
	Node *pTemp;
	for (i = 0; i < V; i++)
	{
		count = 0;
		for (j = 0; j < V; j++)
			for (pTemp = net[j].pNext; pTemp != NULL; pTemp = pTemp->pNext)
				if (pTemp->vertex == i) count++;
		net[i].count = count;
	}
}

void SetCountOutdegree(Head net[], int V)
{
	int i;
	int count;
	Node *pTemp;
	for (i = 0; i < V; i++)
	{
		count = 0;
		for (pTemp = net[i].pNext; pTemp != NULL; pTemp = pTemp->pNext)
			count++;
		net[i].count = count;
	}
}

void ForwardStage(Head net[], int V)
{
	int i, j, k;
	Node *pTemp;
	ArrayStack stack;

	SetCountIndegree(net, V);

	for (i = 0; i < V; i++)
	{
		earliest[i] = 0;
		if (!net[i].count)
			stack.Push(i);
	}

	for (i = 0; i < V; i++)
	{
		if (stack.IsStackEmpty())
		{
			printf("\nNetwork has a cycle. Sort terminated ! ");
			exit(1);
		}
		else
		{
			j = stack.Pop();
			for (pTemp = net[j].pNext; pTemp != pTemp; pTemp = pTemp->pNext)
			{
				k = pTemp->vertex;
				net[k].count--;
				if (!net[k].count)
					stack.Push(k);
				//각 vertex로 가는 최대 비용이 저장된다
				if (earliest[k] < earliest[j] + pTemp->weight)
					earliest[k] = earliest[j] + pTemp->weight;
			}
		}
	}
}

void BackwardStage(Head net[], int V)
{
	int i, j, k, l;
	Node *pTemp;
	ArrayStack stack;

	SetCountOutdegree(net, V);
	for (i = 0; i < V; i++)
	{
		//earliest[V - 1]은 임계값이다 (ForwardStage()함수가 실행 된 가정 하에)
		lastest[i] = earliest[V - 1];
		if (!net[i].count)
			stack.Push(i);
	}
	for (i = 0; i < V; i++)
	{
		if (stack.IsStackEmpty())
		{
			printf("\nNetwork has a cycle. Sort terminated ! ");
			exit(1);
		}
		else
		{
			j = stack.Pop();
			for (l = 0; l < V; l++)
			{
				for (pTemp = net[l].pNext; pTemp != NULL; pTemp = pTemp->pNext)
				{
					if (pTemp->vertex == j)
					{
						k = l;
						net[k].count--;
						if (!net[k].count)
							stack.Push(k);
						if (lastest[k] > lastest[j] - pTemp->weight)
							lastest[k] = lastest[j] - pTemp->weight;
					}

				}
			}
		}
	}
}

void PrintCriticalActivity(Head net[], int V)
{
	int i;
	int e, l;
	Node *pTemp;
	printf("\n\nCritical Activities");
	printf("\nEdge Action	Early	Late	Late-Early	Critical?"
		"\n.....	......... ...... ....... .............. ............ ......");
	for (i = 0; i < V; i++)
	{
		for (pTemp = net[i].pNext; pTemp != NULL; pTemp = pTemp->pNext)
		{
			e = earliest[i];	//early() 계산
			l = lastest[pTemp->vertex] - pTemp->weight; //late() 계산
			printf("\n<%c, %c> %-20s %-4d"
				"	%-%d %4d %s", int2name(i), int2name(pTemp->vertex), pTemp->vertex, e, l, l - e,
				(l - e == 0) ? "yes" : "no");
		}
	}
}
