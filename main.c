#include "ft_printf.h"
#include <locale.h>

int    main(void)
{
    int i;

    // setlocale(LC_ALL, "");
    ft_printf("Hello World!\n");
    // ft_printf("%s", "This is ");
    // ft_printf("%.*s\n", 9, "ft_printf and ft_dprintf");
    // ft_printf("%d\n", 123);
    // ft_printf("%05d\n", 42);
    // ft_printf("%+09d\n", 42);
    // ft_printf("%#b\n", 256);
    // ft_printf("%#o\n", 1039);
    // ft_printf("%#X\n", 16417188);
    // ft_printf("%p\n", &i);
    // ft_printf("%C %C %C\n", L'ä', L'ö', L'ü');
	ft_printf("%c", 'q');
    return (0);
}
