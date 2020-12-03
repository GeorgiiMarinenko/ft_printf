#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int    main(void)
{
    int i;

    // setlocale(LC_ALL, "");
    // ft_printf("Hello World!\n");
    // // ft_printf("%s", "This is ");
    // ft_printf("%.*s\n", 9, "ft_printf and ft_dprintf");

    // ft_printf("ft_printf: %10.5d\n", -216);
    // printf("   printf: %10.5d\n\n", -216);
    printf("printf: %+2d\n\n", 5);

    ft_printf("ft_printf: %8.3d\n", 8375);
    printf("   printf: %8.3d\n\n", 8375);

    ft_printf("ft_printf: %8.3d\n", -8473);
    printf("   printf: %8.3d\n\n", -8473);

    ft_printf("ft_printf %8.5d\n", 34);
    printf("   printf %8.5d\n\n", 34);

    ft_printf("ft_printf %8.5d\n", 0);
    printf("   printf %8.5d\n\n", 0);

    ft_printf("ft_printf %010.5d\n", -216);
    printf("   printf %010.5d\n\n", -216);

    ft_printf("ft_printf %07d\n", -54);
    printf("   printf %07d\n\n", -54);

    printf("d_prec_width_fit_fit_neg\n");
    ft_printf("ft_printf %10.5d\n", -216);
    printf("   printf %10.5d\n\n", -216);

    printf("d_prec_width_ff_neg_zp\n");
    ft_printf("ft_printf %010.5d\n", -216);
    printf("   printf %010.5d\n\n", -216);

    printf("d_prec_width_fn_neg_zp\n");
    ft_printf("ft_printf %03.7d\n", -2375);
    printf("   printf %03.7d\n\n", -2375);

    printf("d_prec_width_ff_pos_zp\n");
    ft_printf("ft_printf %08.5d\n", 34);
    printf("   printf %08.5d\n\n", 34);

    printf("d_prec_width_ff_zero_zp\n");
    ft_printf("ft_printf %08.5d\n", 0);
    printf("   printf %08.5d\n\n", 0);
    // ft_printf("%+09d\n", 42);
    // ft_printf("%#b\n", 256);
    // ft_printf("%#o\n", 1039);
    // ft_printf("%#X\n", 16417188);
    // ft_printf("%p\n", &i);
    // ft_printf("%C %C %C\n", L'ä', L'ö', L'ü');
	// ft_printf("%c", 'q');
    return (0);
}
