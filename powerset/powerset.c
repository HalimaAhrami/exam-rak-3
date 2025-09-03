#include <stdio.h>
#include <stdlib.h>

void	print(int *b, int j)
{
	int i = 0;

	while (i < j)
	{
		printf("%d",b[i]);
		i++;
	}
	printf("\n");
}

void powerset(int *p, int *b, int n, int l, int i, int j, int sum)
{
	if (i >= l)
	{
		if (n == sum)
			print(b,j);
		return ;
	}
	b[j] = p[i];
	powerset(p, b, n, l, i + 1, j + 1, sum + p[i]);
	powerset(p, b, n, l, i + 1, j, sum);
}

int main(int ac, char **av)
{
	if ( ac < 2)
		return 1;
	int l = ac - 2;
	int n = atoi(av[1]);
	int i = 0;
	int p[l];
	int b[l];

	while (i < l)
	{
		p[i] = atoi(av[i + 2]);
		i++;
	}
	powerset(p, b, n, l, 0, 0, 0);
	return 0;
}