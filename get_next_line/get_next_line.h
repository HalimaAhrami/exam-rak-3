#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#ifndef BUF
#define BUF 10
#endif

char *get_next_line(int fd);

#endif