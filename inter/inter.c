#include <unistd.h>

void inter(char *str1, char* str2)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    char res[256];
    while (str1[i])
    {   
        while (str2[j])
            {
            if (str1[i] != str2[j])
                j++;
            else
                j++;
                count++;
            }
        if (count <= 1)
            res[k] = str1[i]; 
            write(1, &res[k], 1);
        k++;
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        inter(argv[1], argv[2]);
    }
    write(1, "\n", 1);
}
