#include <stdio.h>


int valid(char *s)
{
	int i = 0;
	int op = 0;
	int cl = 0;

	while (s[i])
	{
		if (s[i] == '(')
			op++;
		else if (s[i] == ')')
		{
			if (op > 0)
				op--;
			else
				cl++;
		}
		i++;
	}
	return (op + cl);
}

void rip(char *s, int v, int i, int p)
{
	if (v == i && !valid(s))
	{
		printf("%s\n", s);
		return;
	}
	int j = p;
	while (s[j])
	{
		if (s[j] == '(' || s[j] == ')')
		{
			int c = s[j];
			s[j] = ' ';
			rip(s, v, i + 1, j);
			s[j] = c;
		}
		j++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int v = valid(av[1]);
	rip(av[1], v, 0, 0);
	return 0;
}