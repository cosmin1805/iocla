#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *str)
{
    char *startingAddress = (char*)str;
    while (*str)
    {
        str++;
    }
 	return (int)(str - startingAddress);
}

void equality_check(const char *str)
{
    int len = my_strlen(str);
    for (int i = 0; i < len; i++)
    {
        char curChar = *(str + i);
        char nextChar = *(str + ((i + (1 << i))) % len);
        if (!(curChar ^ nextChar))
			printf("Address of %c: %p\n", curChar, str + i);
    }
}

int main(void)
{
	/* TODO: Test functions */
    printf("%d\n",my_strlen("aac"));
    equality_check("aac");
	return 0;
}

