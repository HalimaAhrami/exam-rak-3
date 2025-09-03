#include <stdio.h>
#include <string.h>

int cheack(char *b, char c, int i)
{
	int j = 0;
	while (j < i)
	{
		if (b[j] == c)
			return 0;
		j++;
	}
	return 1;
}
void back(char *s, char *b, int l, int i)
{
	if (i == l)
	{
		b[i] = '\0';
		printf("%s\n", b);
		return;
	}
	int j = 0;
	while (j < l)
	{
		if (cheack(b, s[j], i))
		{
			b[i] = s[j];
			back(s, b, l, i + 1);
		}
		j++;
	}

}

int main(int ac, char **av)
{
	if(ac != 2)
		return 1;
	int l = strlen(av[1]);
	char b[l + 1];
	back(av[1], b, l, 0);
	return 0;
}