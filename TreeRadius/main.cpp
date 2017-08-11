#include <iostream>
using namespace std;

//https://www.acmicpc.net/problem/1967
//������ ù ��° ���� ����� ���� n(1��n ��10000)�̴�.
//��° �ٺ��� n ��° �ٱ��� �� ������ ���� ������ ���´�.
//������ ���� ������ �� ���� ������ �̷���� �ִ�
//.ù ��° ������ ������ �����ϴ� �� ��� �� �θ� ����� ��ȣ�� ��Ÿ����, �� ��° ������ �ڽ� ��带, �� ��° ������ ������ ����ġ�� ��Ÿ����.
//������ ���� ������ �θ� ����� ��ȣ�� ���� ���� ���� �Էµǰ�, �θ� ����� ��ȣ�� ������ �ڽ� ����� ��ȣ�� ���� ���� ���� �Էµȴ�.
//��Ʈ ����� ��ȣ�� �׻� 1�̶�� �����ϸ�, ������ ����ġ�� 100���� ũ�� ���� ���� �����̴�.

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
	totalWeight = leftWeight + rightWeight;  //���⼭ ���ظ޸� �ѹ� ����.

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