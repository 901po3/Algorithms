//Hide and Seek

// N is N( 0 <= N <= 100000) 
// K is K( 0 <= K <= 100000)
//N can walk or teleport.
//if walk, N becomes N + 1 or N - 1 per second;
//if teleport, N becomes N * 2 per second;
//find the shortest time that N and K can be same;

//ex if you type 5 and 17;
//the shortest case is 5-10-9-18-17; (4secs)

#include<iostream>
using namespace std;

//it works in most cases, but there are stil some errors;
//i think i can solve this using graph.

struct Node{
	int depth;
	Node *Walking;
	Node *Teleporting;
};

static int minDepth = 100001;

void AllPath(Node *pNode, int N, int K) 
{
	if(pNode == NULL) return;
	if(N == K)
	{
		pNode->Walking = NULL;
		pNode->Teleporting = NULL;
		cout<<endl<<"Depth : "<<pNode->depth<<" *"<<"	N : "<<N<<"	K : "<<K<<endl;
		if(minDepth > pNode->depth) minDepth = pNode->depth;
		return;
	}
	
	Node *pWalking = new Node;
	Node *pTeleporting = new Node;

	pNode->Walking = pWalking;
	pNode->Teleporting = pTeleporting;
	pWalking->depth = pNode->depth + 1;
	pTeleporting->depth = pNode->depth + 1;

	if(K > N)
	{
		AllPath(pWalking, N + 1, K);
		AllPath(pTeleporting, N * 2, K);
	}

	else if(N > K)
	{
		AllPath(pWalking, N - 1, K);
	}
	cout<<"Depth : "<<pNode->depth<<"	N : "<<N<<"	K : "<<K<<endl;
}

int  main()
{
	int N, K;
	cin>>N>>K;
	if(N < 0 || N > 100000 || K < 0 || K > 100000) return 0;
	if(N == K) cout<<0<<endl;

	Node *pInitial = new Node;
	pInitial->depth = 0;

	AllPath(pInitial, N, K);
	cout<<endl<<minDepth<<endl;

	return 0;
}