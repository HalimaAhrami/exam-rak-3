#include <stdio.h>
#include <stdlib.h>


int cheack(int *p, int i, int j)
{
	int c = 0;

	while (c < i)
	{
		if ( p[c] == j || p[c] - j == i - c || j - p[c] == i - c)
			return 0;
		c++;
	}
	return 1;
}

void print(int *p, int n)
{
	int i = 0;
	while (i < n)
	{
		printf("%d", p[i]);
		i++;
	}
	printf("\n");
}
void n_queen(int *p, int n, int i)
{
	if (i == n)
	{
		print(p, n);
		return;
	}
	int j = 0;
	while (j < n)
	{
		if (cheack(p, i, j))
		{
			p[i] = j;
			n_queen(p, n, i + 1);
		}
		j++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int n = atoi(av[1]);
	int p[n];
	n_queen(p, n, 0);
	return 0;
}