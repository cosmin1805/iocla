#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_SIZE 512

char *new_string(const char *cont_str)
{
	char *res;

	res = calloc(STR_SIZE, sizeof(char));
	strcpy(res, cont_str);

	return res;
}

int my_strlen(const char *str)
{
    char *startingAddress = (char*)str;
    while (*str)
    {
        str++;
    }
 	return (int)(str - startingAddress);
}

void mirror(char *s)
{
	int len = my_strlen(s);
    for (int i = 0;i < (len >> 1);i++)
    {
        int offIndex = len - i - 1;
        char aux = *(s + i);
        *(s + i) = *(s + offIndex);
        *(s + offIndex) = aux;
    }
}

int main(void)
{
	/* TODO: Test function */
    char *str = new_string("AnaAreMere");
    mirror(str);
    printf("%s\n",str);
    free(str);
	return 0;
}

