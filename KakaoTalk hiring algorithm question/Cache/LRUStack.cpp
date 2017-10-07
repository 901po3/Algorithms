#include "LRUStack.h"
int getStrLen(char *str)
{
	int cnt = 0;
	while (str[cnt] != 0)
	{
		cnt++;
	}
	return cnt + 1;
}

bool isStrSame(char *str1, char *str2)
{
	int len1 = getStrLen(str1);
	int len2 = getStrLen(str2);
	if (len1 != len2) return false;

	for (int i = 0; i < len1; i++)
	{
		if (str1[i] != str2[i]) return false;
	}
	return true;
}

int LRUStack::getSize()
{
	return cnt;
}
LRUStack::LRUStack()
{
	pHead = new node;
	pTail = new node;
	cnt = 0;
	time = 0;
	pHead->pNext = pTail;
	pHead->pPrev = pHead;
	pTail->pNext = pTail;
	pTail->pPrev = pHead;
	pHead->str = nullptr;
	pTail->str = nullptr;
}

LRUStack::~LRUStack()
{
	removeAll();
	delete pHead;
	delete pTail;
	cnt = 0;
}

void LRUStack::push(char* str)
{
	node *newNode = new node;
	newNode->str = str;
	
	pTail->pPrev->pNext = newNode;
	newNode->pPrev = pTail->pPrev;
	newNode->pNext = pTail;
	pTail->pPrev = newNode;
	cnt++;
}

char* LRUStack::pop()
{
	if (!cnt) return nullptr;

	node *pTemp = pTail->pPrev;
	char* tempStr = pTemp->str;

	pTemp->pPrev->pNext = pTail;
	pTail->pPrev = pTemp->pPrev;
	
	delete pTemp;
	cnt--;
	return tempStr;
}

node *LRUStack::findSameStr(char *str)
{
	if (!cnt) return nullptr;

	node *pTemp = pHead->pNext;
	while (pTemp->pNext != pTail)
	{
		if (isStrSame(pTemp->str, str))
		{
			return pTemp;
		}
		pTemp = pTemp->pNext;
	}
	return nullptr;
}

void LRUStack::removeNode(char *str)
{
	if (!cnt) return;
	node *pTemp = pHead->pNext;
	while (pTemp->pNext != pTail)
	{
		if (isStrSame(pTemp->str, str))
		{
			pTemp->pPrev->pNext = pTemp->pNext;
			pTemp->pNext->pPrev = pTemp->pPrev;
			delete pTemp;
			cnt--;
			time++;
			return;
		}
		pTemp = pTemp->pNext;
	}
	time += 5;
}

void LRUStack::LRUPush(char *str)
{
	push(str);
	removeNode(str);
}

void LRUStack::removeAll()
{
	cnt = 0;
	time = 0;
	if (!cnt) return;

	while (pHead->pNext != pTail)
	{
		node *pTemp = pHead->pNext;
		pTemp->pNext->pPrev = pTemp->pPrev;
		pTemp->pPrev->pNext = pTemp->pNext;
		delete pTemp;
	}
}

int LRUStack::getTime()
{
	return time;
}