#pragma once
 
struct node
{
	char* str;
	node *pPrev;
	node *pNext;
};


class LRUStack
{
private:
	int cnt;
	int time;
	node *pHead;
	node *pTail;
public:
	LRUStack();
	~LRUStack();

	void push(char *str);
	char* pop();

	node *findSameStr(char *str);
	void removeNode(char *str);

	void LRUPush(char *str);

	void removeAll();
	
	int getSize();
	int getTime();
};