#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1967
//파일의 첫 번째 줄은 노드의 개수 n(1≤n ≤10000)이다.
//둘째 줄부터 n 번째 줄까지 각 간선에 대한 정보가 들어온다.
//간선에 대한 정보는 세 개의 정수로 이루어져 있다
//.첫 번째 정수는 간선이 연결하는 두 노드 중 부모 노드의 번호를 나타내고, 두 번째 정수는 자식 노드를, 세 번째 정수는 간선의 가중치를 나타낸다.
//간선에 대한 정보는 부모 노드의 번호가 작은 것이 먼저 입력되고, 부모 노드의 번호가 같으면 자식 노드의 번호가 작은 것이 먼저 입력된다.
//루트 노드의 번호는 항상 1이라고 가정하며, 간선의 가중치는 100보다 크지 않은 양의 정수이다.

#define MAX_VERTEX			10000
struct TreeGraphNode;

struct Edge
{
	int weight;
	TreeGraphNode *pToParent;
	TreeGraphNode *pToChild;
};

struct TreeGraphNode
{
	int vertex;
	int curWeight;
	Edge *pToParent;
	Edge *pToLeftChild;
	Edge *pToRightChild;
};

TreeGraphNode *a[MAX_VERTEX];

void MakeGraph(int v)
{
	int parentNode, childNode, weight;

	for (int i = 0; i < MAX_VERTEX; i++) a[i] = NULL;
	for (int i = 1; i < v + 1; i++)
	{
		a[i] = new TreeGraphNode;
		a[i]->pToParent = NULL;
		a[i]->pToLeftChild = NULL;
		a[i]->pToRightChild = NULL;
		a[i]->vertex = i;
		a[i]->curWeight = 0;
	}

	for (int i = 0; i < v - 1; i++)
	{
		Edge *pE = new Edge;
		cin >> parentNode;
		if (a[parentNode]->pToLeftChild == NULL)
			a[parentNode]->pToLeftChild = pE;
		else
			a[parentNode]->pToRightChild = pE;
		pE->pToParent = a[parentNode];

		cin >> childNode;
		pE->pToChild = a[childNode];
		a[childNode]->pToParent = pE;

		cin >> weight;
		pE->weight = weight;
	}
}

int GetMaxWeight(TreeGraphNode *pNode, int weight)
{

	weight += pNode->pToParent->weight;
	pNode->curWeight = weight;
	if (pNode->pToLeftChild != NULL || pNode->pToRightChild != NULL)
	{
		int leftW = 0;
		int rightW = 0;
		if (pNode->pToLeftChild != NULL)
		{
			leftW = GetMaxWeight(pNode->pToLeftChild->pToChild, pNode->curWeight);
		}
		if (pNode->pToRightChild != NULL)
		{
			rightW = GetMaxWeight(pNode->pToRightChild->pToChild, pNode->curWeight);
		}
		weight = leftW >= rightW ? leftW : rightW;
	}
	return weight;

}

int GetTreeRadius(TreeGraphNode *pRoot)
{
	int leftWeight = 0;
	int rightWeight = 0;
	int totalWeight;
	TreeGraphNode *pLeft = NULL;
	TreeGraphNode *pRight = NULL;
	if(pRoot->pToLeftChild != NULL)
	 pLeft = pRoot->pToLeftChild->pToChild;
	if(pRoot->pToRightChild != NULL)
		 pRight = pRoot->pToRightChild->pToChild;

	if (pLeft != NULL)
	{
		leftWeight = GetMaxWeight(pLeft, 0);
	}
	if (pRight != NULL)
	{
		rightWeight = GetMaxWeight(pRight, 0);
	}
	totalWeight = leftWeight + rightWeight;  //여기서 스텍메모리 한번 정리.

	if (pRoot->pToLeftChild != NULL || pRoot->pToRightChild != NULL)
	{
		int leftW = 0;
		int rightW = 0;
		int biggerNum;
		if (pRoot->pToLeftChild != NULL)
			leftW = GetTreeRadius(pRoot->pToLeftChild->pToChild);
		if (pRoot->pToRightChild != NULL)
			rightW = GetTreeRadius(pRoot->pToRightChild->pToChild);
		biggerNum = leftW >= rightW ? leftW : rightW;
		totalWeight = totalWeight >= biggerNum ? totalWeight : biggerNum;
	}
	return totalWeight;
}

TreeGraphNode *SearchRootNode(int v)
{
	for (int i = 1; i < v + 1; i++)
	{
		if (a[i]->vertex == 1)
			return a[i];
	}
	return NULL;
}

int main()
{
	int nodeNum;
	cin >> nodeNum;
	if (nodeNum < 1 || nodeNum > 10000) return 0;
	MakeGraph(nodeNum);

	cout << GetTreeRadius(SearchRootNode(nodeNum)) << endl;

	return 0;
}