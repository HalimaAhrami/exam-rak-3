#include "get_next_line.h"

char *ft_strdup(char *s)
{
	char *p;
	int i = 0;

	p = malloc(strlen(s) + 1);
	if (!p)
		return NULL;
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return p;
}

char *get_next_line(int fd)
{
	static char b[BUF];
	static int p;
	static int r;
	char s[9000];
	int i = 0;

	if (fd < 0 || BUF < 0)
		return NULL;
	while (1)
	{
		if (p >= r)
		{
			r = read(fd, b, BUF);
			p = 0;
			if (r <= 0)
				break;
		}
		s[i++] = b[p++];
		if (b[p-1] == '\n')
			break;
	}
	s[i] = '\0';
	if (i == 0)
		return NULL;
	return (ft_strdup(s));
}

#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	char *l;
	l = get_next_line(fd);
	while (l)
	{
		printf("%s", l);
		free(l);
		l = get_next_line(fd);
	}
	return 0;
}