int GetGCD(int n1, int n2)
{
	int min = n1 <= n2 ? n1 : n2;

	for(int gcd = min; gcd >= 1; gcd--)
	{
		if(n1 % gcd == 0 &&  n2 % gcd == 0)
		{
			return gcd;
		}
		if(gcd == 1) 
			return gcd;
	}
}