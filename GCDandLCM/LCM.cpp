int GetLCM(int n1, int n2)
{
	if(n1 == n2) return n1;
	int min, max;

	if(n1 > n2)
	{
		max = n1;
		min = n2;
	}
	else
	{
		max = n2;
		min = n1; 
	}
	for(int i = 1; i <= min; i++)
	{
		int temp;
		temp = max * i; 
		if(temp % min == 0)
			return temp;
	}
}