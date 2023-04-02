#pragma warning(disable:4996)
#pragma warning(disable:6031)

#include <stdio.h>


int factorial(int n)
{
	int res = 1;
	for (int i = 1; i <= n; ++i)
	{
		res *= i;
	}
	return res;
}

int main(void)
{
	int a = 0;
	scanf(" %d", &a);

	a = factorial(a);
	printf("%d", a);
}