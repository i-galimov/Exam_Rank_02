# Exam_Rank_02 (Ecole 42) 

### Содержание
> *Если ты выбрал легкий путь, то ты обойдешь стороной printf*
* [**Inter**](https://github.com/i-galimov/Exam_Rank_02/tree/main/inter)
* [**Union**](https://github.com/i-galimov/Exam_Rank_02/tree/main/union)
* [**Get_next_line**](https://github.com/i-galimov/Exam_Rank_02/tree/main/get_next_line)
---
### [Пример кода](https://github.com/i-galimov/Exam_Rank_02/blob/main/get_next_line/get_next_line.c)
> *Куда ты, тропинка, меня привела?*
```
// get_next_line.h   
#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>

int get_next_line(char **line);

#endif

// get_next_line.c
#include "get_next_line.h"
//#include <stdio.h>

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
```
********
> ***Не принято гордиться тем, что выбрал легкий путь. Но принято гордиться тем, что пришел к цели***
> 
![Легко](https://cdn.pixabay.com/photo/2017/12/10/20/56/feather-3010848_1280.jpg)
