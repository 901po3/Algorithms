#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	if (N > 1000000000) return 0;
	std::vector<int> list;

	while (N >= 1)
	{
		list.push_back(N % 10);
		N /= 10;
	}

	std::sort(list.begin(), list.end());
	
	for (int i = list.size() - 1; i >= 0; i--)
		cout << list[i];

	return 0;
}
