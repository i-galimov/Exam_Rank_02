#include <unistd.h>
#include <stdarg.h>

static int  ft_nbrlen(long n, int base_len)
{
	int i = 1;

	while (n >= base_len)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

static void ft_putnbr(long nbr, int base_len, char *base)
{
	if (nbr >= base_len)
		ft_putnbr(nbr / base_len, base_len, base);
	write(1, &base[nbr % base_len], 1);
}

int		ft_printf(const char *str, ...)
{
	va_list args;
	char	*s; // строка (s) из cspdiuxX
	long	nbr; // d и x из cspdiuxX
	int		neg; //флаг на минус
	int		len;//длина для проверок
	int		width; //ширина
	int		prec;//точность
	int		spaces;//пробел
	int		zeros;// ноль
	int		length; // возврашаемая длина

	va_start(args, str);
	length = 0;

	while (*str)
	{
 		if (*str == '%')
		{
            str++;
            neg = 0;
            len = 0;
            width = 0;
            prec = -1;
            spaces = 0;
            zeros = 0;
//-----------p-a-r-s-e-r-------------------------------
            while (*str >= '0' && *str <= '9') // если после % цифры
            {
                width = width * 10 + (*str - '0'); //перевожу в int
                str++;
            }

            if (*str == '.') // если .
            {
                prec = 0; // это точность
                str++; //шаг вперед
                while (*str >= '0' && *str <= '9')
                {
                    prec = prec * 10 + (*str - '0');
					str++; // шаг вперед
                }
            }
		//-----------s---------------------------------
            if (*str == 's') // если  s то это строка
            {
                s = va_arg(args, char *); // то это char *
                if (!s)
                    s = "(null)";
                while (s[len])
                    len++; // считываем строку
            }
		//-----------d---------------------------------
            if (*str == 'd') // если d то это int
            {
                nbr = va_arg(args, int); // то это int
                if (nbr < 0) // если отрицательное
                {
                    nbr = -nbr; //меняем - на +
                    neg = 1; // включаю флаг минуса
                }
                len = ft_nbrlen(nbr, 10) + neg; // длина числа + минус
            }
		//-----------x---------------------------------
            if (*str == 'x')
            {
                nbr = va_arg(args, unsigned); // то это unsigned
                len = ft_nbrlen(nbr, 16);
            }
		//-------------проверки-------------------------
			//----------точность--------------------
            if (prec >= len && *str != 's') // если точность больше длины и это не строка
                zeros = prec - len + neg;   // считаем сколько нулей добавить перед числом
            else if (prec < len && prec > -1 && *str == 's') // точность есть и точность меньше длины и это строка
                len = prec; // !!!    длина равна точности! приоритет точности   !!!
            else if (prec == 0 && (*str == 's' || nbr == 0)) // если точность  0 это строка или число 0, то  длина равна 0
                len = 0;
			//--------print " " "-" "0"-----------------------
            spaces = width - zeros - len;
            while (spaces-- > 0) //пока пробелы есть - вывожу
                length += write(1, " ", 1); // функция write возвращает количество символов которое напечатало (как printf)
            if (neg == 1)//пишем "-" после пробелов
                write(1, "-", 1); //  знак "-"" уже учтен в len поэтому не пишем lenght +=  
            while (zeros-- > 0)
                length += write(1, "0", 1);
			//--------печатать sdx -----------------
            if (*str == 's')
                write(1, s, len);
            else if (len > 0 && *str == 'd')
                ft_putnbr(nbr, 10, "0123456789");
            else if (len > 0 && *str == 'x')
                ft_putnbr(nbr, 16, "0123456789abcdef");
            length += len;
        }
        else // если нет %
            length += write(1, str, 1); // печатаю все и считаю
        str++;
    }
    va_end(args);
    return (length);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main() 
{
  int d = 0;
  double f = 1.12345;
  char c[7] = {"123456"};
  char *p;
  char *p2 = NULL;
  //p = &c[0];
  p = NULL;
  int l1;
  int l2;
  
  
  l1 = printf("d = %10.0d!! x = %12.10x!! s1 = %8s!! s2 = %5.3s", d, d, c, p);
  printf("\n %d \n", l1);
  l2 = printf("d = %10.8d!! x = %12.10x!! s1 = %8s!! s2 = %5.3s", d, d, c, p);
  printf("\n %d \n", l2);
//   printf("p = %0.0p\n", p);
//   printf("p = %p\n", p);
//   printf("p2 = %8.p\n", p2);
//   printf("p2 = %2.8p\n", p2);
//   printf("p2 = %3.0p\n", p2);
//   printf("p2 = %.4p\n", p2);
//   printf("str = %0.0s\n", p);
//   printf("str = %1.2s\n", p);
//   printf("str 4.0 = %1.3s\n", p);
//   printf("str = %-12.7s\n", p);
//   printf("asdfg %-12.19%\n");
//   printf("asdfg %12.0%\n");
//   printf("asdfg %3.10%\n");
//   printf("str = %-12.s\n", p);
  return 0;
}