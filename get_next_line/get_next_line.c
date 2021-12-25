#include "get_next_line.h"
// #include <stdio.h>

int get_next_line(char **line)
{
    int i = 0, j;
    char *buf;
    buf = (char *)malloc(10000);
    while ((j = read(0, &buf[i], 1)) == 1 && buf[i] != '\n' && buf[i] != '\0')
        i++;
    buf[i] = '\0';
    *line = buf;
    return (j);
}

/* int main(void)
{
    int r = 0;
    char *line;
    while ((r = get_next_line(&line)) > 0)
    printf("%s\n", line);
    free(line); 
} */
