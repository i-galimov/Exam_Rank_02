#include <unistd.h>

int main(int argc, char **argv)
{
    int i, j;
    int ascii[256];
    i = 0;
    j = 0;
    
    if (argc == 3)
    {
        char * str1 = argv[1];
        char * str2 = argv[2];
        while (i < 256)
            ascii[i++] = 0;
        i = 0;
        while (str1[i])
        {
            if (ascii[(int)str1[i]] == 1)
                i++;
            else
            {
                ascii[(int)str1[i]] = 1;
                write(1, &str1[i++], 1);
            }
        }
        while (str2[j])
        {
            if (ascii[(int)str2[j]] == 1)
                j++;
            else
            {
                ascii[(int)str2[j]] = 1;
                write(1, &str2[j++], 1);
            }
        }
    }
    write(1, "\n", 1);
    return(0);
}
