#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUF 10

int ft_strncmp(char *s, char *c, int l)
{
	int i = 0;

	while (i < l)
	{
		if (s[i] != c[i])
			return 0;
		i++;
	}
	return 1;
}

int main(int ac, char **av)
{
	char b[BUF];
	char *s = malloc(9000); 
	int i = 0;
	int j;
	int r;
	int l = strlen(av[1]);

	while ((r = read(0, b, BUF)) > 0)
	{
		j = 0;
		while(j < r)
		{
			s[i] = b[j];
			i++;
			j++;
		}
	}
	s[i] = '\0';
	i = 0;
	while (s[i])
	{
		if (ft_strncmp(av[1], s + i, l))
		{
			j = 0;
			while (j < l)
			{
				printf("*");
				j++;
			}
			i += l;
		}
		else{
			printf("%c", s[i]);
			i++;
		}
	}
	return 0;
}