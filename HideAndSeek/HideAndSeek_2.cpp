#include<iostream>
using namespace std;

//error that 'HideAndSeek_1.cpp' had is fixed, but there is memory problem when gap between N and K becomes extremely large.

#define ARR_MAX			100000
#define QUEUE_MAX		100000

struct Node
{
	int depth;
	int N;
	Node *pCase1;
	Node *pCase2;
	Node *pCase3;
};

typedef Node *myType;

class ArrayQueue					//I am goint to use Queue to do level-order traverse
{
private:
	myType Queue[QUEUE_MAX];
	int Front;
	int Rear;
public:
	ArrayQueue(){ Front = Rear = 0;}
	~ArrayQueue() {}

	void EnQueue(myType data);
	myType DeQueue();
	bool IsQueueEmpty();
};

void ArrayQueue::EnQueue(myType data)
{
	if(Rear+1 % QUEUE_MAX == Front)
		return;

	Queue[Rear] = data;
	Rear = Rear++ % QUEUE_MAX;
}

myType ArrayQueue::DeQueue()
{
	if(Rear == Front)
		return NULL;

	Front++;
	return Queue[Front - 1];
}

bool ArrayQueue::IsQueueEmpty()
{
	if(Rear == Front) return true;
	else return false;
}

ArrayQueue queue;
int arr[ARR_MAX];
int cnt = 1;

int GetShortestTime(int K)
{
	while(!queue.IsQueueEmpty())
	{
		Node *pTemp = queue.DeQueue();
		if(pTemp == NULL) continue;
		//cout<<pTemp->N<<endl;
		pTemp->pCase1 = pTemp->pCase2 = pTemp->pCase3 = NULL;

		if(pTemp->N == K)
		{
			return pTemp->depth;
		}
		bool checkSameNum1 = false;
		bool checkSameNum2 = false;
		bool checkSameNum3 = false;
		int case1 = pTemp->N + 1;
		int case2 = pTemp->N - 1;
		int case3 = pTemp->N * 2;

		if(case2 < 0) checkSameNum2 = true;
		
		for(int i = 0; i < cnt; i++)
		{
			if(case1 == arr[i]) 
			{
				checkSameNum1 = true;
			}
			if(case2 == arr[i]) 
			{
				checkSameNum2 = true;
			}
			if(case3 == arr[i]) 
			{
				checkSameNum3 = true;
			}
		}

		Node *newCase1 = NULL;
		Node *newCase2 = NULL;
		Node *newCase3 = NULL;

		if(!checkSameNum1)
		{
			newCase1 = new Node;
			newCase1->N = arr[cnt++] = case1;
			newCase1->depth = pTemp->depth + 1;
			pTemp->pCase1 = newCase1;
			queue.EnQueue(newCase1);

		}
		if(!checkSameNum2)
		{
			newCase2 = new Node;
			newCase2->N = arr[cnt++] = case2;
			newCase2->depth = pTemp->depth + 1;
			pTemp->pCase2 = newCase2;
			queue.EnQueue(newCase2);
		}
		if(!checkSameNum3)
		{
			newCase3 = new Node;
			newCase3->N = arr[cnt++] = case3;
			newCase3->depth = pTemp->depth + 1;
			pTemp->pCase3 = newCase3;
			queue.EnQueue(newCase3);
		}
	}
}

int main()
{
	int N, K;
	cin>>N>>K;
	if(N < 0 || N > 100000 || K < 0 || K > 100000) return 0;

	Node *pHead = new Node;
	arr[0] = pHead->N = N;
	pHead->depth = 0;
	queue.EnQueue(pHead);

	int t = GetShortestTime( K);
	cout<<t<<endl;
	return 0;
}
