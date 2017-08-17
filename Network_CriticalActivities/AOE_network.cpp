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
	Node *ptr;
	ArrayStack stack;
	SetCountIndegree(net, V);

	for (i = 0; i < V; i++)
		earliest[i] = 0;
	for (i = 0; i < V; i++)
		if (!net[i].count)
			stack.Push(i);
	for (i = 0; i < V; i++)
	{
		if (stack.IsStackEmpty())
		{
			printf("\nNetwork has a cycle. Sort Terminated ! ");
			exit(1);
		}
		else
		{
			j = stack.Pop();
			for (ptr = net[j].pNext; ptr != NULL; ptr = ptr->pNext)
			{
				k = ptr->vertex;
				net[k].count--;
				if (!net[k].count)
					stack.Push(k);
				if (earliest[k] < earliest[j] + ptr->weight)
					earliest[j] = earliest[j] + ptr->weight;
				//earliest[j] + <j, k> 가중치의 최소값이 earliest[j]가 된다
			}
		}
	}
}