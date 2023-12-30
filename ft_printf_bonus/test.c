#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"

void printStrings(int count, ...)
{
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++)
    {
        char* str = va_arg(args, char*);
        printf("%s\n", str);
    }

    va_end(args);
}

int main()
{
	printf("printf : %bbs %%%s %s\n","Hello", "World");
	ft_printf("aaa %bbs %%%s %s","Hello", "World", "!");
    //printStrings(3, "Hello", "World", "!");
    return 0;
}
