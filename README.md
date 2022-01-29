# Exam_Rank_02 (Ecole 42) 

### Содержание
> *Если ты выбрал легкий путь, то ты обойдешь стороной printf!*
* [**Inter**](https://github.com/i-galimov/Exam_Rank_02/tree/main/inter)
* [**Union**](https://github.com/i-galimov/Exam_Rank_02/tree/main/union)
* [**Get_next_line**](https://github.com/i-galimov/Exam_Rank_02/tree/main/get_next_line)
* [**Printf**](https://github.com/i-galimov/Exam_Rank_02/tree/main/ft_printf_exam)
### [Пример кода](https://github.com/i-galimov/Exam_Rank_02/blob/main/get_next_line/get_next_line.c)
> *Все гениальное просто!*
```
#include "get_next_line.h"

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
```
********
> ***Не принято гордиться тем, что выбрал легкий путь. Но принято гордиться тем, что пришел к цели! Чтобы ты не выбрал - ты достоин уважения, пока идешь вперед!***
> 
![Легко](https://cdn.pixabay.com/photo/2017/12/10/20/56/feather-3010848_1280.jpg)
